#include "VerticalSpeedSensor.h"
#include "log.h"

#define MILLISECONDS_PER_SECOND 1000

VerticalSpeedSensor::VerticalSpeedSensor(IAltitudeSensor *pAltitudeSensor, unsigned int sensorId) :
    Sensor(sensorId),
    pAltitudeSensor(pAltitudeSensor),
    pInterval(nullptr),
    lastReportAltitude(0.0F),
    lastReportVerticalSpeed(0.0F),
    pFilter(nullptr) {
}

void VerticalSpeedSensor::setReportInterval(Interval *pInterval) {
    this->pInterval = pInterval;
}

void VerticalSpeedSensor::setFilter(Filter *pFilter)
{
    this->pFilter = pFilter;
}

long VerticalSpeedSensor::getValue()
{
    float altitudeRead = pAltitudeSensor->readAltitude();
    if (pFilter) {
        pFilter->addValue(altitudeRead);
    }

    float currentVerticalSpeed;
    unsigned long diffMillis = pInterval->getMillisSinceLast();
    if (pInterval->isElapsed()) {
        float currentAltitude = pFilter ? pFilter->getFilteredValue() : altitudeRead;
        float diffAltitude = currentAltitude - lastReportAltitude;
        currentVerticalSpeed = diffAltitude * MILLISECONDS_PER_SECOND / diffMillis;        
        LOG("old: ", lastReportAltitude, " current: ", currentAltitude, " diff: ", diffAltitude, " vSpeed: ", currentVerticalSpeed, "\n");
        lastReportAltitude = currentAltitude;
        lastReportVerticalSpeed = currentVerticalSpeed;
        pFilter->reset();
    } else {
        currentVerticalSpeed = lastReportVerticalSpeed;
    }

    return (long)(round(PRECISION * currentVerticalSpeed));
}
