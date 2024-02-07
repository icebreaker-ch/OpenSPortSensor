#ifndef SENSOR_HUB_H
#define SENSOR_HUB_H
#include <List.h>
#include "global.h"
#include "config.h"
#include "Sensor.h"

class SensorHub {
    public:
        explicit SensorHub(PhysicalId physicalId);
        void addSensor(Sensor *pSensor);
        PhysicalId getPhysicalId();
        Sensor *getNextSensor();

    private:
        SensorHub(SensorHub &) = delete;
        SensorHub operator=(SensorHub &) = delete;
        PhysicalId physicalId;
        int currentSensorIndex;
        List<Sensor *>sensors;
        List<Sensor *>::Iterator iterator;
};

#endif