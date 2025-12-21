# SNES to NeoGeo MVS controller adapter
A SNES to NeoGeo MVS controller adapter based on Arduino. To be used with a Supergun, not AES compatible. The code and pinout come from [this repository](https://github.com/robinhedwards/SNES-to-NeoGeo) from Robin Edwards, so it must works as it, but code needs optimization. The adapter is **not natively AES compatible** (the "not" so includes NeoGeo AES and NeoGeo CD) because the AES DB15 male port is indeed too deep to be used with standard DB15 female connectors.

While currently untested, there is no reason it would not work as it.

## Schematic (to be validated)
![](/PCB/Schematic.png)

## PCB (to be validated)
![](/PCB/PCB.png)

## Required parts
- [Project PCB](/PCB/) ordered at [JLCPCB](https://jlcpcb.com/). Just drop the Gerber .zip files on their site and order with default options.
- [90° SNES controller port](https://aliexpress.com/item/32828768824.html)
- [90° female DB15 port](https://aliexpress.com/item/1005005998429505.html). As I said, the male socket of AES systems is too deep to fit with regular female DB15 port and I do not find a reference for compatible AES connectors, if any exists.
- [Arduino Nano, any USB type](https://aliexpress.com/item/1005007475356474.html).

## To do
- build and confirm that the pinout from the source repository is OK and the PCB working
- optimize the Arduino code as I have no idea if its current version induces a lag or not. I guess using a lookup table would fasten the code.
