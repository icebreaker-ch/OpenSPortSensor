#include "BME280VarioVerticalSpeedSensor.h"
#include "log.h"

#define MILLISECONDS_PER_SECOND 1000

BME280VarioVerticalSpeedSensor::BME280VarioVerticalSpeedSensor(BME280 *pBme280, unsigned int sensorId) :
    Sensor(sensorId),
    pBme280(pBme280),
    reportInterval(0L),
    lastReportMillis(0L),
    lastReportAltitude(0.0F),
    lastReportVerticalSpeed(0.0F),
    pFilter(nullptr) {
}

void BME280VarioVerticalSpeedSensor::setReportInterval(unsigned long reportInterval) {
    this->reportInterval = reportInterval;
}

void BME280VarioVerticalSpeedSensor::setFilter(Filter *pFilter)
{
    this->pFilter = pFilter;
}

long BME280VarioVerticalSpeedSensor::getValue()
{
    unsigned long currentMillis = millis();
    float altitudeRead = pBme280->readAltitude();

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
