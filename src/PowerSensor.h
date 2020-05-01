#ifndef PowerSensor_h
#define PowerSensor_h

#include "Sensor.h"

#include <inttypes.h>

class PowerSensor : public Sensor {
public:
  PowerSensor(uint8_t amperePin, uint8_t voltPin, double kAmpereCoef, double kVoltCoef);
  ~PowerSensor();

  const char *sensorClass() const override { return "PowerSensor"; };
  const char *addressString() const override { return _address; };
  void begin() override;
  bool readValues() override;

protected:
  const uint8_t _amperePin;
  const uint8_t _voltPin;
  const double _kAmpereCoef;
  const double _kVoltCoef;
  const char *_address = NULL;
  uint32_t _rawAmpere = 0;
  uint32_t _rawVolt = 0;
};

#endif // PowerSensor_h
