#ifndef BME280_VARIO_ALTITUDE_SENSOR_H
#define BME280_VARIO_ALTITUDE_SENSOR_H

#include "global.h"
#include "Sensor.h"
#include "BME280.h"

class BME280VarioAltiudeSensor : public Sensor {
    public:
        BME280VarioAltiudeSensor(BME280 &bme280, unsigned int sensorId = ALT_FIRST_ID);
        long getValue();

    private:
        BME280 &bme280;
};

#endif
