#ifndef ARDUINO_OUTPUT_PIN_H_
#define ARDUINO_OUTPUT_PIN_H_

#include "output_pin.h"

class ArduinoOutputPin : OutputPin {
private:
  const int pin_;
public:
  ArduinoOutputPin(const int pin) : pin_(pin) {
    pinMode(pin, OUTPUT);
  }
  void Write(int level) {
    digitalWrite(this->pin_, level);
  }
};

#endif

