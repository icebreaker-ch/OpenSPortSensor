#ifndef CONFIG_H
#define CONFIG_H

/**
 * Uncomment this, if you want to use the Hardware Serial interface (RX/TX Pins)
 * on your board to handle the communication between the Arduino and the Receiver.
 * You need a RS232 Inverter Board between the Arduino and the Receiver.
*/
#define USE_HARDWARE_SERIAL

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
