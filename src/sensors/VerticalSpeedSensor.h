#ifndef VERTICAL_SPEED_SENSOR_H
#define VERTICAL_SPEED_SENSOR_H

#include "global.h"
#include "Sensor.h"
#include "IAltitudeSensor.h"
#include "Filter.h"

class VerticalSpeedSensor : public Sensor {
    public:
        VerticalSpeedSensor(IAltitudeSensor *pAltitudeSensor, unsigned int sensorId = VARIO_FIRST_ID);
        void setReportInterval(unsigned long reportInterval);
        void setFilter(Filter *pFilter);
        long getValue();

    private:
        static const unsigned int PRECISION = 100; // Precision 2 digits

        IAltitudeSensor *pAltitudeSensor;
        unsigned long reportInterval;
        unsigned long lastReportMillis;
        float lastReportAltitude;
        float lastReportVerticalSpeed;
        Filter *pFilter;
};

#endif
