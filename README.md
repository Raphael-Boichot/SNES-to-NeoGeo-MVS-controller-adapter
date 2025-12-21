# SNES to NeoGeo MVS controller adapter
A SNES to NeoGeo MVS controller adapter based on Arduino. To be used with a supergun or MVS consolization. The code and pinout come from [this repository](https://github.com/robinhedwards/SNES-to-NeoGeo) from Robin Edwards, so it must works as it, but code needs optimization. The adapter is **not natively AES compatible** (the "not" so includes NeoGeo AES and NeoGeo CD) because the AES DB15 male port is indeed too deep to be used with standard DB15 female connectors.

While currently untested, there is no reason it would not work as it.

PCB designs can be edited with [EasyEDA Standard Edition](https://easyeda.com). Eu citizens are advised to order PCBs at [JLCPCB](https://jlcpcb.com/) to avoid additional prohibitive taxes with customs (taxes paid at order). Just drop the gerber to their site and order with default parameters (the cheapest by default).

## Why ?
Using genuine NeoGeo controllers with a supergun + MVS board stays the best arcade experience. But these controllers are horrendously expensive while the SNES controllers are among the best and most common controller still available. Plus the NeoGeo controllers are surpringly prone to issues with their microswitches and quite difficult to tear down and reassemble. So if you don't fear missing the clicky sound which is part of the NeoGeo experience, go for this SNES adapter.

## Schematic (to be validated)
![](/PCB/Schematic.png)

## PCB (to be validated)
![](/PCB/PCB.png)

## Required parts
- [Project PCB](/PCB/) ordered at [JLCPCB](https://jlcpcb.com/). Just drop the Gerber .zip files on their site and order with default options (any thickness, any color).
- [90° SNES controller port](https://aliexpress.com/item/32828768824.html)
- [90° female DB15 port](https://aliexpress.com/item/1005005998429505.html). As I said, the male socket of AES systems is too deep to fit with regular female DB15 port and I do not find a reference for compatible AES connectors, if any exists.
- [Arduino Nano, any USB type](https://aliexpress.com/item/1005007475356474.html).

## To do
- build and confirm that the pinout from the source repository is OK and the overall design working with a supergun powered in 5.5V.
- optimize the Arduino code as I have no idea if the current version induces a lag or not. I guess using a lookup table would fasten the code.

## Useful sources
- [SNES / Super Famicom Joystick Data format](https://gamesx.com/controldata/snesdat.htm)
- [Super Nintendo controller - how it works](https://learn.adafruit.com/super-nintendo-usb-controller/how-it-works)
