#ifndef SIMPLE_SENSOR_H
#define SIMPLE_SENSOR_H

#include <Sensor.h>

class SimpleSensor : public Sensor {
    public:
        SimpleSensor(int sensorId);
        long getValue();
};

#endif