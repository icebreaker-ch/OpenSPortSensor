#include "SPortStream.h"

SPortStream::SPortStream(Stream *pStream) :
    isSoftwareStream(false),
    pin(0),
    pStream(pStream)
{
}

SPortStream::SPortStream(int pin) :
    isSoftwareStream(true),
    pin(pin) {
        pStream = new SoftwareSerial(pin, pin, true);
}

void SPortStream::begin(unsigned long speed, byte config) {
    if (isSoftwareStream)
    {
        pinMode(pin, INPUT); // Start with reading mode
        static_cast<SoftwareSerial *>(pStream)->begin(speed);
    } else {
        static_cast<HardwareSerial *>(pStream)->begin(speed, SERIAL_8N1);
    }
}

void SPortStream::listen()
{
    if (isSoftwareStream) {
        pinMode(pin, INPUT);
        static_cast<SoftwareSerial *>(pStream)->listen();
    }
}

void SPortStream::stopListening()
{
    if (isSoftwareStream) {
      pinMode(pin, OUTPUT);
      static_cast<SoftwareSerial *>(pStream)->stopListening();
    }
}

int SPortStream::available()
{
    return pStream->available();
}

int SPortStream::read()
{
    return pStream->read();
}

size_t SPortStream::write(uint8_t c)
{
    return pStream->write(c);
}

int SPortStream::peek()
{
    return pStream->peek();
}
