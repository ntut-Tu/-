import Jetson.GPIO as GPIO
import time

SPICLK = 11
SPIMISO = 9
SPIMOSI = 10
SPICS = 8
LED1 = 17
LED2 = 18
output_pin = 7
photo_ch = 0

def init():
    GPIO.setmode(GPIO.BOARD)
    GPIO.setup(output_pin, GPIO.OUT, initial=GPIO.HIGH)
    GPIO.setwarnings(False)
    GPIO.cleanup()
    GPIO.setmode(GPIO.BCM)
    GPIO.setup(SPIMOSI, GPIO.OUT)
    GPIO.setup(SPIMISO, GPIO.IN)
    GPIO.setup(SPICLK, GPIO.OUT)
    GPIO.setup(SPICS, GPIO.OUT)
    GPIO.setup(LED1, GPIO.OUT)
    GPIO.setup(LED2, GPIO.OUT)

def readadc(adcnum, clockpin, mosipin, misopin, cspin):
    if ((adcnum > 7) or (adcnum < 0)):
        return  -1
    GPIO.output(cspin, True)

    GPIO.output(clockpin, False)
    GPIO.output(cspin, False)

    commandout = adcnum
    commandout |= 0x18
    commandout <<= 3
    for i in range(5):
        if commandout & 0x80:
            GPIO.output(mosipin, True)
        else:
            GPIO.output(mosipin, False)
        commandout <<= 1
        GPIO.output(clockpin, True)
        GPIO.output(clockpin, False)

    adcout = 0
    for i in range(12):
        GPIO.output(clockpin, True)
        GPIO.output(clockpin, False)
        adcout <<= 1
        if GPIO.input(misopin):
            adcout |= 0x1
    GPIO.output(cspin, True)
    adcout >>= 1
    return adcout

#main
def main():
    init()
    while True:
        adc_value=readadc(photo_ch,SPICLK,SPIMOSI,SPIMISO,SPICS)
        print(adc_value)
        #GPIO.output(LED,True)
        if(adc_value>30):
            print("LED1 ON")
            GPIO.output(LED1,True)
        else:
            print("LED1 OFF")
            GPIO.output(LED1,GPIO.LOW)
        if(adc_value>70):
            print("LED2 ON")
            GPIO.output(LED2,True)
        else:
            print("LED2 OFF")
            GPIO.output(LED2,GPIO.LOW)  
        time.sleep(0.5)

if __name__ == '__main__':
    main()
#gst-launch-1.0 nvcamerasrc !
#'video/x-raw(memory:NVMM),width=640, height=480, framerate=30/1, format=NV12'
#! nvvidconv flip-method=2 ! nvegltransform ! nveglglessink -e
#gst-launch-1.0 nvarguscamerasrc ! nvvidconv ! xvimagesink