#include "BME280VarioVSpeedSensor.h"

//#define DEBUG_VARIO_VSPEED
#define READ_INTERVAL 1000 // mS

BME280VarioVSpeedSensor::BME280VarioVSpeedSensor(BME280 &bme280, int sensorId) :
    Sensor(sensorId),
    bme280(bme280),
    lastMillis(0),
    lastAltitude(0),
    currentResult(0) {
}

long BME280VarioVSpeedSensor::getValue()
{
    if (lastMillis > 0) {
        unsigned long currentMillis = millis();
        long diffMillis = currentMillis - lastMillis;
        if (diffMillis > READ_INTERVAL) {
            float currentAltitude = bme280.readAltitude();
            if (lastAltitude > 0) {
                float diffAltitude = currentAltitude - lastAltitude;
                float vSpeed = diffAltitude * 1000 / diffMillis;
#ifdef DEBUG_VARIO_VSPEED
                Serial.print("old: ");
                Serial.print(lastAltitude);
                Serial.print(" new: ");
                Serial.print(currentAltitude);
                Serial.print(" diff: ");
                Serial.print(diffAltitude);
                Serial.print(" result: ");
                Serial.println((long)(round(100 * vSpeed)));
#endif
                currentResult = (long)(round(100 * vSpeed));
                lastMillis = currentMillis;
            }
            lastAltitude = currentAltitude;
        }
    } else
        lastMillis = millis();
    return currentResult;
}
