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

unsigned long listen_floor = 1000 * 10; // 10 seconds

// Occasionally, the Blue Flash of Death will prevent any user code from executing
// Intercept any listening events after system start, and reset to break the infinite loop
void maybe_break_listen(system_event_t event, uint32_t param, void* pointer) {
  if (event == wifi_listen_begin) {
    if (millis() > listen_floor) {
      System.reset();
    }
  }
}

int togglePower(String command) {
  irSend.sendNEC(0x10AF8877, 32);
  return 0;
}

void setup() {
  Particle.function("power", togglePower);
  System.on(wifi_listen, maybe_break_listen);
}

void loop() {
}
