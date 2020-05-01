#include "RainSensor.h"

#include <Arduino.h>

RainSensor::RainSensor(uint8_t rainSensorPin, uint8_t rainOutputPin, uint8_t temperatureReadPin, uint8_t temperatureOutputPin, uint8_t heaterPin) :
    _rainSensorPin(rainSensorPin),
    _rainOutputPin(rainOutputPin),
    _temperatureReadPin(temperatureReadPin),
    _temperatureOutputPin(temperatureOutputPin),
    _heaterPin(heaterPin),
    _heat(false),
    _temperature(0) {
}

void RainSensor::begin() {
  pinMode(_rainSensorPin, INPUT);
  pinMode(_rainOutputPin, OUTPUT);
  digitalWrite(_rainOutputPin, LOW);
  pinMode(_temperatureReadPin, INPUT);
  pinMode(_temperatureOutputPin, OUTPUT);
  digitalWrite(_temperatureOutputPin, LOW);
  pinMode(_heaterPin, OUTPUT);
  digitalWrite(_heaterPin, HIGH);
}

bool RainSensor::readValues() {
  digitalWrite(_temperatureOutputPin, HIGH);
  _temperature = analogRead(_temperatureReadPin);
  digitalWrite(_temperatureOutputPin, LOW);
  readRain();
  return true;
}

void RainSensor::setHeat(bool value) {
  _heat = value;
  digitalWrite(_heaterPin, !_heat);
}

void RainSensor::readRain() {
  digitalWrite(_rainOutputPin, HIGH);
  if (false) {
    delay(500);
    _rainValue = analogRead(_rainSensorPin);
  } else {
    _rainValue = 0;
    while (!pinReadFast(_rainSensorPin) && _rainValue < 30000) {
      _rainValue++;
    }
  }
  digitalWrite(_rainOutputPin, LOW);
}
