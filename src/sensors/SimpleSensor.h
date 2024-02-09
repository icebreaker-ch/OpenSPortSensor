#ifndef SIMPLE_SENSOR_H
#define SIMPLE_SENSOR_H

#include "global.h"
#include "Sensor.h"

/**
 * A simple sensor wich returns a new value for each call.
 */
class SimpleSensor : public Sensor {
    public:
        explicit SimpleSensor(unsigned int sensorId = DIY_FIRST_ID);
        long getValue() override;
};

#endif