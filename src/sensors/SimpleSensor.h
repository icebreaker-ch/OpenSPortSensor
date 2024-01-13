#ifndef SIMPLE_SENSOR_H
#define SIMPLE_SENSOR_H

#include "global.h"
#include "Sensor.h"

class SimpleSensor : public Sensor {
    public:
        SimpleSensor(unsigned int sensorId = DIY_FIRST_ID);
        long getValue();
};

#endif