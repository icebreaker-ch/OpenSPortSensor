#include "BME280VarioAltitudeSensor.h"

#define PRECISION 100.0
//#define DEBUG_VARIO_ALTITUDE

BME280VarioAltiudeSensor::BME280VarioAltiudeSensor(BME280 &bme280, int sensorId) :
    Sensor(sensorId),
    bme280(bme280) {
}

long BME280VarioAltiudeSensor::getValue()
{
    float altitude = bme280.readAltitude();
    long result = ((long)(round(PRECISION * altitude)));

#ifdef DEBUG_VARIO_ALTITUDE
    Serial.print(" altitude: ");
    Serial.print(altitude);
    Serial.print(" ");
    Serial.println(result);
#endif
    return result;
}
