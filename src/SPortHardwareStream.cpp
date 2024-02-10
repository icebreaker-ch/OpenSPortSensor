#include "SPortHardwareStream.h"

#ifdef USE_HARDWARE_SERIAL

SPortHardwareStream::SPortHardwareStream(HardwareSerial *pStream) :
    pStream(pStream) {
}

void SPortHardwareStream::begin(unsigned long speed, byte config) {
    pStream->begin(speed, config);
}

void SPortHardwareStream::listen() {
    // Not necessary for hardware serial
}

void SPortHardwareStream::stopListening() {
    // Not necessary for hardware serial
}

int SPortHardwareStream::available() {
    return pStream->available();
}

int SPortHardwareStream::read() {
    return pStream->read();
}

size_t SPortHardwareStream::write(uint8_t c) {
    return pStream->write(c);
}

int SPortHardwareStream::peek() {
    return pStream->peek();
}

#endif