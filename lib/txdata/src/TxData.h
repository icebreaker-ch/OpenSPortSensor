#ifndef TX_DATA_H
#define TX_DATA_H

#define DATA_FRAME 0x10

class TxData {
    public:
        TxData(short sensorId, long value, unsigned char type = DATA_FRAME);
        void getData(unsigned char buffer[]);

        static const int LEN = 8;
        static unsigned char const NO_DATA[LEN];

    private:
        unsigned char getChecksum(unsigned char data[]);
        short sensorId;
        long value;
        unsigned char type;
};

#endif