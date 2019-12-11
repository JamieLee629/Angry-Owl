# How to Set Up the MBed Speaker with Class-D Amp to Play WAV files

## Parts List
- mbed
- Speaker
- [Class-D Amp](https://os.mbed.com/components/TPA2005D1-Class-D-Audio-Amp/)
- [MicroSD Card Breakout Boards](https://www.sparkfun.com/products/544)
- SD Card

## Instructions
- Wire up the Speaker with the Class-D Amp to the mbed. For instructions on how to connect the Speaker and Class-D Amp, click 
[here](https://os.mbed.com/components/TPA2005D1-Class-D-Audio-Amp/) and scroll down to the Wiring section.
- Connect the MicroSD Card Breakout Board to the mbed. An example demo to get started with the microSD card can be found 
[here](https://os.mbed.com/cookbook/SD-Card-File-System).

### Wiring Instructions for MicroSD Breakout Board

| MicroSD Breakout | mbed              |
|------------------|-------------------|
| CS               | 8 (DigitalOut cs) |
| DI               | 5 (SPI mosi)      |
| VCC              | VOUT              |
| SCK              | 7 (SPI sclk)      |
| GND              | GND               |
| DO               | 6 (SPI miso)      |
| CD               |                   |
*** Warning
Note that VCC is 3.3V from mbed's VOUT pin. Do not use 5V from mbed's VU pin. 
5V power will damage the SD card. 
VOUT and VU are adjacent pins on some mbed platforms, 
so double check the jumper wire!

- Insert SD Card with desired `.WAV` files pre-loaded onto the card.
- Import the [.WAV player demo code](https://github.com/JamieLee629/Angry-Owl/tree/master/wav-player-demo-code) onto the
 online mbed compiler. Replace the file name with your `.WAV` file name. and compile. Load the bin file that results 
 from a successful compilation onto the mbed.
- Start the MBed and hear your sound play.

### Troubleshooting
If your sound comes out distorted and slow, try changing the spi frequency. In this project,
the spi frequency is set to 8 MHz.
