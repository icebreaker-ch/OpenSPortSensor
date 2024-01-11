#ifndef VOLTAGE_SENSOR_H
#define VOLTAGE_SENSOR_H

#include "config.h"
#include "Sensor.h"

/**
 * A voltage measurement sensor.
 * You have to make sure to reduce the input voltage to the range [0..ANALOG_VOLTAGE_REFERENCE]
 * by using a voltage divider:
 * 
 * Vin o-----.
 *           |
 *          .-.
 *          | | R1 (resistorToVoltage)
 *          | |
 *          `-'
 *           |--------o Ax (Arduino analog pin)
 *          .-.
 *          | | R2 (resistorToGround)
 *          | |
 *          `-'
 *           |
 * Gnd o-----+--------o Gnd
 * 
*/ 
class VoltageSensor : public Sensor
{
    public:
        VoltageSensor(unsigned int sensorId, uint8_t analogPin, long resistorToVoltage, long resistorToGround);
        long getValue();

    private:
        uint8_t analogPin;
        long resistorToVoltage;
        long resistorToGround;
};

#endif