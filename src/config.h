#ifndef CONFIG_H
#define CONFIG_H

#include "global.h"

/**
 * Uncomment this, if you want to use the Hardware Serial interface (RX/TX Pins)
 * on your board to handle the communication between the Arduino and the Receiver.
 * You need a RS232 Inverter Board between the Arduino and the Receiver.
*/
//#define USE_HARDWARE_SERIAL

#ifndef USE_HARDWARE_SERIAL
/**
 * Defines the pin to be used for SoftrwareSerial communication to the S.Port of the Receiver.
 * No additional Hardware is required, when you use SoftwareSerial.
*/
#define SOFTWARE_SERIAL_PIN 8
#endif

/**
 * Defines the baud rate for the S.Port communication. The default is 57600
 * which should be fine.
*/
#define S_PORT_BAUD 57600

/**
 * Define the Physical ID of the Hub
 * Choose one of the defined IDs which is not used by another sensor in your system.
*/
#define PHYSICAL_ID PHYSICAL_ID11

/**
 * Define, what to use as the analog reference voltage.
 * can be one of:
 * DEFAULT: the default analog reference of 5 volts (on 5V Arduino boards) or 3.3 volts (on 3.3V Arduino boards)
 * INTERNAL: a built-in reference, equal to 1.1 volts on the ATmega168 or ATmega328P and 2.56 volts on the ATmega32U4 and ATmega8 (not available on the Arduino Mega)
 * INTERNAL1V1: a built-in 1.1V reference (Arduino Mega only)
 * INTERNAL2V56: a built-in 2.56V reference (Arduino Mega only)
 * EXTERNAL: the voltage applied to the AREF pin (0 to 5V only) is used as the reference.
*/
#define ANALOG_REFERENCE INTERNAL

/**
 * Defines the reference voltage in [mV]
 * Use INTERNAL_REFERENCE_VOLTAGE or the actual value of the refernce value at AREF.
*/
#define ANALOG_REFERENCE_VOLTAGE INTERNAL_REFERENCE_VOLTAGE

#endif
