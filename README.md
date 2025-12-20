# SNES to NeoGeo MVS controller adapter
A SNES to NeoGeo MVS controller adapter based on Arduino. To be used with a Supergun, not AES compatible. The code and pinout come from [this repository](https://github.com/robinhedwards/SNES-to-NeoGeo) from Robin Edwards, must works as it, but to be optimized. The adapter is not natively AES compatible - which includes NeoGeo and NeoGeo CD - the AES DB15 male port is indeed too deep to be used with standard DB15 female connectors.

## Schematic (to be validated)
![](/PCB/Schematic.png)

## PCB (to be validated)
![](/PCB/PCB.png)

## Required parts
- [Project PCB](/PCB/) ordered at [JLCPCB](https://jlcpcb.com/). Just drop the Gerber .zip files on their site and order with default options.
- [90° SNES controller port](https://aliexpress.com/item/32828768824.html)
- [90° female DB15 port](https://aliexpress.com/item/1005005998429505.html)
- [Arduino Nano, any USB type](https://aliexpress.com/item/1005007475356474.html)

## To do
- build and test the device
- optimize the Arduino code as I have no idea if its current version induces a lag or not.
