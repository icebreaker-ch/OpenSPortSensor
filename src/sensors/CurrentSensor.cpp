#include <Arduino.h>
#include <log.h>
#include "CurrentSensor.h"

CurrentSensor::CurrentSensor(uint8_t analogPin, int millivoltsForZeroAmps, int millivoltsPerAmp, unsigned int sensorId) :
    Sensor(sensorId),
    analogPin(analogPin),
    millivoltsForZeroAmps(millivoltsForZeroAmps),
    millivoltsPerAmp(millivoltsPerAmp),
    current(0.0),
    pFilter(nullptr),
    reportInterval(0) {
}

void CurrentSensor::setFilter(Filter *pFilter) {
    this->pFilter = pFilter;
}

void CurrentSensor::setReportInterval(unsigned long reportInterval) {
    this->reportInterval = reportInterval;
}

long CurrentSensor::getValue() {
    long analogReadValue = analogRead(analogPin);
    double pinMilliVolts = analogReadValue * ANALOG_REFERENCE_VOLTAGE / 1024.0;
    double readCurrent = (pinMilliVolts - millivoltsForZeroAmps) / millivoltsPerAmp;

    pFilter->addValue(readCurrent);

    if (timer.getElapsedTime() >= reportInterval) {
        current = pFilter->getFilteredValue();
        pFilter->reset();
        timer.reset();
        LOG("report new Current: ", reportCurrent, "\n");
    }
    return (long)(current * PRECISION);
}