#ifndef TEST_SENSOR_H
#define TEST_SENSOR_H

#include "global.h"
#include "Sensor.h"

/**
 * A simple sensor wich returns a counting value for each call,
 * so we have an easy check, if all frames are making their way back
 * to the transmitter.
 */
class TestSensor : public Sensor {
    private:
        long currentValue;

    public:
        explicit TestSensor(unsigned int sensorId = DIY_FIRST_ID + 1);
        long getValue() override;
};

#endif