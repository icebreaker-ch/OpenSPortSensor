#include <Arduino.h>
#include "SimpleSensor.h"

SimpleSensor::SimpleSensor(unsigned int sensorId) :
    Sensor(sensorId) {
}

long SimpleSensor::getValue() {
    return 100 + millis() / 1000;
}