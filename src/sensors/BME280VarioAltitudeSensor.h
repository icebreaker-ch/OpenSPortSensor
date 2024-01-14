#ifndef BME280_VARIO_ALTITUDE_SENSOR_H
#define BME280_VARIO_ALTITUDE_SENSOR_H

#include "global.h"
#include "Sensor.h"
#include "BME280.h"
#include "Filter.h"

class BME280VarioAltiudeSensor : public Sensor {
    public:
        BME280VarioAltiudeSensor(BME280 *pBme280, unsigned int sensorId = ALT_FIRST_ID);
        void setReportInterval(unsigned long reportInterval);
        void setFilter(Filter *pFilter);
        long getValue();        

    private:
        static const unsigned int PRECISION = 100; // Precision 2 digits

        BME280 *pBme280;
        unsigned long reportInterval;
        unsigned long lastReportMillis;
        long lastReportValue;
        Filter *pFilter;
};

#endif
