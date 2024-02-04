#ifndef ALTITUDE_SENSOR_H
#define ALTITUDE_SENSOR_H

#include "global.h"
#include "Sensor.h"
#include "IAltitudeSensor.h"
#include "Timer.h"
#include "Filter.h"

class AltiudeSensor : public Sensor {
    public:
        explicit AltiudeSensor(IAltitudeSensor *pAltitudeSensor, unsigned int sensorId = ALT_FIRST_ID);
        void setReportInterval(unsigned long reportInterval);
        void setFilter(Filter *pFilter);
        long getValue() override;        

    private:
        static const unsigned int PRECISION = 100; // Precision 2 digits

        IAltitudeSensor *pAltitudeSensor;
        Filter *pFilter;
        Timer timer;
        unsigned long reportInterval;
        long lastReportValue;
};

#endif
