#ifndef BME280_VARIO_VSPEED_SENSOR_H
#define BME280_VARIO_VSPEED_SENSOR_H

#include "global.h"
#include "Sensor.h"
#include "BME280.h"
#include "Filter.h"

class BME280VarioVSpeedSensor : public Sensor {
    public:
        BME280VarioVSpeedSensor(BME280 &bme280, int sensorId = VARIO_FIRST_ID);
        void setFilter(Filter *pFilter);
        long getValue();

    private:
        BME280 &bme280;
        unsigned long lastMillis;
        float lastValidAltitude;
        float currentVSpeed;
        Filter *pFilter;
};

#endif
