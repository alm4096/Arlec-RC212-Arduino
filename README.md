# Arlec-RC212-Arduino
Bare bones code to control the Arlec RC212 Wireless Power Point from an Arduino using the MX-RM-5V a cheap chinese 433MHz transmitter or similar. Take note that pin 11 is used to send the data.

I have had to modify the RC-Switch library to accept a 34bit code. If you use the standard RC-Switch library you will have issues compiling.

A note, these things do not remember their code like the old RC10's from Arlec. Each time the power is cycled the ON command must be sent so that the RC212 learns the code.

![RC212 image](RC212.png?raw=true "RC212 Image")
