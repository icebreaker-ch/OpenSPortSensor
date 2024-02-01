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
    pInterval(nullptr) {
}

void VoltageSensor::setFilter(Filter *pFilter) {
    this->pFilter = pFilter;
}

void VoltageSensor::setReportInterval(Interval *pInterval) {
    this->pInterval = pInterval;
}

long VoltageSensor::getValue() {
    int analogReadValue = analogRead(analogPin);
    double referenceVoltage = ANALOG_REFERENCE_VOLTAGE / 1000.0;
    double pinVoltage = (double)analogReadValue * referenceVoltage / 1024.0;
    double inputVoltage = pinVoltage * (resistorToGround + resistorToVoltage) / resistorToGround;

    if (pFilter) {
        pFilter->addValue(inputVoltage);
    }
    
    double reportVoltage;
    if (pInterval->isElapsed()) {
        reportVoltage = pFilter ? pFilter->getFilteredValue() : inputVoltage;
        if (pFilter) {
            pFilter->reset();
        }
        lastReportVoltage = reportVoltage;
        LOG("report new Voltage: ", reportVoltage, "\n");
    } else {
        reportVoltage = lastReportVoltage;
    }

    return (long)(reportVoltage * PRECISION);
}