//This is timed perfectly for the arduino nano ATmega328P old bootloader. Different micros will need different delays. If you use interrupts then this will affect send of the message.
long delay2 = 20;

void Digsend(int val);
void MessagePause();
void SendMess(long long message);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(1000000);
  pinMode(11, OUTPUT);
  pinMode(13, OUTPUT);
}

//1101010100011000000011111100110100 A On   ‭  14300495668‬
//1101010100011000000011101100110000 A Off    ‭14300494640‬
//1101010100011000000011011100111000 B On     ‭14300493624‬
//1101010100011000000011001100111100 B Off    ‭14300492604‬
//1101010100011000000010111100100100 C On     ‭14300491556‬
//1101010100011000000010101100100000 C Off   ‭ 14300490528‬
//1101010100011000000001111100010100 D On     ‭14300487444‬
//1101010100011000000001101100010000 D Off    ‭14300486416‬
//1101010100011000000001001100011100 All On   ‭14300484380‬
//1101010100011000000010001100101100 All Off  ‭14300488492‬

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  SendMess(14300487444);

  delay(2000);
  SendMess(14300486416);

}

//Write a 1 or a 0. Is timed exactly for a arduino nano ATmega328p old bootloader
void Digsend(int val) {
  if (val == 1) {
    digitalWrite(11, true);
    delayMicroseconds(45 * delay2);
    digitalWrite(11, false);
    delayMicroseconds(15 * delay2);
  }
  else {
    digitalWrite(11, true);
    delayMicroseconds(20 * delay2);
    digitalWrite(11, false);
    delayMicroseconds(35 * delay2);
  }
}

//Pause
void MessagePause() {
  digitalWrite(11, false);
  delayMicroseconds(500 * delay2);
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
