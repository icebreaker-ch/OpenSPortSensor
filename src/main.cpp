#include <Arduino.h>
#include "config.h"
#include "SensorHub.h"
#include "Sensor.h"
#include "SimpleSensor.h"
#include "VoltageSensor.h"
#include "TxData.h"
#include "SPortWriter.h"
#include "SPortStream.h"

#define START_BYTE 0x7E

#ifdef USE_HARDWARE_SERIAL
  static SPortStream *pStream = new SPortStream(&HARDWARE_SERIAL_STREAM);
#else
  static SPortStream *pStream = new SPortStream(SOFTWARE_SERIAL_PIN);
#endif

static SPortWriter *pSPortWriter;
static SensorHub hub = SensorHub(PHYSICAL_ID11);

void setup() {
  Serial.begin(9600); // Debugging output
  analogReference(ANALOG_REFERENCE);


  SimpleSensor *pSensor1 = new SimpleSensor(0x5200);
  SimpleSensor *pSensor2 = new SimpleSensor(0x5210);
  VoltageSensor *pSensor3 = new VoltageSensor(0x5220, A0, 10000, 2200);

  hub.addSensor(pSensor1);
  hub.addSensor(pSensor2);
  hub.addSensor(pSensor3);

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
      if ((pStream->available() && (pStream->readBytes(&byte, 1) == 1) && (byte == hub.getPhysicalId()))) {
        state = stateWriteData;
      }
      break;

    case stateWriteData:
      pStream->stopListening();
      Sensor *pSensor = hub.getNextSensor();
      TxData data(pSensor->getSensorId(), pSensor->getValue());

      unsigned char bytes[TxData::LEN];
      data.getData(bytes);

      for (int i = 0; i < TxData::LEN; ++i) {
        pSPortWriter->write(bytes[i]);
      }

      pStream->listen();
      state = stateWaitHeader;
      break;
  }
}
