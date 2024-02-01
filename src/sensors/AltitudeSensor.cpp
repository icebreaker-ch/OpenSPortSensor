#include "log.h"
#include "AltitudeSensor.h"

AltiudeSensor::AltiudeSensor(IAltitudeSensor *pAltitudeSensor, unsigned int sensorId) :
    Sensor(sensorId),
    pAltitudeSensor(pAltitudeSensor),
    pInterval(nullptr),
    lastReportValue(0L),
    pFilter(nullptr) {
}

void AltiudeSensor::setReportInterval(Interval *pInterval) {
    this->pInterval = pInterval;
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
    if (pInterval->isElapsed()) {
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
