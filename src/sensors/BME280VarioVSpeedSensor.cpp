#include "BME280VarioVSpeedSensor.h"
#include "log.h"

#define READ_SENSOR_INTERVAL 100 //mS
#define UPDATE_INTERVAL 500 // mS
#define MILLISECONDS_PER_SECOND 1000
#define PRECISION 100 // Factor

BME280VarioVSpeedSensor::BME280VarioVSpeedSensor(BME280 &bme280, unsigned int sensorId) :
    Sensor(sensorId),
    bme280(bme280),
    lastMillis(0),
    lastValidAltitude(0),
    currentVSpeed(0),
    pFilter(nullptr) {
}

void BME280VarioVSpeedSensor::setFilter(Filter *pFilter)
{
    this->pFilter = pFilter;
}

long BME280VarioVSpeedSensor::getValue()
{
    unsigned long currentMillis = millis();
    long diffMillis = currentMillis - lastMillis;
    float altitudeRead = bme280.readAltitude();

    if (lastMillis == 0) { // First read
        lastValidAltitude = altitudeRead;        
        currentVSpeed = 0; // Calculation not possible
        lastMillis = currentMillis;
    } else if (diffMillis < UPDATE_INTERVAL) { // Collecting values
        pFilter->addValue(altitudeRead);
    } else { // Send new Value
        pFilter->addValue(altitudeRead);
        float currentValidAltitude = pFilter->getFilteredValue();
        float diffAltitude = currentValidAltitude - lastValidAltitude;
        currentVSpeed = diffAltitude * MILLISECONDS_PER_SECOND / diffMillis;

        LOG("old: ", lastValidAltitude, " current: ", currentValidAltitude, " diff: ", diffAltitude, " vSpeed: ", currentVSpeed, "\n");
        lastMillis = currentMillis;
        lastValidAltitude = currentValidAltitude;
        pFilter->reset();
    }
    return (long)(round(PRECISION * currentVSpeed));
}
