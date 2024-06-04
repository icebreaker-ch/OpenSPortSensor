#include "log.h"
#include "AltitudeSensor.h"

AltiudeSensor::AltiudeSensor(IAltitudeSensor *pAltitudeSensor, unsigned int sensorId) :
    Sensor(sensorId),
    pAltitudeSensor(pAltitudeSensor),
    pFilter(nullptr),
    reportInterval(0),
    altitude(0L) {
}

void AltiudeSensor::setReportInterval(unsigned long reportInterval) {
    this->reportInterval = reportInterval;
}

void AltiudeSensor::setFilter(Filter *pFilter) {
    this->pFilter = pFilter;
}

long AltiudeSensor::getValue() {
    float readAltitude = pAltitudeSensor->readAltitude();
    pFilter->addValue(readAltitude);

    if (timer.getElapsedTime() >= reportInterval) {
        altitude = pFilter->getFilteredValue();
        pFilter->reset();
        timer.reset();
        LOG("new altitude: ", altitude, "\n");
    }

    return ((long)(round(PRECISION * altitude)));
}
