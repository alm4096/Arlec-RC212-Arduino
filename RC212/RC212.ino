#include <RCSwitch.h>

char aOn[35]="1101010100011000000011111100110100";
char aOf[35]="1101010100011000000011101100110000";
char bOn[35]="1101010100011000000011011100111000";
char bOf[35]="1101010100011000000011001100111100";
char cOn[35]="1101010100011000000010111100100100";
char cOf[35]="1101010100011000000010101100100000";
char dOn[35]="1101010100011000000001111100010100";
char dOf[35]="1101010100011000000001101100010000";
char allOn[35]="1101010100011000000001001100011100";
char allOf[35]="1101010100011000000010001100101100";

//Load our modified RCSwitch Library
RCSwitch mySwitch = RCSwitch();

void setup() {
  // Transmitter is connected to Arduino Pin #11
  mySwitch.enableTransmit(11);

  // Need to set pulse width to 300
  mySwitch.setPulseLength(300);
}

void loop() {
  // Example turning on and off powerpoint C
  mySwitch.send(&cOn[0] , 34);
  delay(1000);
  mySwitch.send(&cOf[0] , 34);
  delay(1000);

}
