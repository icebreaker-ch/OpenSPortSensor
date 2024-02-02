#include "VerticalSpeedSensor.h"
#include "log.h"

#define MILLISECONDS_PER_SECOND 1000

VerticalSpeedSensor::VerticalSpeedSensor(IAltitudeSensor *pAltitudeSensor, unsigned int sensorId) :
    Sensor(sensorId),
    pAltitudeSensor(pAltitudeSensor),
    pFilter(nullptr),
    reportInterval(0),
    lastReportAltitude(0.0F),
    lastReportVerticalSpeed(0.0F) {
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

    float currentVerticalSpeed;
    unsigned long elapsedTime = timer.getElapsedTime();
    if (elapsedTime >= reportInterval) {
        float currentAltitude = pFilter->getFilteredValue();
        float diffAltitude = currentAltitude - lastReportAltitude;
        currentVerticalSpeed = diffAltitude * MILLISECONDS_PER_SECOND / elapsedTime;        
        LOG("old: ", lastReportAltitude, " current: ", currentAltitude, " diff: ", diffAltitude, " vSpeed: ", currentVerticalSpeed, "\n");
        lastReportAltitude = currentAltitude;
        lastReportVerticalSpeed = currentVerticalSpeed;
        pFilter->reset();
        timer.reset();
    } else {
        currentVerticalSpeed = lastReportVerticalSpeed;
    }

    return (long)(round(PRECISION * currentVerticalSpeed));
}
