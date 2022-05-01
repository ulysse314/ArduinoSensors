#include "AnalogSensor.h"

#include <Arduino.h>

AnalogSensor::AnalogSensor(uint8_t pin) :
    _pin(pin) {
}

void AnalogSensor::begin() {
  pinMode(_pin, INPUT);
  readValues();
}

bool AnalogSensor::readValues() {
  _value = analogRead(_pin);
  return true;
}
