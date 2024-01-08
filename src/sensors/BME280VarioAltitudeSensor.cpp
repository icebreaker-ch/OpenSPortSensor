#include "BME280VarioAltitudeSensor.h"

BME280VarioAltiudeSensor::BME280VarioAltiudeSensor(BME280 &bme280, int sensorId) :
    Sensor(sensorId),
    bme280(bme280) {
}

long BME280VarioAltiudeSensor::getValue()
{
    float altitude = bme280.readAltitude();
    return (long)(10 * altitude);
}
