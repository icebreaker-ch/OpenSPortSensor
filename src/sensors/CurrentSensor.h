#ifndef CURRENT_SENSOR_H
#define CURRENT_SENSOR_H

#include "config.h"
#include "Sensor.h"
#include "Filter.h"
#include "Timer.h"

/**
 * A current measurement sensor.
 * You have to make sure to reduce the input voltage to the range [0..ANALOG_VOLTAGE_REFERENCE]
 * eventually by using a voltage divider.
 */
class CurrentSensor : public Sensor {
    public:
        CurrentSensor(uint8_t analogPin, double millivoltsForZeroAmps, double millivoltsPerAmp, unsigned int sensorId = CURR_FIRST_ID);
        void setReportInterval(unsigned long reportInterval);
        void setFilter(Filter *pFilter);
        long getValue() override;

    private:
        static const unsigned int PRECISION = 10; // 1 digit

        uint8_t analogPin;
        double millivoltsForZeroAmps;
        double millivoltsPerAmp;
        double current;
        Filter *pFilter;
        Timer timer;
        unsigned long reportInterval;
};

#endif