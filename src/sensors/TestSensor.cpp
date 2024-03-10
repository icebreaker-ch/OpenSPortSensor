#include <Arduino.h>
#include "TestSensor.h"

TestSensor::TestSensor(unsigned int sensorId) :
    Sensor(sensorId),
    currentValue(0) {
}

long TestSensor::getValue() {
    return currentValue++;
}