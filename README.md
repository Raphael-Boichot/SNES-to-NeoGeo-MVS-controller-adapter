# SNES to NeoGeo MVS controller adapter
A SNES to NeoGeo MVS controller adapter based on Arduino. To be used with a supergun or MVS consolization. The pinout come from [this repository](https://github.com/robinhedwards/SNES-to-NeoGeo) from Robin Edwards. The adapter is **not natively AES compatible** (the "not" so includes NeoGeo AES and NeoGeo CD) because the AES DB15 male port is indeed too deep to be used with standard DB15 female connectors.

PCB designs can be edited with [EasyEDA Standard Edition](https://easyeda.com). Eu citizens are advised to order PCBs at [JLCPCB](https://jlcpcb.com/) to avoid additional prohibitive taxes with customs (taxes paid at order). Just drop the gerber to their site and order with default parameters (the cheapest by default).

Button layout is based on a NeoGeo CD controller because I'm used to it, but is very easy to modify in the code.

## Why ?
Using genuine NeoGeo controllers with a supergun + MVS board stays the best arcade experience. But these controllers are horrendously expensive while the SNES controllers are among the best and most common controller still available. Plus the NeoGeo controllers are surpringly prone to issues with their microswitches and quite difficult to tear down and reassemble. So if you don't fear missing the clicky sound which is part of the NeoGeo experience, go for this SNES adapter.

## Schematic
![](/PCB/Schematic.png)

## PCB
![](/PCB/PCB.png)

## Buttons layout
![](/Button_layout.png)

## Required parts
- [Project PCB](/PCB/) ordered at [JLCPCB](https://jlcpcb.com/). Just drop the Gerber .zip files on their site and order with default options (any thickness, any color).
- [90° SNES controller port](https://aliexpress.com/item/32828768824.html)
- [90° female DB15 port](https://aliexpress.com/item/1005005998429505.html). As I said, the male socket of AES systems is too deep to fit with regular female DB15 port and I do not find a reference for compatible AES connectors, if any exists.
- [Arduino Nano, any USB type](https://aliexpress.com/item/1005007475356474.html).

## Useful sources
- [A similar project because I like to redo what other did](https://github.com/NEO-JAMMA/Neo-Geo_MVS_Projects/tree/main/ControllerAdapter)
- [SNES / Super Famicom Joystick Data format](https://gamesx.com/controldata/snesdat.htm)
- [Super Nintendo controller - how it works](https://learn.adafruit.com/super-nintendo-usb-controller/how-it-works)
- [Most reliable schematic of a supergun ever found on the internet](http://gc339.free.fr/SuperGun/SG.html)
![supergun wiring](/Supergun_wiring.jpg)

And yes we European had mandatory direct RGB inputs on our televisions via a SCART socket (Syndicat des Constructeurs d'Appareils Radiorécepteurs et Téléviseurs). Composite and RF signals were just bad science fiction for us. Sadly this format is now obsolete but any TV built in Europe between 1979 and 2016 has it natively.
