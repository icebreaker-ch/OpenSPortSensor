#include <math.h>
#include "GPSPositionSensor.h"

GPSPositionSensor::GPSPositionSensor(IGPSSensor *pGPSSensor, unsigned int sensorId) :
    Sensor(sensorId),
    reportLongitude(false),
    pGPSSensor(pGPSSensor) {
}

long GPSPositionSensor::getValue() {
    double value = reportLongitude ? pGPSSensor->getLongitude() : pGPSSensor->getLatitude();
    unsigned long int reportValue = (unsigned long)(fabs(value) * 600000) & 0x3FFFFFFF;

    if (value < 0) {
        reportValue |= 0x40000000;
    }

    if (reportLongitude) {
        reportValue |= 0x80000000;
    }
    reportLongitude = !reportLongitude;
    return reportValue;
}
