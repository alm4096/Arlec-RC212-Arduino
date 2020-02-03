# Arlec-RC212-Arduino
Bare bones code to control the Arlec RC212 Wireless Power Point from an Arduino using the MX-RM-5V a cheap chinese 433MHz transmitter or similar. Take note that pin 11 is used to send the data.

Code is written for and Arduino Nano ATMega328P. Using any other microcontroller will need adjustment to the delay to ensure the message is sent correctly. Ideally the code should be re-written to use timers.

Why can't you use RC-Switch? Well the pulse width is variable. A zero is nearly half the length of a one.

A note, these things do not remember their code like the old RC10's from Arlec. Each time the power is cycled the ON command must be sent so that the RC212 learns the code.

![RC212 image](RC212.png?raw=true "RC212 Image")
