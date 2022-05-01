#ifndef DigitalSensor_h
#define DigitalSensor_h

#include "Sensor.h"

#include <inttypes.h>

class DigitalSensor : public Sensor {
public:
  DigitalSensor(uint8_t pin);

  const char *sensorClass() const override { return "DigitalSensor"; };
  void begin() override;
  void loop() override;
  bool readValues() override;

  bool value() const { return _value; };
  bool hasValueChanged() const { return _previousValue != _value; };

protected:
  const uint8_t _pin = 0;
  bool _value = 0;
  bool _previousValue = 0;
};

#endif // DigitalSensor_h
