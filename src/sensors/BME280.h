#ifndef BME280_H
#define BME280_H

#include <Arduino.h>
#include <Adafruit_BME280.h>

#define BME280_ADDR 0x76

/**
 * Adafruit BME280 pressure sensor
*/
class BME280  {
    public:
        BME280(uint8_t address = BME280_ADDR);
        float readAltitude();
        float readPressure();
        float readTemperature();
    private:
        Adafruit_BME280 bme;
};

#endif
