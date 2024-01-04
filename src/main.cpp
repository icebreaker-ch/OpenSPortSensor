#include <Arduino.h>
#include <SoftwareSerial.h>
#include <config.h>
#include <SensorPool.h>
#include <Sensor.h>
#include <SimpleSensor.h>
#include <TxData.h>
#include <SPortWriter.h>
#include <SPortStream.h>

#define START_BYTE 0x7E

#ifdef USE_HARDWARE_SERIAL
  SPortStream *pStream = new SPortStream(&HARDWARE_SERIAL_STREAM);
#else
  SPortStream *pStream = new SPortStream(SOFTWARE_SERIAL_PIN);
#endif

SPortWriter *pSPortWriter;

SensorPool pool = SensorPool(13);

void setup() {
  Serial.begin(9600);

  SimpleSensor *pSensor1 = new SimpleSensor(0x5200);
  SimpleSensor *pSensor2 = new SimpleSensor(0x5210);

  pool.addSensor(pSensor1);
  pool.addSensor(pSensor2);

  pStream->begin(S_PORT_BAUD, SERIAL_8N1);
  pStream->listen();

  pSPortWriter = new SPortWriter(pStream);
}

enum State {
  stateWaitHeader,
  stateWaitPhysicalId,
  stateWriteData
};

static State state = stateWaitHeader;

void loop() {
  unsigned char byte;

  switch (state) {
    case stateWaitHeader:
      if ((pStream->available() && (pStream->readBytes(&byte, 1) == 1) && (byte == START_BYTE))) {
        state = stateWaitPhysicalId;
      }
      break;

    case stateWaitPhysicalId:
      if ((pStream->available() && (pStream->readBytes(&byte, 1) == 1) && (byte == pool.getPhysicalId()))) {
        state = stateWriteData;
      }
      break;

    case stateWriteData:
      pStream->stopListening();
      Sensor *pSensor = pool.getNextSensor();
      TxData data(pSensor->getSensorId(), pSensor->getValue());

      unsigned char bytes[8];
      data.getData(bytes);

      for (int i = 0; i <= 7; ++i) {
        pSPortWriter->write(bytes[i]);
      }

      pStream->listen();
      state = stateWaitHeader;
      break;
  }
}
