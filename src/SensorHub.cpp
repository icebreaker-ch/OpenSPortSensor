#include "SensorHub.h"
#include "config.h"

SensorHub::SensorHub(PhysicalId physicalId) :
    physicalId(physicalId),
    sensorCount(0),
    currentSensorIndex(0)
{
    pSensors = new Sensor*[MAX_SENSORS];
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
