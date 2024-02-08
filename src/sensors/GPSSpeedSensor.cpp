#include <math.h>
#include "GPSSpeedSensor.h"

GPSSpeedSensor::GPSSpeedSensor(IGPSSensor *pGPSSensor, unsigned int sensorId) :
    Sensor(sensorId),
    pGPSSensor(pGPSSensor) {
}

long GPSSpeedSensor::getValue()
{
    return static_cast<long>(pGPSSensor->getSpeed() * PRECICION + 0.5);
}
