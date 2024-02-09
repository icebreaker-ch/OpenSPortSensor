#include <Arduino.h>
#include <log.h>
#include "VoltageSensor.h"

VoltageSensor::VoltageSensor(uint8_t analogPin, long resistorToVoltage, long resistorToGround, unsigned int sensorId) :
    Sensor(sensorId),
    analogPin(analogPin),
    resistorToVoltage(resistorToVoltage),
    resistorToGround(resistorToGround),
    lastReportVoltage(0.0),
    pFilter(nullptr),
    reportInterval(0) {
}

void VoltageSensor::setFilter(Filter *pFilter) {
    this->pFilter = pFilter;
}

void VoltageSensor::setReportInterval(unsigned long reportInterval) {
    this->reportInterval = reportInterval;
}

long VoltageSensor::getValue() {
    int analogReadValue = analogRead(analogPin);
    double referenceVoltage = ANALOG_REFERENCE_VOLTAGE / 1000.0;
    double pinVoltage = (double)analogReadValue * referenceVoltage / 1024.0;
    double inputVoltage = pinVoltage * (resistorToGround + resistorToVoltage) / resistorToGround;
    pFilter->addValue(inputVoltage);

    double reportVoltage;
    if (timer.getElapsedTime() >= reportInterval) {
        reportVoltage = pFilter ? pFilter->getFilteredValue() : inputVoltage;
        pFilter->reset();
        lastReportVoltage = reportVoltage;
        LOG("report new Voltage: ", reportVoltage, "\n");
        timer.reset();
    } else {
        reportVoltage = lastReportVoltage;
    }

    return (long)(reportVoltage * PRECISION);
}