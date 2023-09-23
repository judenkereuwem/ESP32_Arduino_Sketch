
#include <MD_Parola.h>
#include <MD_MAX72xx.h>

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4 // 4 blocks
#define CS_PIN 21

// create an instance of the MD_Parola class
MD_Parola ledMatrix = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

void setup() {
  ledMatrix.begin();         // initialize the object
  ledMatrix.setIntensity(0); // set the brightness of the LED matrix display (from 0 to 15)
  ledMatrix.displayClear();  // clear led matrix display

  ledMatrix.displayScroll("ESP32", PA_CENTER, PA_SCROLL_LEFT, 100);
}

void loop() {
  if (ledMatrix.displayAnimate()) {
    ledMatrix.displayReset();
  }
}
