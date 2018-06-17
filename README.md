# matrixNecklace


Index
-----

* [Introduction](#introduction)
* [Building and uploading](#building-and-uploading)
* [Planned features](#planned-features)
* [To Do](#to-do)
* [Datasheets](#datasheets)


Introduction
------------

matrixNecklace is a simple, customizable necklace, based on an AtTiny2313a and a 8x8 dot LED matrix.

The very first idea came from [furrtek][0]'s mind, called **jewelmatrix**. You can find his project on [his website][1](french).

I wanted to improve the thing and add a few options, like a rechargeable Li-Ion battery (instead of the coin cell furrtek used) and a cross-platform tool to add custom patterns on the fly, without the need to rebuild and flash the attiny every time.


Building and uploading
----------------------

In order to build the firmware, make sure that your programmer is connected to the chip following the [datasheet](#datasheets). You may edit the following line of the makefile if you don't use an [`usbasp`][2] programmer:
``` makefile
# Programming hardware
AVRDUDE_PROGRAMMER = usbasp
```


Then, run the following commands in a linux shell:
```
make
make upload
```

That's it!


Planned features
----------------

* AtTiny48/88 version
* USB flash/upload-(With custom bootloader)


To Do
-----

* Correct pinout/registers match


Datasheets
----------

Here are the direct link to the datasheets (.pdf) for the various AVR chips that can be used in this project.

* ATtiny2313: [microchip website][10] ([mirror][11])
* ATtiny2313a/4313: [microchip website][12] ([mirror][13])


NB1: The ATtinys 2313, 2313a and 4313 have the same pinout and can be substituted to each other.

NB2: The proposed mirror is on my personnal website.



  [0]: https://github.com/furrtek/
  [1]: http://furrtek.free.fr/?a=jewelmatrix
  [2]: http://www.fischl.de/usbasp/

  [10]: http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-2543-AVR-ATtiny2313_Datasheet.pdf
  [11]: https://taz8du29.fr/matrixNecklace/Atmel-2543-AVR-ATtiny2313_Datasheet.pdf

  [12]: http://ww1.microchip.com/downloads/en/DeviceDoc/doc8246.pdf
  [13]: https://taz8du29.fr/matrixNecklace/ATtiny2313A_4313.pdf
