#ifndef VOLTAGE_SENSOR_H
#define VOLTAGE_SENSOR_H

#include "config.h"
#include "Sensor.h"
#include "Filter.h"
#include "Timer.h"

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
        VoltageSensor(uint8_t analogPin, long resistorToVoltage, long resistorToGround, unsigned int sensorId = VFAS_FIRST_ID + 1);
        void setReportInterval(Timer *pTimer);
        void setFilter(Filter *pFilter);
        long getValue() override;

    private:
        static const unsigned int PRECISION = 100; // 2 digits

        uint8_t analogPin;
        long resistorToVoltage;
        long resistorToGround;
        double lastReportVoltage;
        Filter *pFilter;
        Timer *pTimer;
};

#endif