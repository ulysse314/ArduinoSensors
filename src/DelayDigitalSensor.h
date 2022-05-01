#ifndef DelayDigitalSensor_h
#define DelayDigitalSensor_h

#include "DigitalSensor.h"

#include <inttypes.h>

class DelayDigitalSensor : public DigitalSensor {
public:
  DelayDigitalSensor(uint8_t pin, unsigned long long delay_in_seconds);

  const char *sensorClass() const override { return "DelayDigitalSensor"; };
  bool readValues() override;

protected:
  const unsigned long long _delay = 0;
  unsigned long long _last_set = 0;
};

#endif // DelayDigitalSensor_h
