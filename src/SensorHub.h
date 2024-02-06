#ifndef SENSOR_HUB_H
#define SENSOR_HUB_H
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
        int sensorCount;
        int currentSensorIndex;
        Sensor *sensors[MAX_SENSORS];
};

#endif