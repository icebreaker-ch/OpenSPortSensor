#include "log.h"
#include "BME280VarioAltitudeSensor.h"

BME280VarioAltiudeSensor::BME280VarioAltiudeSensor(BME280 *pBme280, unsigned int sensorId) :
    Sensor(sensorId),
    pBme280(pBme280),
    reportInterval(0),
    lastReportMillis(0L),
    lastReportValue(0L),
    pFilter(nullptr) {
}

void BME280VarioAltiudeSensor::setReportInterval(unsigned long reportInterval) {
    this->reportInterval = reportInterval;
}

void BME280VarioAltiudeSensor::setFilter(Filter *pFilter)
{
    this->pFilter = pFilter;
}

long BME280VarioAltiudeSensor::getValue()
{
    long currentMillis = millis();
    float altitude = pBme280->readAltitude();
    if (pFilter) {
        pFilter->addValue(altitude);
    }

    long result;
    if ((currentMillis - lastReportMillis) >= reportInterval) {
        float reportAltitude = pFilter ? pFilter->getFilteredValue() : altitude;
        if (pFilter) {
            pFilter->reset();
        }
        result = ((long)(round(PRECISION * reportAltitude)));        
        lastReportValue = result;
        lastReportMillis = currentMillis;
        LOG("altitude: ", reportAltitude, " result: ", result, "\n");
    } else {
        result = lastReportValue;
    }
    return result;
}
