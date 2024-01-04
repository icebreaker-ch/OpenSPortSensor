#include "SensorHub.h"

SensorHub::SensorHub(PhysicalId physicalId, int maxSensorCount) :
    physicalId(physicalId),
    sensorCount(0),
    currentSensorIndex(0)
{
    pSensors = new Sensor*[maxSensorCount];
}

void SensorHub::addSensor(Sensor *pSensor) {
    pSensors[sensorCount++] = pSensor;
}

int SensorHub::getPhysicalId() {
    return physicalId;
}

Sensor *SensorHub::getNextSensor() {
    if (sensorCount > 0) {
        currentSensorIndex = (currentSensorIndex + 1) % sensorCount;
        return pSensors[currentSensorIndex];
    }
    return nullptr;
}
