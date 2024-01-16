#include "SensorHub.h"
#include "config.h"

SensorHub::SensorHub(PhysicalId physicalId) :
    physicalId(physicalId),
    sensorCount(0),
    currentSensorIndex(0) {
        for (int index = 0; index < MAX_SENSORS; ++index)
           sensors[index] = nullptr;
}

void SensorHub::addSensor(Sensor *pSensor) {
    sensors[sensorCount++] = pSensor;
}

int SensorHub::getPhysicalId() {
    return physicalId;
}

Sensor *SensorHub::getNextSensor() {
    if (sensorCount > 0) {
        currentSensorIndex = (currentSensorIndex + 1) % sensorCount;
        return sensors[currentSensorIndex];
    }
    return nullptr;
}
