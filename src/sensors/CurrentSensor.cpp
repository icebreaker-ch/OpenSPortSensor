#include <Arduino.h>
#include <log.h>
#include "CurrentSensor.h"

CurrentSensor::CurrentSensor(uint8_t analogPin, double millivoltsForZeroAmps, double millivoltsPerAmp, unsigned int sensorId) :
    Sensor(sensorId),
    analogPin(analogPin),
    millivoltsForZeroAmps(millivoltsForZeroAmps),
    millivoltsPerAmp(millivoltsPerAmp),
    lastReportCurrent(0.0),
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
    long pinMilliVolts = analogReadValue * ANALOG_REFERENCE_VOLTAGE / 1024;
    double current = (pinMilliVolts - millivoltsForZeroAmps) / millivoltsPerAmp;

    pFilter->addValue(current);

    double reportCurrent;
    if (timer.getElapsedTime() >= reportInterval) {
        reportCurrent = pFilter ? pFilter->getFilteredValue() : current;
        pFilter->reset();
        lastReportCurrent = reportCurrent;
        LOG("report new Current: ", reportCurrent, "\n");
        timer.reset();
    } else {
        reportCurrent = lastReportCurrent;
    }

    return (long)(reportCurrent * PRECISION);
}