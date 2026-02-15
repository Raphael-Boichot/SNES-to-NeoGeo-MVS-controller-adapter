# SNES to NeoGeo MVS controller adapter
A SNES to NeoGeo MVS controller adapter based on Arduino. To be used with a supergun or MVS consolization. The pinout come from [this repository](https://github.com/robinhedwards/SNES-to-NeoGeo) from Robin Edwards. The adapter is **not natively AES compatible** (the "not" so includes NeoGeo AES and NeoGeo CD) because the AES DB15 male port is indeed too deep to be used with standard DB15 female connectors. You can of course replace the DB15 by some third-party butchered extension cord if you want the AES compatibility.

PCB designs can be edited with [EasyEDA Standard Edition](https://easyeda.com). Eu citizens are advised to order PCBs at [JLCPCB](https://jlcpcb.com/) to avoid additional prohibitive taxes with customs (taxes paid at order). Just drop the gerber to their site and order with default parameters (the cheapest by default).

Button layout is based on a NeoGeo CD controller because I'm used to it, but is very easy to modify in the code. It was Metal Slug proofed with success.

## Why ?
Using genuine NeoGeo controllers with a supergun + MVS board stays the best "genuine" experience out of owning a cabinet. But these controllers are horrendously expensive now. 

The reasonable option with a supergun is to go with the NeoGeo CD controllers, a less bit on the pricey side, still doing the job according to NeoGeo players.

But I must be honest, I always found the NeoGeo CD controllers quite average (mushy push buttons with annoying "plok" sound) and imprecise (the microswitches are cool but joystick is too soft, it's easy to miss a given direction) contrary to the SNES controller which is 100% accurate in any push. So the converter.

## Is there a lag ?
Yes of course, about 1/4 to 1/3 of a 60 Hz frame. Joke apart: none because code is faster than the NeoGeo I/O controller circuit and much faster than your brain.

## Schematic
![](/PCB/Schematic.png)

## PCB
![](/PCB/PCB.png)

All components go on the same side. The Arduino is programmed to flash the onboard led when an input is dectected because it's cool.

## Buttons layout
![](/Button_layout.png)

Based on the NeoGeo CD controller plus autofires placed where I find them the more accurate when playing.

## Required parts
- [Project PCB](/PCB/) ordered at [JLCPCB](https://jlcpcb.com/). Just drop the Gerber .zip files on their site and order with default options (any thickness, any color).
- [90° SNES controller port](https://aliexpress.com/item/32828768824.html)
- [90° female DB15 port](https://aliexpress.com/item/1005005998429505.html). As I said, the male socket of AES systems is too deep to fit with regular female DB15 port and I do not find a reference for compatible AES connectors, if any exists.
- [Arduino Nano, any USB type](https://aliexpress.com/item/1005007475356474.html).

## Useful sources
- [A similar project because I like to redo what other did](https://github.com/NEO-JAMMA/Neo-Geo_MVS_Projects/tree/main/ControllerAdapter). Honestly my PCB is cooler.
- [SNES / Super Famicom Joystick Data format](https://gamesx.com/controldata/snesdat.htm)
- [Super Nintendo controller - how it works](https://learn.adafruit.com/super-nintendo-usb-controller/how-it-works)
- [Most reliable schematic of a supergun ever found on the internet](http://gc339.free.fr/SuperGun/SG.html)
![supergun wiring](/Supergun_wiring.jpg)

It's basically the [SmallCab deluxe](https://www.smallcab.net/supergun-deluxe-p-2166.html) supergun schematic apart from some minor things.

And yes we European had mandatory direct RGB inputs on our televisions via a SCART socket (Syndicat des Constructeurs d'Appareils Radiorécepteurs et Téléviseurs). Composite and RF signals were just bad science fiction for us. Sadly this format is now obsolete but any TV built in Europe between 1979 and 2016 has it natively.
