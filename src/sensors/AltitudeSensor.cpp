#include "log.h"
#include "AltitudeSensor.h"

AltiudeSensor::AltiudeSensor(IAltitudeSensor *pAltitudeSensor, unsigned int sensorId) :
    Sensor(sensorId),
    pAltitudeSensor(pAltitudeSensor),
    pFilter(nullptr),
    pTimer(nullptr),
    lastReportValue(0L) {
}

void AltiudeSensor::setReportInterval(Timer *pTimer) {
    this->pTimer = pTimer;
}

void AltiudeSensor::setFilter(Filter *pFilter) {
    this->pFilter = pFilter;
}

long AltiudeSensor::getValue() {
    float altitude = pAltitudeSensor->readAltitude();
    if (pFilter) {
        pFilter->addValue(altitude);
    }

    long result;
    if (pTimer->isElapsed()) {
        float reportAltitude = pFilter ? pFilter->getFilteredValue() : altitude;
        if (pFilter) {
            pFilter->reset();
        }
        result = ((long)(round(PRECISION * reportAltitude)));        
        lastReportValue = result;
        LOG("new altitude: ", reportAltitude, " result: ", result, "\n");
    } else {
        result = lastReportValue;
    }

    return result;
}
