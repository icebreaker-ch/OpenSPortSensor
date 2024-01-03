#include <SensorPool.h>

SensorPool::SensorPool(int physicalId, int maxSensorCount) :
    physicalId(physicalId),
    sensorCount(0),
    currentSensorIndex(0)
{
    pSensors = new Sensor*[maxSensorCount];
}

void SensorPool::addSensor(Sensor *pSensor) {
    pSensors[sensorCount++] = pSensor;
}

int SensorPool::getPhysicalId() {
    return physicalId;
}

Sensor *SensorPool::getNextSensor() {
    if (sensorCount > 0) {
        currentSensorIndex = (currentSensorIndex + 1) % sensorCount;
        return pSensors[currentSensorIndex];
    }
    return nullptr;
}
