#include "SPortHardwareStream.h"

SPortHardwareStream::SPortHardwareStream() :
    serial(HARDWARE_SERIAL_STREAM) {
}

void SPortHardwareStream::begin(unsigned long speed, byte config) {
    serial.begin(speed, config);
}

void SPortHardwareStream::listen() {
    // Not necessary for hardware serial
}

void SPortHardwareStream::stopListening() {
    // Not necessary for hardware serial
}

int SPortHardwareStream::available() {
    return serial.available();
}

int SPortHardwareStream::read() {
    return serial.read();
}

size_t SPortHardwareStream::write(uint8_t c) {
    return serial.write(c);
}

int SPortHardwareStream::peek() {
    return serial.peek();
}
