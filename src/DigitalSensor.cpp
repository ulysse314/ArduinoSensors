#include "DigitalSensor.h"

#include <Arduino.h>

DigitalSensor::DigitalSensor(uint8_t pin) :
    _pin(pin) {
}

void DigitalSensor::begin() {
  pinMode(_pin, INPUT);
}

bool DigitalSensor::readValues() {
  _value = digitalRead(_pin);
  return true;
}
