#include <math.h>
#include "GPSCourseSensor.h"

GPSCourseSensor::GPSCourseSensor(IGPSSensor *pGPSSensor, unsigned int sensorId) :
    Sensor(sensorId),
    pGPSSensor(pGPSSensor) {
}

long GPSCourseSensor::getValue()
{
    return static_cast<long>(round(pGPSSensor->getCourse() * PRECICION));
}
