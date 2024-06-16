# -*- coding: utf-8 -*-

import time
import random
import sys

def read_light_sensor():
    return random.randint(0, 1023)

def read_humidity_sensor():
    return random.randint(0, 100)

def main():
    while True:
        light = read_light_sensor()
        humidity = read_humidity_sensor()
        file='output.txt' 
        with open(file, 'w') as filetowrite:
            filetowrite.write(f"R\nLight: {light} Humidity: {humidity}")
        time.sleep(5) 

if __name__ == '__main__':
    main()
