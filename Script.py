#!/usr/bin/python

import smbus
import time

bus = smbus.SMBus(1)    # 0 = /dev/i2c-0 (port I2C0), 1 = /dev/i2c-1 (port I2C1)

DEVICE_ADDRESS = 0x20      #7 bit address (will be left shifted to add the read write bit)
DEVICE_REG_MODE1 = 0x00

#Write a single register
bus.write_byte(DEVICE_ADDRESS,6)
time.sleep(1)


def readValue(address,register):
	bus.write_byte(address,register)
	time.sleep(.1)
	try:
		value = bus.read_byte_data(address,2)
		return value	
	except IOError:
		return "Fel i sandningen"
	
while True:
	print "Fukt varde:"
	print readValue(DEVICE_ADDRESS,0)
	print "Temperatur varde:"
	print readValue(DEVICE_ADDRESS,5)
	bus.write_byte(DEVICE_ADDRESS,3)
	print "Ljus varde"
	print readValue(DEVICE_ADDRESS,4)
	print "slut"
	print ""
	time.sleep(1)
