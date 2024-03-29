#include "BME280.h"

BME280::BME280(uint8_t address) {
    bme.begin(address);
}

float BME280::readAltitude() {
    return bme.readAltitude(STANDARD_SEALEVEL_PRESSURE);
}

float BME280::readPressure() {
    return bme.readPressure();
}

float BME280::readTemperature() {
    return bme.readTemperature();
}
