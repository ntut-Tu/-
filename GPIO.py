import Jetson.GPIO as GPIO
import time
import sys

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
def main(mode):
    if mode == 1:
        init()
        count=0
        sumOut=0
        for i in range(20):
            adc_value=readadc(photo_ch,SPICLK,SPIMOSI,SPIMISO,SPICS)
            if(adc_value!=0 or adc_value<1000):
                count+=1
                sumOut+=adc_value
        if(count>0):
            adc_value=sumOut/count
        else:
            adc_value=sumOut
        print(adc_value)
        if(adc_value>30):
            GPIO.output(LED1,True)
        else:
            GPIO.output(LED1,GPIO.LOW)
        if(adc_value>70):
            GPIO.output(LED2,True)
        else:
            GPIO.output(LED2,GPIO.LOW)  
    else:
        init()
        if(sys.argv[1]=='0'):
            GPIO.output(LED1,GPIO.LOW)
            GPIO.output(LED2,GPIO.LOW)  
            print('0')
        elif(sys.argv[1]=='A'):
            GPIO.output(LED1,True)
            GPIO.output(LED2,GPIO.LOW)  
            print('A')
        elif(sys.argv[1]=='B'):
            GPIO.output(LED2,True)
            GPIO.output(LED1,GPIO.LOW)
            print('B')
        elif(sys.argv[1]=='AB'):
            GPIO.output(LED1,True)
            GPIO.output(LED2,True)
            print('AB')
        else:
            print("pass")
    sys.stdout.flush()
    
if __name__ == '__main__':
    if(len(sys.argv)>1):
        main(2)
    else:
        main(1)