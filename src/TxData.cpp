#include <TxData.h>

TxData::TxData(short sensorId, long value, unsigned char type = DATA_FRAME) :
    sensorId(sensorId),
    value(value),
    type(type)
{
}
 
 unsigned char TxData::getChecksum(unsigned char data[])  {
  int crc = data[0];
  for (int i = 1; i < 7; ++i)  {
    crc += data[i];
    crc += crc >> 8;
    crc &= 0xFF;
  }
  return 0XFF - crc;
}

void TxData::getData(unsigned char buffer[]) {
    buffer[0] = type;
    buffer[1] = sensorId & 0xFF;
    buffer[2] = (sensorId >> 8) & 0xFF;
    buffer[3] = value & 0xFF;
    buffer[4] = (value >> 8) & 0xFF;
    buffer[5] = (value >> 16) & 0xFF;
    buffer[6] = (value >> 24) & 0xFF;
    buffer[7] = getChecksum(buffer);
}
