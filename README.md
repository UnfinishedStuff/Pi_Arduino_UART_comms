# Pi Arduino UART comms
Send data from a Raspberry Pi to an Arduino via UART!

This repo is mostly to store scripts which I've used to send text from a Raspberry Pi to an Arduino-compatible over the UART bus.  It's just here for future reference for the next time I decide I need to do this.

All code was written and tested on a Pi Zero and an Adafruit Feather 328p with an SSD1306 OLED Featherwing.  Everything should be adaptable to other Pi boards and other Arduino-compatible boards.

# Raspberry Pi setup

The Raspberry Pi needs some setup because of the way that the UART systems work.  By default the main UART system is used for other things, so these have to be disabled first.

Using the guide [found here](https://www.raspberrypi.org/documentation/configuration/uart.md):

1) Add `enable_uart=1` to the bottom of `/boot/config.txt`.
2) On a separate line, add `dtoverlay=pi3-disable-bt`.  **Note:** this will disable Bluetooth on the device.
3) Run `sudo raspi-config`, go to `Interfacing options`, select `Serial` and when it asks if you want the login shell to be accessible over serial select `No`.  If it asks if you want the serial hardware to be enabled select `Yes`.
4) Run `sudo systemctl disable hciuart` to make doubly sure that the system doesn't try to run the login shell over the UART bus.
5) Reboot the Pi

# Wiring

The TX pin of the Pi must connect to the RX pin of the Arduino-compatible, and a ground pin on each board should be connected too.  These scripts only send data one way so there's no need to connect the Arduino-compatible's TX pin to the Pi's RX pin.

# Code

There are two files for this.  `Pi_UART.py` sends a string over the serial bus, and needs to be run on the Pi.  `FeatherOLEDUART.ino` is the code I've been running on the Feather328p with OLED Featherwing.  It checks for activity on the serial bus, appends data from the bus to a string and then shows the string on the OLED.

Program the Arduino-compatible and wire everything up.  Power the boards.  Run `Pi_UART.py` on the Pi, and the message should appear on the OLED.

# Known issues

For some reason the Feather 328p is skipping the first character at the start of the message.  Not sure why yet.   
