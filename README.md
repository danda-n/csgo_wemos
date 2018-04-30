# CS:GO  Wemos | Neopixel game integration

Contents
========
* Introduction
* Assembly
* Installation
* Interaction

Introduction
========
This is a project for enhancing your gameplay in Counter Strike: Global Offensive using NeoPixels ambient lights for bomb defusal. The way this works is we have 40 LEDS that represent bomb timer and give you ability to decide your chances in winning the round and successfuly defusing the bomb. As soon as bomb is planted, the LEDs start to tick down in **green** color, which means the defuse is still possible without defuse kit. As soon as the color changes to **orange**, defuse is only possible with the kit and when it changes to **red**, run away to save your weapon.

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
[![Alt text for your video](https://i.imgur.com/7l257sD.png)](https://www.youtube.com/watch?v=QzYb9gWQYtc)

Installation
========

#### Install Arduino
Download Arduino ide from here wwww.arduino.cc -> Download -> Arduino IDE (not Online ide).

#### Install ESP8266 Board specifications
Start Arduino and proceed to preferences window (Files -> Preferences).
Enter the following line into Additional Board manager URLs field:

    http://arduino.esp8266.com/stable/package_esp8266com_index.json

![alt text](https://i.imgur.com/fWHM0U0.png)

Open Boards Manager from Tools > Board menu and install ESP8266 platform (and remember to select board in the selection)
![alt text](https://i.imgur.com/U9YVay7.png)

More info available [here](https://github.com/esp8266/Arduino).7

#### Install Adafruit NeoPixel library
Proceed to Sketch > Include Library > Manage Libraries...

![alt text](https://i.imgur.com/6dNgG3J.png)

Python
========
Install Python 2.7 [here](https://www.python.org/download/releases/2.7/).

Install PySerial 2.7 from [here](https://sourceforge.net/projects/pyserial/files/pyserial/2.7/). Unpack the file, navigate via command prompt to the folder directory and run:

    python setup.py install

#### USB Serial driver
To be able to communicate with the Wemos board you will need to install the Serial drivers. On the following link you can find the latest driver:
https://wiki.wemos.cc/downloads

If you have trouble with the MAC driver you can find a later version here that is signed:
https://blog.sengotta.net/signed-mac-os-driver-for-winchiphead-ch340-serial-bridge/

Directly from the manufacturer of the Serial chip:
http://www.wch.cn/download/CH341SER_ZIP.html

Uploading code
========

**1.** First step is to upload code to Arduino for NeoPixel integration from this file:
   
     csgointegrationNeoPixels.ino
     
**1.1** To upload the code, you click the button *Upload*

![alt text](https://i.imgur.com/a9tAW2L.png)

And wait until the code is fully uploaded!
![alt text](https://i.imgur.com/9HPNpTV.png)
   
**Remember to properly select Wemos board in arduino, as well as correct port when you plug the board in!**

**2.** Then upload the code to Python using this file:
    
    CSGoArduino.py
    
And execute it following Run -> Run Module (F5).
![alt text](https://i.imgur.com/PjPA6nV.png)

### NOTE
Be careful when re-uploading code and/or restarting the python server when you get error about ports as they may contradict eachother from Arduino and Python. Python server has to be **off** and if the upload still does not work, plug it out and back in and try uploading again.

Interaction
========
Following steps explain how to use and how NeoPixels work.

* Start CS:GO.
* Plug in the Wemos board.
* Start Python server.
* Observe results and play away.


**Have fun!**
