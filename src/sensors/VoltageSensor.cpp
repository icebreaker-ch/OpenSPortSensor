#include <Arduino.h>
#include <log.h>
#include "VoltageSensor.h"

VoltageSensor::VoltageSensor(uint8_t analogPin, long resistorToVoltage, long resistorToGround, unsigned int sensorId) :
    Sensor(sensorId),
    analogPin(analogPin),
    resistorToVoltage(resistorToVoltage),
    resistorToGround(resistorToGround),
    reportInterval(0),
    lastReportMillis(0L),
    lastReportVoltage(0.0),
    pFilter(nullptr) {
}

void VoltageSensor::setReportInterval(unsigned long reportInterval) {
    this->reportInterval = reportInterval;
}

void VoltageSensor::setFilter(Filter *pFilter) {
    this->pFilter = pFilter;
}

long VoltageSensor::getValue() {
    unsigned long currentMillis = millis();
    int analogReadValue = analogRead(analogPin);
    double referenceVoltage = ANALOG_REFERENCE_VOLTAGE / 1000.0;
    double pinVoltage = (double)analogReadValue * referenceVoltage / 1024.0;
    double inputVoltage = pinVoltage * (resistorToGround + resistorToVoltage) / resistorToGround;
    unsigned long diffMillis = currentMillis - lastReportMillis;

    double reportVoltage;
    if (lastReportMillis == 0) { // First report
        reportVoltage = inputVoltage; // Report currnt voltage
        lastReportMillis = currentMillis;
        lastReportVoltage = inputVoltage;
    } else if (diffMillis < reportInterval) { // Collecting data
        if (pFilter) {
            pFilter->addValue(pinVoltage);
        }
        reportVoltage = lastReportVoltage; // Report last Voltage
    } else { // Report new value
        reportVoltage = pFilter ? pFilter->getFilteredValue() : inputVoltage;
        if (pFilter) {
            pFilter->reset();
        }
        lastReportMillis = currentMillis;
        lastReportVoltage = reportVoltage;
        LOG("reportVoltage: ", reportVoltage, "\n");
    }
    return (long)(reportVoltage * PRECISION);
}