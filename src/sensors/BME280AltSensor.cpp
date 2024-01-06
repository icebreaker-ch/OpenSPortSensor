#include <Adafruit_BME280.h>
#include "Sensor.h"
#include "BME280AltSensor.h"

#define STANDARD_SEALEVEL_PRESSURE 1013.25

BME280AltSensor::BME280AltSensor(int sensorId, uint8_t address) :
    Sensor(sensorId) {
    bme.begin(address);
}

long BME280AltSensor::getValue()
{
    float altitude = bme.readAltitude(STANDARD_SEALEVEL_PRESSURE);
    return (long)(100 * altitude);
}
