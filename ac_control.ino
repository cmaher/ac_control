#include "IRremote.h"

/*
 * from Arduino-IRremote/examples/IRrecvDump (https://github.com/shirriff/Arduino-IRremote)
 * Decoded NEC: 10AF8877 (32 bits)
 * Raw (68): -28982 8850 -4450 650 -450 650 -450 650 -450 650 -1600 650 -450 650 -500 600 -500
 *           600 -500 650 -1600 600 -500 650 -1600 600 -500 600 -1650 600 -1600 650 -1600 650
 *           -1600 650 -1600 600 -500 650 -450 650 -450 650 -1600 650 -450 650 -450 650 -500 600
 *           -500 600 -1600 650 -1600 650 -1600 650 -450 650 -1600 650 -1600 600 -1600 650
*/

IRsend irSend = IRsend(D0);

unsigned long timeout = 5 * 60 * 1000; // 5 minutes

int togglePower(String command) {
  irSend.sendNEC(0x10AF8877, 32);
  return 0;
}

void setup() {
  Spark.function("power", togglePower);
}

void loop() {
  if (millis() > timeout) {
    System.reset();
  }
}
