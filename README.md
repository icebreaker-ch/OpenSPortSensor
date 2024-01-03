# OpenSPortSensor
Telemetry for *FrSky* Receivers using the **S.Port** interface.

The main goals for this project were:
- Provide a software easy to adapt for your own sensors by implementing a simple interface
- Provide a software capable to run on many different *Arduino* hardware
- Provide a software to support Software- and Hardware Serial interfaces
- Supply a set of standard sensors for e.g. voltage and current measurement
## Create your own sensors
To create your own sensor, you have to write an implementation (inheritance) of the *Sensor* class.
## Hardware requirements
This software has been successfully tested on different hardware:
- Arduino Pro Micro
- Arduino Nano
- Arduino Mini
## Software- and Hardware-Serial
The connection to the Receivers S.Port can be done by Software- (by a digital pin) or Hardware-Serial (by RX/TX),
<br>whereas using Hardware-Serial is less CPU consuming, than Software-Serial.
<br>However, if you choose, to use Hardware-Serial, you have to invert signals
between the *Arduino* RX/TX pins and the Receivers S-Port and combine the RX/TX channels to use only one wire.
<br>For this purpose, I recommend the RS-232 Inverter by Bernd Feiler described here:
[RS-232 Inverter by Bernd Feiler](https://discuss.ardupilot.org/uploads/short-url/sCX6JsKOJ3IDqZxHaSJgylAd1YR.pdf)
### Differences between Hardware- and Software-Serial
| Hardware Serial               | Softwre Serial                        |
| --------------------          | ----------------                      |
| Duplex communication          | SImplex communication                 |
| RX and TX on 2 different pins | RX and TX can use the same pin number |
| RS-232 Inverter required      | Inverting by software                 |
| CPU load low                  | CPU load higher                       |