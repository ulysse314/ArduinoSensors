#ifndef RainSensor_h
#define RainSensor_h

#include "Sensor.h"

#include <inttypes.h>

class RainSensor : public Sensor {
  public:
    RainSensor(uint8_t rainSensorPin, uint8_t rainOutputPin, uint8_t temperatureSensorPin, uint8_t temperatureOutputPin, uint8_t heaterPin);

    const char *sensorClass() const override { return "RainSensor"; };
    void begin() override;
    bool readValues() override;
    void loop() override;

    float getTemperature() const { return _temperature; };
    unsigned long long getRainValue() const { return _rainValue; };
    bool getHeat() const { return _heat; };

    void setHeat(bool value);

  protected:
    void readRain();

    const uint8_t _rainSensorPin;
    const uint8_t _rainOutputPin;
    const uint8_t _temperatureReadPin;
    const uint8_t _temperatureOutputPin;
    const uint8_t _heaterPin;

    bool _heat;
    float _temperature;
    unsigned long long _rainValue;
    unsigned long _heatDate;
};

#endif  // RainSensor_h
