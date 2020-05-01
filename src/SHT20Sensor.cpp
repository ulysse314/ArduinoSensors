#include "SHT20Sensor.h"

#include "SHT20.h"

SHT20Sensor::SHT20Sensor(TwoWire *i2cBus) :
    _sht20(new SHT20(i2cBus)) {
}

SHT20Sensor::~SHT20Sensor() {
  delete _sht20;
}

void SHT20Sensor::loop() {
  switch(_sht20->waitingFor()) {
  case SHT20::Waiting::NoTrigger:
    break;
  case SHT20::Waiting::Temperature:
    if (_sht20->delayUntilRead() == 0) {
      _sht20->readValue();
    }
    break;
  case SHT20::Waiting::Humidity:
    if (_sht20->delayUntilRead() == 0) {
      _sht20->readValue();
      _sht20->triggerTemperatureMeasure();
    }
    break;
  }
}

bool SHT20Sensor::readValues() {
  if (_sht20->waitingFor() == SHT20::Waiting::NoTrigger) {
    _sht20->triggerHumidityMeasure();
  }
  return _sht20->waitingFor() != SHT20::Waiting::NoTrigger;
}

float SHT20Sensor::getTemperature() const {
  return _sht20->getTemperature();
}

float SHT20Sensor::getHumidity() const {
  return _sht20->getHumidity();
}
