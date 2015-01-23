#!/usr/bin/python

import smbus
import time

bus = smbus.SMBus(1)    # 0 = /dev/i2c-0 (port I2C0), 1 = /dev/i2c-1 (port I2C1)

DEVICE_ADDRESS = 0x20      #7 bit address (will be left shifted to add the read write bit)
DEVICE_REG_MODE1 = 0x00

#Write a single register
bus.write_byte(DEVICE_ADDRESS,6)

def readValue(address,register):
	bus.write_quick(address)
	time.sleep(.02)
	long value = bus.read_byte(address,2)
	return value	

	
while True:
	print readValue(DEVICE_ADDRESS,0)
	print ", "
	print readValue(DEVICE_ADDRESS,5)
	print ", slut"
