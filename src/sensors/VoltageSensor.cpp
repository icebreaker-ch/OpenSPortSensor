#include <Arduino.h>
#include "VoltageSensor.h"

VoltageSensor::VoltageSensor(uint8_t analogPin, long resistorToVoltage, long resistorToGround, unsigned int sensorId) :
    analogPin(analogPin),
    resistorToVoltage(resistorToVoltage),
    resistorToGround(resistorToGround),
    Sensor(sensorId) {
}

long VoltageSensor::getValue() {
    int analogReadValue = analogRead(analogPin);
    double referenceVoltage = ANALOG_REFERENCE_VOLTAGE / 1000.0;
    double pinVoltage = (double)analogReadValue * referenceVoltage / 1024.0;
    double inputVoltage = pinVoltage * (resistorToGround + resistorToVoltage) / resistorToGround;
    return (long)(inputVoltage * 100); // resolution: 2 digits
}