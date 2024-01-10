#include <Arduino.h>
#include "config.h"
#include "SensorHub.h"
#include "Sensor.h"
#include "SimpleSensor.h"
#include "VoltageSensor.h"
#include "BME280.h"
#include "BME280VarioAltitudeSensor.h"
#include "BME280VarioVSpeedSensor.h"
#include "MeanValueFilter.h"
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
  Serial.begin(9600); // For debugging output
    
  analogReference(ANALOG_REFERENCE);

  // Add required sensors here
  SimpleSensor *pSensor1 = new SimpleSensor(0x5200);
  VoltageSensor *pVoltageSensor = new VoltageSensor(0x5210, A0, 10000, 2200);

  // Vario
  BME280 *pBme = new BME280();
  BME280VarioAltiudeSensor *pAltSensor = new BME280VarioAltiudeSensor(*pBme);
  BME280VarioVSpeedSensor *pVSpeedSensor = new BME280VarioVSpeedSensor(*pBme);
  Filter *pFilter = new MeanValueFilter(20);
  pVSpeedSensor->setFilter(pFilter);

  hub.addSensor(pSensor1);
  hub.addSensor(pVoltageSensor);
  hub.addSensor(pAltSensor);
  hub.addSensor(pVSpeedSensor);

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
