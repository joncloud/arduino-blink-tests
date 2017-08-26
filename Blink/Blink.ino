#include "arduino_output_pin.h"
#include "delaying_app_state.h"
#include "writing_app_state.h"
#include "app.h"

App* app;
void setup() {
  ArduinoOutputPin* led = new ArduinoOutputPin(LED_BUILTIN);
  WritingAppState* on = new WritingAppState(HIGH, (OutputPin*)led);
  DelayingAppState* delayOn = new DelayingAppState(1000, &delay, (AppState*)on);
    
  WritingAppState* off = new WritingAppState(LOW, (OutputPin*)led);
  DelayingAppState* delayOff = new DelayingAppState(1000, &delay, (AppState*)off);

  on->set_next((AppState*)delayOff);
  off->set_next((AppState*)delayOn);

  app = new App((AppState*)delayOff);
}

void loop() {
  app->Update();
}
