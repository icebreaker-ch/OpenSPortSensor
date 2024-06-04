#include <Arduino.h>
#include <log.h>
#include "VoltageSensor.h"

VoltageSensor::VoltageSensor(uint8_t analogPin, long resistorToVoltage, long resistorToGround, unsigned int sensorId) :
    Sensor(sensorId),
    analogPin(analogPin),
    resistorToVoltage(resistorToVoltage),
    resistorToGround(resistorToGround),
    voltage(0.0),
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

    if (timer.getElapsedTime() >= reportInterval) {
        voltage = pFilter->getFilteredValue();
        pFilter->reset();
        timer.reset();
        LOG("report new Voltage: ", voltage, "\n");
    }

    return (long)(voltage * PRECISION);
}