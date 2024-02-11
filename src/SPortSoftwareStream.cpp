#include "SPortSoftwareStream.h"
#include <SoftwareSerial.h>

SPortSoftwareStream::SPortSoftwareStream(int pin) :
    pin(pin),
    serial(pin, pin, true) {
}

void SPortSoftwareStream::begin(unsigned long speed, byte config) {
    pinMode(pin, INPUT); // Start with reading mode
    serial.begin(speed);
}

void SPortSoftwareStream::listen() {
    pinMode(pin, INPUT);
    serial.listen();
}

void SPortSoftwareStream::stopListening() {
    pinMode(pin, OUTPUT);
    serial.stopListening();
}

int SPortSoftwareStream::available() {
    return serial.available();
}

int SPortSoftwareStream::read() {
    return serial.read();
}

size_t SPortSoftwareStream::write(uint8_t c) {
    return serial.write(c);
}

int SPortSoftwareStream::peek() {
    return serial.peek();
}
