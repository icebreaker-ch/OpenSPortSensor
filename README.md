# OpenSPortSensor
Telemetry for *FrSky* Receivers using **S.Port**

The main goals for this project were:
- Provide a software easy to adapt for your own sensors by implementing a simple interface
- Provide a software capable to run on many different arduino hardware
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
<br>whereas using Hardware.Serial is less CPU consuming, than Software-Serial.
<br>However, if you choose, to use Hardware-Serial, you have to invert signals
between the Arduino RX/TX pins and the Receivers S-Port.
<br>For this purpose, I recommend the RS-232 Inverter by Bernd Feiler described here:
[RS-232 Inverter by Bernd Feiler](https://discuss.ardupilot.org/uploads/short-url/sCX6JsKOJ3IDqZxHaSJgylAd1YR.pdf)