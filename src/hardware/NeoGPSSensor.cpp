#include "NeoGPSSensor.h"

NeoGPSSensor::NeoGPSSensor() :
    timeout(DEFAULT_TIMEOUT) {
    Serial1.begin(9600, SERIAL_8N1);
}

void NeoGPSSensor::poll() {
    while (Serial1.available() > 0) {
        char c = Serial1.read();
        gps.encode(c);
     }
}

void NeoGPSSensor::setTimeout(unsigned long timeout) {
    this->timeout = timeout;
}

double NeoGPSSensor::getLongitude() {    
    return gps.location.isValid() && gps.location.age() < timeout ? gps.location.lng() : 0;
}

double NeoGPSSensor::getLatitude() {
    return gps.location.isValid() && gps.location.age() < timeout ? gps.location.lat() : 0;
}

double NeoGPSSensor::getAltitude() {
    return gps.altitude.isValid() && gps.altitude.age() < timeout ?  gps.altitude.meters() : 0;
}

double NeoGPSSensor::getSpeed() {
    return gps.speed.isValid() && gps.speed.age() < timeout ? gps.speed.kmph() : 0;
}
