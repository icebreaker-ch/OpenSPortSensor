#ifndef CONFIG_H
#define CONFIG_H

/**
 * Uncomment this, if you want to use the Hardware Serial interface (RX/TX Pins)
 * on your board to handle the communication between the Arduino and the Receiver.
 * You need a RS232 Inverter Board between the Arduino and the Receiver.
*/
//#define USE_HARDWARE_SERIAL

#ifdef USE_HARDWARE_SERIAL
/**
 * Defines the stream object to be used for HardwareSerial communication
 * (communication via RX/TX pins).
 * Different boards use different objects to provide HardwareSerial communication.
 * Arduino Sparkfun proMicro: Serial1
 * Arduino Mini/Pro Mini: Serial
 * Arduino Nano: Serial
*/
#define HARDWARE_SERIAL_STREAM Serial
//#define HARDWARE_SERIAL_STREAM Serial1
#endif

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

#endif
