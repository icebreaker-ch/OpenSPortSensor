#include "config.h"
#include "NeoGPSSensor.h"

#ifdef USE_HARDWARE_SERIAL
#warning "Configuration problem: Hardware serial already used for receiver"
#endif

NeoGPSSensor::NeoGPSSensor() {
    HARDWARE_SERIAL_STREAM.begin(9600, SERIAL_8N1);
}

void NeoGPSSensor::poll() {
    while (HARDWARE_SERIAL_STREAM.available() > 0) {
        char c = HARDWARE_SERIAL_STREAM.read();
        gps.encode(c);
    }
}

double NeoGPSSensor::getLongitude() {
    return gps.location.isValid() && gps.location.age() < SENSOR_TIMEOUT ? gps.location.lng() : 0;
}

double NeoGPSSensor::getLatitude() {
    return gps.location.isValid() && gps.location.age() < SENSOR_TIMEOUT ? gps.location.lat() : 0;
}

double NeoGPSSensor::getAltitude() {
    return gps.altitude.isValid() && gps.altitude.age() < SENSOR_TIMEOUT ? gps.altitude.meters() : 0;
}

double NeoGPSSensor::getSpeed() {
    return gps.speed.isValid() && gps.speed.age() < SENSOR_TIMEOUT ? gps.speed.kmph() : 0;
}

double NeoGPSSensor::getCourse() {
    return gps.course.isValid() && gps.course.age() < SENSOR_TIMEOUT ? gps.course.deg() : 0;
}
