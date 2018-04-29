# CS:GO  Wemos | Neopixel game integration

Arduino
========

Assembly
========
### Materials
* Neopixel string
* Wemos board (We are using Wemos D1)
* Micro USB cable

### Wiring
You need to solder three wires from the wemos board to the Neopixel string. Connect 5v to v5, Di to D2 on the board and G to G. Some Neopixels have two data pads DI BI. Solder both to D2.

![alt text](https://i.imgur.com/OKbxjBG.png)

Make sure the direction on the neopixel string is correct:

![alt text](https://i.imgur.com/vEGlM5i.png)

### How to solder
* Make sure the soldering iron is warm.
* Add a tiny bit of solder on the pads on the strip.
* Add solder on the wire.
* Put the wire to the pad and heat with the soldering iron.

If you need more assistance for soldering, this video is recommended:<br>
[![Alt text for your video](https://i.imgur.com/BC29yAS.png)](https://www.youtube.com/watch?v=QzYb9gWQYtc)


Installation
========
### Setup
#### USB Serial driver
To be able to communicate with the Wemos board you will need to install the Serial drivers. On the following link you can find the latest driver:
https://wiki.wemos.cc/downloads

If you have trouble with the MAC driver you can find a later version here that is signed:
https://blog.sengotta.net/signed-mac-os-driver-for-winchiphead-ch340-serial-bridge/

Directly from the manufacturer of the Serial chip:
http://www.wch.cn/download/CH341SER_ZIP.html

#### Install Arduino
Download Arduino ide from here wwww.arduino.cc -> Download -> Arduino IDE (not Online ide).

Interaction
========


**Have fun!**
