#ifndef BME280_H
#define BME280_H

#include <Arduino.h>
#include <Adafruit_BME280.h>
#include "IAltitudeSensor.h"

#define STANDARD_SEALEVEL_PRESSURE 1013.25

/**
 * Adafruit BME280 pressure sensor
*/
class BME280  : public IAltitudeSensor {
    public:
        BME280(uint8_t address = BME280_DEFAULT_ADDR);
        float readAltitude();
        float readPressure();
        float readTemperature();
    private:
        static const unsigned int BME280_DEFAULT_ADDR = 0x76;

        Adafruit_BME280 bme;
};

#endif
