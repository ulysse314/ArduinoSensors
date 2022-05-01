#ifndef AnalogSensor_h
#define AnalogSensor_h

#include <inttypes.h>

#include "Sensor.h"

class AnalogSensor : public Sensor {
public:
  AnalogSensor(uint8_t pin);

  const char *sensorClass() const override { return "AnalogSensor"; };
  void begin() override;
  bool readValues() override;

  uint32_t value() const { return _value; };

protected:
  const uint8_t _pin = 0;
  uint32_t _value = -1;
};

#endif // AnalogSensor_h
