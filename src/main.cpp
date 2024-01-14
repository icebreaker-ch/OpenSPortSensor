#include <Arduino.h>
#include <TxData.h>
#include "log.h"
#include "config.h"
#include "SensorHub.h"
#include "Sensor.h"
#include "SimpleSensor.h"
#include "VoltageSensor.h"
#include "BME280.h"
#include "AltitudeSensor.h"
#include "VerticalSpeedSensor.h"
#include "MeanValueFilter.h"
#include "SPortWriter.h"
#include "SPortStream.h"

#define START_BYTE 0x7E

#ifdef USE_HARDWARE_SERIAL
  static SPortStream *pStream = new SPortStream(&HARDWARE_SERIAL_STREAM);
#else
  static SPortStream *pStream = new SPortStream(SOFTWARE_SERIAL_PIN);
#endif

static SPortWriter *pSPortWriter;
static SensorHub hub = SensorHub(PHYSICAL_ID);

void setup() {
#ifdef LOGGING_ON
  Serial.begin(9600); // For debugging output
#endif
    
  analogReference(ANALOG_REFERENCE);

  // Add required sensors here
  // Test sensors
  //SimpleSensor *pSensor1 = new SimpleSensor(0x5200);

  // Voltage Sensors
  VoltageSensor *pVoltageSensor = new VoltageSensor(A0, 15000, 3300);
  pVoltageSensor->setReportInterval(500);
  pVoltageSensor->setFilter(new MeanValueFilter());

  // Vario
  IAltitudeSensor *pBme280 = new BME280();
  AltiudeSensor *pAltSensor = new AltiudeSensor(pBme280);
  pAltSensor->setReportInterval(500);
  pAltSensor->setFilter(new MeanValueFilter());
  VerticalSpeedSensor *pVerticalSpeedSensor = new VerticalSpeedSensor(pBme280);
  pVerticalSpeedSensor->setReportInterval(500);
  pVerticalSpeedSensor->setFilter(new MeanValueFilter());

  //hub.addSensor(pSensor1);
  hub.addSensor(pVoltageSensor);
  hub.addSensor(pAltSensor);
  hub.addSensor(pVerticalSpeedSensor);

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
