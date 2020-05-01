#ifndef SHT20Sensor_h
#define SHT20Sensor_h

#include "Sensor.h"

class SHT20;
class TwoWire;

class SHT20Sensor : public Sensor {
public:
  SHT20Sensor(TwoWire *i2cBus);
  ~SHT20Sensor();

  virtual const char *sensorClass() const override { return "STH"; };
  virtual const char *sensorType() const override { return "STH20"; };
  virtual void loop() override;
  virtual bool readValues() override;

  float getTemperature() const;
  float getHumidity() const;

protected:
  SHT20 *_sht20;
};

#endif  // SHT20Sensor_h
