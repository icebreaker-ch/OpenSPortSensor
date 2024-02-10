#include "SPortSoftwareStream.h"

#ifndef USE_HARDWARE_SERIAL
#include <SoftwareSerial.h>

SPortSoftwareStream::SPortSoftwareStream(int pin) :
    pin(pin) {
    pStream = new SoftwareSerial(pin, pin, true);
}

void SPortSoftwareStream::begin(unsigned long speed, byte config) {
    pinMode(pin, INPUT); // Start with reading mode
    pStream->begin(speed);
}

void SPortSoftwareStream::listen() {
    pinMode(pin, INPUT);
    pStream->listen();
}

void SPortSoftwareStream::stopListening() {
    pinMode(pin, OUTPUT);
    pStream->stopListening();
}

int SPortSoftwareStream::available() {
    return pStream->available();
}

int SPortSoftwareStream::read() {
    return pStream->read();
}

size_t SPortSoftwareStream::write(uint8_t c) {
    return pStream->write(c);
}

int SPortSoftwareStream::peek() {
    return pStream->peek();
}

#endif