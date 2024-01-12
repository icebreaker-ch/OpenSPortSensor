#ifndef SENSOR_HUB_H
#define SENSOR_HUB_H
#include "global.h"
#include "Sensor.h"

#define DEFAULT_MAX_SENSORS 10

class SensorHub {
    public:
        SensorHub(PhysicalId physicalId);
        void addSensor(Sensor *pSensor);
        int getPhysicalId();
        Sensor *getNextSensor();

    private:
        PhysicalId physicalId;
        int sensorCount;
        int currentSensorIndex;
        Sensor **pSensors;
};

#endif