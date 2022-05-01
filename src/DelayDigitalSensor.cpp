#include "DelayDigitalSensor.h"

#include <Arduino.h>

DelayDigitalSensor::DelayDigitalSensor(uint8_t pin, unsigned long long delay) : DigitalSensor(pin),
    _delay(delay * 1000) {
}

bool DelayDigitalSensor::readValues() {
  _previousValue = _value;
  bool new_value = digitalRead(_pin);
  if (new_value) {
    _last_set =	millis();
    _value = new_value;
  } else if ((unsigned long long)(millis() - _last_set) > _delay) {
    _value = new_value;
  }
  return true;
}
