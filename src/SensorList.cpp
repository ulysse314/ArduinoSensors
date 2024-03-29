#include "SensorList.h"

#include "Sensor.h"

#include <Arduino.h>

SensorList::SensorList() {
  _sensorBucket = NULL;
}

SensorList::~SensorList() {
  while (_sensorBucket) {
    delete _sensorBucket->sensor;
    SensorBucket *nextBucket = _sensorBucket->nextBucket;
    delete _sensorBucket;
    _sensorBucket = nextBucket;
  }
}

void SensorList::addSensor(Sensor *sensor) {
  SensorBucket *newSensorBucket;
  SensorBucket **bucketCursor;

  newSensorBucket = (SensorBucket *)malloc(sizeof(SensorBucket));
  newSensorBucket->sensor = sensor;
  newSensorBucket->nextBucket = NULL;

  bucketCursor = &_sensorBucket;
  while (*bucketCursor) {
    bucketCursor = &((*bucketCursor)->nextBucket);
  }
  *bucketCursor = newSensorBucket;
}

Sensor *SensorList::sensorAtIndex(unsigned int index) {
  SensorBucket *bucketCursor = _sensorBucket;

  while (bucketCursor && index > 0) {
    bucketCursor = bucketCursor->nextBucket;
    index--;
  }
  return bucketCursor?bucketCursor->sensor:NULL;
}

unsigned int SensorList::sensorCount(void) {
  SensorBucket *bucketCursor = _sensorBucket;
  unsigned int count = 0;

  while (bucketCursor) {
    bucketCursor = bucketCursor->nextBucket;
    count++;
  }
  return count;
}

Sensor *SensorList::getNextSensor(void **cursor) {
  Sensor *result;

  if (cursor == NULL || *cursor == NULL) {
    result = NULL;
  } else {
    SensorBucket *bucketCursor = (SensorBucket *)*cursor;
    result = bucketCursor->sensor;
    *cursor = (void *)(bucketCursor->nextBucket);
  }
  return result;
}

void SensorList::begin() {
  SensorBucket *bucketCursor = _sensorBucket;
  while (bucketCursor) {
    bucketCursor->sensor->begin();
    bucketCursor = bucketCursor->nextBucket;
  }
}

void SensorList::loop() {
  SensorBucket *bucketCursor = _sensorBucket;
  while (bucketCursor) {
    bucketCursor->sensor->loop();
    bucketCursor = bucketCursor->nextBucket;
  }
}

bool SensorList::readValues() {
  bool result = true;
  SensorBucket *bucketCursor = _sensorBucket;

  while (bucketCursor) {
    bool sensorResult = bucketCursor->sensor->readValues();
    result = sensorResult && result;
    bucketCursor = bucketCursor->nextBucket;
  }
  return result;
}

bool SensorList::resetValues() {
  bool result = true;
  SensorBucket *bucketCursor = _sensorBucket;

  while (bucketCursor) {
    result = bucketCursor->sensor->resetValues() && result;
    bucketCursor = bucketCursor->nextBucket;
  }
  return result;
}

bool SensorList::areAllReady() {
  bool result = true;
  SensorBucket *bucketCursor = _sensorBucket;

  while (bucketCursor) {
    if (!bucketCursor->sensor->isReady()) {
      result = false;
      break;
    }
    bucketCursor = bucketCursor->nextBucket;
  }
  return result;
}
