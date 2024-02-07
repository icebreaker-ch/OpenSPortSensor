#include "SensorHub.h"
#include "config.h"

SensorHub::SensorHub(PhysicalId physicalId) :
    physicalId(physicalId),
    currentSensorIndex(0),
    iterator(sensors.begin()) {
}

void SensorHub::addSensor(Sensor *pSensor) {
    sensors.add(pSensor);
}

PhysicalId SensorHub::getPhysicalId() {
    return physicalId;
}

Sensor *SensorHub::getNextSensor() {
    Sensor *pSensor;
    if (iterator == sensors.end())
        iterator = sensors.begin();
    pSensor = *iterator;
    ++iterator;
    return pSensor;
}
