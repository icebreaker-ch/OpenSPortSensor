#include <Arduino.h>
#include <TxData.h>
#include <List.h>
#include "log.h"
#include "config.h"
#include "SensorHub.h"
#include "Sensor.h"
#include "TestSensor.h"
#include "VoltageSensor.h"
#include "CurrentSensor.h"
#include "BME280.h"
#include "AltitudeSensor.h"
#include "VerticalSpeedSensor.h"
#ifdef GPS_SENSOR
#include "NeoGPSSensor.h"
#include "GPSCourseSensor.h"
#include "GPSPositionSensor.h"
#include "GPSAltitudeSensor.h"
#include "GPSSpeedSensor.h"
#endif
#include "IPollingDevice.h"
#include "NullFilter.h"
#include "MeanValueFilter.h"
#include "SPortHardwareStream.h"
#include "SPortSoftwareStream.h"
#include "SPortWriter.h"

#define START_BYTE 0x7E

#ifdef USE_HARDWARE_SERIAL
static ISPortStream *pStream = new SPortHardwareStream();
#else
static ISPortStream *pStream = new SPortSoftwareStream(SOFTWARE_SERIAL_PIN);
#endif

static SPortWriter *pSPortWriter;
static SensorHub hub(PHYSICAL_ID);
static List<IPollingDevice *> pollingDevices;

static void addSensors() {
#ifdef TEST_SENSOR
    // Add required sensors here
    // Test Sensor
    // ===========
    TestSensor *pTestSensor = new TestSensor(0x5200);
    hub.addSensor(pTestSensor);
#endif

#ifdef VOLTAGE_SENSOR
    // Voltage Sensor
    // ==============
    VoltageSensor *pVoltageSensor = new VoltageSensor(A0, 15000, 3300);
    pVoltageSensor->setFilter(new MeanValueFilter());
    pVoltageSensor->setReportInterval(STANDARD_INTERVAL);
    hub.addSensor(pVoltageSensor);
#endif

#ifdef CURRENT_SENSOR
    // Current Sensor
    // ==============
    CurrentSensor *pCurrentSensor = new CurrentSensor(A2, 1280.0, 25.0);
    pCurrentSensor->setFilter(new MeanValueFilter());
    pCurrentSensor->setReportInterval(STANDARD_INTERVAL);
    hub.addSensor(pCurrentSensor);
#endif

#ifdef VARIO_SENSOR
    // Vario
    // =====
    // Vario: Altitude
    IAltitudeSensor *pBme280 = new BME280();
    AltiudeSensor *pAltSensor = new AltiudeSensor(pBme280);
    pAltSensor->setFilter(new MeanValueFilter());
    pAltSensor->setReportInterval(STANDARD_INTERVAL);
    hub.addSensor(pAltSensor);
    // Vario: Vertical speed
    VerticalSpeedSensor *pVerticalSpeedSensor = new VerticalSpeedSensor(pBme280);
    pVerticalSpeedSensor->setFilter(new MeanValueFilter());
    pVerticalSpeedSensor->setReportInterval(STANDARD_INTERVAL);
    hub.addSensor(pVerticalSpeedSensor);
#endif

 #ifdef GPS_SENSOR
    // GPS
    NeoGPSSensor *pNeoGPSSensor = new NeoGPSSensor();
    pollingDevices.add(pNeoGPSSensor); // register as polling device for feeding GPS data
    // GPS: Position Sensor
    GPSPositionSensor *pLatitudeLongitudeSensor = new GPSPositionSensor(pNeoGPSSensor);
    hub.addSensor(pLatitudeLongitudeSensor);

    // GPS: Altitude Sensor
    GPSAltitudeSensor *pGPSAltitudeSensor = new GPSAltitudeSensor(pNeoGPSSensor);
    hub.addSensor(pGPSAltitudeSensor);

    // GPS: Speed Sensor
    GPSSpeedSensor *pGPSSpeedSensor = new GPSSpeedSensor(pNeoGPSSensor);
    hub.addSensor(pGPSSpeedSensor);

    // GPS: Course Sensor
    GPSCourseSensor *pGPSCourseSensor = new GPSCourseSensor(pNeoGPSSensor);
    hub.addSensor(pGPSCourseSensor);
#endif
}

void setup() {
#ifdef LOGGING_ON
    Serial.begin(9600); // For debugging output
#endif

    pinMode(LED_PIN, OUTPUT);
    analogReference(ANALOG_REFERENCE);
    addSensors();

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

    // Hanlde polling devices in every loop
    for (List<IPollingDevice *>::Iterator it = pollingDevices.begin(); it != pollingDevices.end(); ++it) {
        (*it)->poll();
    }

    switch (state) {
    case stateWaitHeader:
        digitalWrite(LED_PIN, HIGH);
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
        digitalWrite(LED_PIN, LOW);

        pStream->stopListening();
        Sensor *pSensor = hub.getNextSensor();
        unsigned char bytes[TxData::LEN];
        TxData data(pSensor->getSensorId(), pSensor->getValue());
        data.getData(bytes);
        pSPortWriter->write(bytes, TxData::LEN);

        pStream->listen();
        state = stateWaitHeader;
        break;
    }
}
