#include "VerticalSpeedSensor.h"
#include "log.h"

#define MILLISECONDS_PER_SECOND 1000

VerticalSpeedSensor::VerticalSpeedSensor(IAltitudeSensor *pAltitudeSensor, unsigned int sensorId) :
    Sensor(sensorId),
    pAltitudeSensor(pAltitudeSensor),
    reportInterval(0L),
    lastReportMillis(0L),
    lastReportAltitude(0.0F),
    lastReportVerticalSpeed(0.0F),
    pFilter(nullptr) {
}

void VerticalSpeedSensor::setReportInterval(unsigned long reportInterval) {
    this->reportInterval = reportInterval;
}

void VerticalSpeedSensor::setFilter(Filter *pFilter)
{
    this->pFilter = pFilter;
}

long VerticalSpeedSensor::getValue()
{
    unsigned long currentMillis = millis();
    float altitudeRead = pAltitudeSensor->readAltitude();

    unsigned long diffMillis = currentMillis - lastReportMillis;
    float currentVerticalSpeed;

    if (lastReportMillis == 0) { // First read
        lastReportMillis = currentMillis;
        lastReportAltitude = altitudeRead;
        currentVerticalSpeed = 0; // Calculation not possible
    } else if (diffMillis < reportInterval) { // Collecting values
        pFilter->addValue(altitudeRead);
        currentVerticalSpeed = lastReportVerticalSpeed;
    } else { // Send new Value
        pFilter->addValue(altitudeRead);
        float currentValidAltitude = pFilter->getFilteredValue();
        float diffAltitude = currentValidAltitude - lastReportAltitude;
        currentVerticalSpeed = diffAltitude * MILLISECONDS_PER_SECOND / diffMillis;

        LOG("old: ", lastReportAltitude, " current: ", currentValidAltitude, " diff: ", diffAltitude, " vSpeed: ", currentVerticalSpeed, "\n");
        lastReportMillis = currentMillis;
        lastReportAltitude = currentValidAltitude;
        lastReportVerticalSpeed = currentVerticalSpeed;
        pFilter->reset();
    }
    return (long)(round(PRECISION * currentVerticalSpeed));
}
