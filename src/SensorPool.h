#ifndef SENSOR_POOL_H
#define SENSOR_POOL_H

#include <Sensor.h>

#define DEFAULT_MAX_SENSORS 10

class SensorPool {
    public:
        SensorPool(int physicalId, int maxSensorCount = DEFAULT_MAX_SENSORS);
        void addSensor(Sensor *pSensor);
        int getPhysicalId();
        Sensor *getNextSensor();

    private:
        int physicalId;
        int sensorCount;
        int currentSensorIndex;
        Sensor **pSensors;
};

#endif