#include "PowerSensor.h"

#include <stdio.h>
#include <Arduino.h>

PowerSensor::PowerSensor(uint8_t amperePin, uint8_t voltPin, double kAmpereCoef, double kVoltCoef) :
    _amperePin(amperePin),
    _voltPin(voltPin),
    _kAmpereCoef(kAmpereCoef),
    _kVoltCoef(kVoltCoef) {
  char *address = (char *)malloc(16);
  sprintf(address, "A:%ud,V:%ud", _amperePin, _voltPin);
  _address = address;
}

PowerSensor::~PowerSensor() {
  free((void *)_address);
}

void PowerSensor::begin() {
  pinMode(_amperePin, INPUT);
  pinMode(_voltPin, INPUT);
}

bool PowerSensor::readValues() {
  _rawAmpere = analogRead(_amperePin);
  _rawVolt = analogRead(_voltPin);
  return true;
}
