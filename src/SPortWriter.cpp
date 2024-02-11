#include "SPortWriter.h"

SPortWriter::SPortWriter(Stream *pStream) :
    pStream(pStream) {
}

void SPortWriter::write(unsigned char byte) {
    if (byte == 0x7E) {
        pStream->write(0x7D);
        pStream->write(0x5E);
    } else if (byte == 0x7D) {
        pStream->write(0x7D);
        pStream->write(0x5D);
    } else
        pStream->write(byte);
}

void SPortWriter::write(unsigned char const buffer[], size_t len) {
    for (size_t i = 0; i < len; ++i) {
        write(buffer[i]);
    }
}
