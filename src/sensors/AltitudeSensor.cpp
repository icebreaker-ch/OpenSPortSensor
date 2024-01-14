#include "log.h"
#include "AltitudeSensor.h"

AltiudeSensor::AltiudeSensor(IAltitudeSensor *pAltitudeSensor, unsigned int sensorId) :
    Sensor(sensorId),
    pAltitudeSensor(pAltitudeSensor),
    reportInterval(0),
    lastReportMillis(0L),
    lastReportValue(0L),
    pFilter(nullptr) {
}

void AltiudeSensor::setReportInterval(unsigned long reportInterval) {
    this->reportInterval = reportInterval;
}

void AltiudeSensor::setFilter(Filter *pFilter)
{
    this->pFilter = pFilter;
}

long AltiudeSensor::getValue()
{
    long currentMillis = millis();
    float altitude = pAltitudeSensor->readAltitude();
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
