#include <math.h>
#include "GPSAltitudeSensor.h"

GPSAltitudeSensor::GPSAltitudeSensor(IGPSSensor *pGPSSensor, unsigned int sensorId) :
    Sensor(sensorId),
    pGPSSensor(pGPSSensor) {
}

long GPSAltitudeSensor::getValue()
{
    return static_cast<long>(round(pGPSSensor->getAltitude() * PRECICION));
}
