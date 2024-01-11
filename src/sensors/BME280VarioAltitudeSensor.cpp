#include "log.h"
#include "BME280VarioAltitudeSensor.h"

#define PRECISION 100.0

BME280VarioAltiudeSensor::BME280VarioAltiudeSensor(BME280 &bme280, int sensorId) :
    Sensor(sensorId),
    bme280(bme280) {
}

long BME280VarioAltiudeSensor::getValue()
{
    float altitude = bme280.readAltitude();
    long result = ((long)(round(PRECISION * altitude)));
    LOG("altitude: ", altitude, " result: ", result, "\n");
    return result;
}
