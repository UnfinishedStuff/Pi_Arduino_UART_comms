#!/usr/bin/python3

import wiringpi, time
wiringpi.wiringPiSetup()

#Set up the UART bus
serial = wiringpi.serialOpen('/dev/ttyAMA0', 9600)

#Send a message on the bus.  For some reason the first char is always skipped by the Arduino (not sure why)
wiringpi.serialPuts(serial, ' Hello!')
