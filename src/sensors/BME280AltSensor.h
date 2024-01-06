#ifndef BME280_ALT_SENSOR_H
#define BME280_ALT_SENSOR_H

#include <Arduino.h>
#include <Adafruit_BME280.h>

#include "Sensor.h"

#define BME280_ADDR 0x76

class BME280AltSensor : public Sensor {
    public:
        BME280AltSensor(int sensorId, uint8_t address = BME280_ADDR);
        long getValue();
    private:
        Adafruit_BME280 bme;
};

#endif