#ifndef S_PORT_WRITER_H
#define S_PORT_WRITER_H

#include <Stream.h>

class SPortWriter {
    public:
        explicit SPortWriter(Stream *pStream);
        void write(unsigned char const buffer[], size_t len);

    private:
        void write(unsigned char byte);
        Stream *pStream;
};

#endif