# Welcome to OpenSPortSensor
Telemetry for *FrSky* RC Receivers using the **S.Port** interface.

The main goals for this project were:
- Provide a software easy to adapt for your own sensors by implementing a simple interface
- Support different *Arduino* boards by using high level libraries for communication only
- Support Hardware- and Software-Serial interfaces
- Supply a set of standard sensors for e.g. voltage and current measurement
## Hardware requirements
This software has been successfully tested on different boards:
- Arduino Sparkfun Pro Micro
- Arduino Nano
- Arduino Pro Mini Atmega 328
- Arduino Pro Mini Atmega 168
## Software- and Hardware-Serial
The connection to the Receiver's S.Port can be done by Software- (by a digital pin) or Hardware-Serial (by RX/TX),
whereas using Hardware-Serial is less CPU consuming, than Software-Serial.
However, if you choose, to use Hardware-Serial, you have to invert signals
between the *Arduino* RX/TX pins and the Receivers S-Port and combine the RX/TX channels to use only one wire.
For this purpose, I recommend the RS-232 Inverter by Bernd Feiler described here:
[RS-232 Inverter by Bernd Feiler](https://discuss.ardupilot.org/uploads/short-url/sCX6JsKOJ3IDqZxHaSJgylAd1YR.pdf)
### Differences between Hardware- and Software-Serial
| Hardware Serial               | Software Serial                       |
| -                             | -                                     |
| Duplex communication          | Simplex communication                 |
| RX and TX on 2 different pins | RX and TX can use the same pin number |
| RS-232 Inverter required      | Inverting can be handled by software  |
| CPU load low                  | CPU load higher                       |