#include "DigitalSensor.h"

#include <Arduino.h>

DigitalSensor::DigitalSensor(uint8_t pin) :
    _pin(pin) {
}

void DigitalSensor::begin() {
  pinMode(_pin, INPUT);
  readValues();
}

void DigitalSensor::loop() {
  readValues();
}

bool DigitalSensor::readValues() {
  _previousValue = _value;
  _value = digitalRead(_pin);
  return true;
}
