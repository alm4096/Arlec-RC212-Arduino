//This is timed perfectly for the arduino nano ATmega328P old bootloader. Different micros will need different delays. If you use interrupts then this will affect send of the message.
long delay2 = 40;

void Digsend(int val);
void MessagePause();
void SendMess(long long message);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(1000000);
  pinMode(11, OUTPUT);
  pinMode(13, OUTPUT);
}

//1101010100011000000011111100111100 A On?
//1101010100011000000011101100111000 A Off?

//1101010100011000000011001100111100 B On?
//1101010100011000000011011100111000 B Off?

//1101010100011000000010111100100100 C On
//1101010100011000000010101100100000 C Off

//1101010100011000000001111100010100 D On  14300487444
//1101010100011000000001101100010000 D Off 14300486416


void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  SendMess(14300487444);

  delay(2000);
  SendMess(14300486416);

}

//Pause
void MessagePause() {
  digitalWrite(11, false);
  for (long i = 0; i < 200 * delay2; i++) {
    __asm__("nop\n\t");
  }

}

void SendMess(long long message) {
  digitalWrite(13, true);

  //-------------
  //Parse Message
  //-------------
  bool MessageBuffer[34];
  for (long long i = 33; i >= 0; i--) {
    if ((message & ((long long)1 << i)) == 0) {
      MessageBuffer[i] = false;
      //  Serial.print("0");
    }
    else {
      MessageBuffer[i] = true;
      //    Serial.print("1");
    }
  }
  //        Serial.println("");
  //-------------

  //-------------
  //Send Message
  //-------------
  for (int j = 0; j <= 5; j++) {
    MessagePause();

    for (long long i = 33; i >= 0; i--) {
      if (MessageBuffer[i]) {
        Digsend(1);
      }
      else {
        Digsend(0);
      }
    }

    MessagePause();
  }
  //-------------

  digitalWrite(13, false);
}

//Write a 1 or a 0. Is timed exactly for a arduino nano ATmega328p old bootloader
void Digsend(int val) {
  if (val == 1) {
    digitalWrite(11, true);
    for (long i = 0; i < 50 * delay2; i++) {
      __asm__("nop\n\t");
    }
    digitalWrite(11, false);
    for (long i = 0; i < 10 * delay2; i++) {
      __asm__("nop\n\t");
    }

  }
  else {
    digitalWrite(11, true);
    for (long i = 0; i < 19 * delay2; i++) {
      __asm__("nop\n\t");
    }
    digitalWrite(11, false);
    for (long i = 0; i < 25 * delay2; i++) {
      __asm__("nop\n\t");
    }
  }
}
