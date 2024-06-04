#include "VerticalSpeedSensor.h"
#include "log.h"

#define MILLISECONDS_PER_SECOND 1000

VerticalSpeedSensor::VerticalSpeedSensor(IAltitudeSensor *pAltitudeSensor, unsigned int sensorId) :
    Sensor(sensorId),
    pAltitudeSensor(pAltitudeSensor),
    pFilter(nullptr),
    reportInterval(0),
    lastReportAltitude(0.0F),
    verticalSpeed(0.0F) {
}

void VerticalSpeedSensor::setReportInterval(unsigned long reportInterval) {
    this->reportInterval = reportInterval;
}

void VerticalSpeedSensor::setFilter(Filter *pFilter) {
    this->pFilter = pFilter;
}

long VerticalSpeedSensor::getValue() {
    float altitudeRead = pAltitudeSensor->readAltitude();
    pFilter->addValue(altitudeRead);

    unsigned long elapsedTime = timer.getElapsedTime();
    if (elapsedTime >= reportInterval) {
        float currentAltitude = pFilter->getFilteredValue();
        float diffAltitude = currentAltitude - lastReportAltitude;
        verticalSpeed = diffAltitude * MILLISECONDS_PER_SECOND / elapsedTime;
        pFilter->reset();
        timer.reset();

        LOG("old: ", lastReportAltitude, " current: ", currentAltitude, " diff: ", diffAltitude, " vSpeed: ", verticalSpeed, "\n");
        lastReportAltitude = currentAltitude;
    }
    return (long)(round(PRECISION * verticalSpeed));
}
