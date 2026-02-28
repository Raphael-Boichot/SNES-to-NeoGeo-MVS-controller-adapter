# Yet another SNES to NeoGeo MVS adapter
A SNES to NeoGeo MVS controller adapter based on Arduino. To be used with a supergun or MVS consolization. The pinout come from [this repository](https://github.com/robinhedwards/SNES-to-NeoGeo) from Robin Edwards. The adapter is **not natively AES compatible** (the "not" so includes NeoGeo AES and NeoGeo CD) because the AES DB15 male port is indeed too deep to be used with standard DB15 female connectors. You can of course replace the DB15 by some third-party butchered extension cord if you want the AES compatibility. SNES, super Nintendo and Super Famicom controllers work with the converter.

PCB designs can be edited with [EasyEDA Standard Edition](https://easyeda.com). Eu citizens are advised to order PCBs at [JLCPCB](https://jlcpcb.com/) to avoid additional prohibitive taxes with customs (taxes paid at order). Just drop the gerber to their site and order with default parameters (the cheapest by default). Each adapter unit should cost you about 7€ of 2026 (PCB, components and shipping included).

Button layout is based on a NeoGeo CD controller because I'm used to it, but is very easy to modify in the code. It was Metal Slug proofed with success.

## Why ?
Using genuine NeoGeo controllers with a supergun + MVS board stays the best "genuine" experience out of owning a cabinet. But these controllers are horrendously expensive now. The next reasonable option with a supergun is to go with the NeoGeo CD controllers, which is a less bit on the pricey side. But if you're real cheap and like tinkering, the SNES controller perfectly does the job of beating some ass in KOF97. So this converter.

## Is there a lag ?
No because the code is faster than the NeoGeo I/O controller circuit and much faster than your brain, even not drunk.

## Schematic
![](/PCB/Schematic.png)

## PCB
![](/PCB/PCB.png)

**All components go on the same side.** The Arduino is programmed to blink the onboard led when an input is dectected because it's cool (and allows testing before connecting to the supergun).

## Some warning before assembly

Before any attempt to solder anything, **TRY THE ARDUINO NANO FIRST**. You must be able to flash it with the [Arduino IDE](https://support.arduino.cc/hc/en-us/articles/360019833020-Download-and-install-Arduino-IDE) out of the bag and it must blink fast for two seconds with the converter installed. On average, 50% of my AliExpress Arduino hauls go directly to the garbage bin (I mean the recycling bin...) because they are just defective, i.e. equipped with a baroque bootloader at best (if any), a fake chip at worst, and are anyway impossible to reflash without a Ph.D. in Aliexpress oddities. Testing before soldering saves you a nervous breakdown and prevents wasting a PCB, a DB15 port, a SNES port and your fucking time because desoldering plastic parts with hot air is just a wasted effort. 

Once assembled, you can power it via USB and test a SNES controller directly, it will flash when an input is entered. If the device makes magic smoke once powered by the supergun, this means that DB15 port was soldered upside down.

## Buttons layout
![](/Button_layout.png)

Based on the NeoGeo CD controller plus autofires placed where I find them the more accurate when playing.

## Required parts
- [Project PCB](/PCB/) ordered at [JLCPCB](https://jlcpcb.com/). Just drop the Gerber .zip files on their site and order with default options (any thickness, any color).
- [90° SNES controller port](https://aliexpress.com/item/32828768824.html). They are normally bent always the same way but just in case look at the seller pictures.
- [90° female DB15 port, regular footprint](https://aliexpress.com/item/1005005998429505.html). As I said, the male socket of AES systems is too deep to fit with regular female DB15 port and I do not find a reference for compatible AES connectors, if any exists.
- [Arduino Nano, any USB type](https://fr.aliexpress.com/item/1005006438510487.html). This seller seems to sell working arduinos...

## Useful resources
- [A similar project because I like to redo what other did](https://github.com/NEO-JAMMA/Neo-Geo_MVS_Projects/tree/main/ControllerAdapter). Honestly my PCB is cooler.
- [SNES / Super Famicom Joystick Data format](https://gamesx.com/controldata/snesdat.htm)
- [Super Nintendo controller - how it works](https://learn.adafruit.com/super-nintendo-usb-controller/how-it-works)
- [Most reliable schematic of a supergun ever found on the internet](http://gc339.free.fr/SuperGun/SG.html)
![supergun wiring](/Supergun_wiring.jpg)

It's basically the [SmallCab deluxe](https://www.smallcab.net/supergun-deluxe-p-2166.html) supergun schematic apart from some minor things.

And yes we European had mandatory direct RGB inputs on our televisions via a SCART socket (Syndicat des Constructeurs d'Appareils Radiorécepteurs et Téléviseurs). Composite and RF signals were just bad science fiction for us. Sadly this format is now obsolete but any TV built in Europe between 1979 and 2016 has it natively.
