# IoT Challenge II
Implement a simple communication protocol that transmits data between 2 BBC Micro:bit devices, using GPIOs.

**Author**: Mariyam Yasmeen (S1800367) & Ismath Ibrahim (S1900094)\
**Batch**: BSc (Hons) Computer Science Jan 2019\
**Project Name**: Flappy Bird with a scoreboard\
**Created Date**: March 2020\
**Description**: The game flappy bird reinvented for a microbit with communication\
in order to show the real time score using a second microbit


## Introduction  
This is a simple game that resembles the original flappy bird game for mobile, except,\
this game's world does not have gravity effecting gameplay. The bird has to be directed \
using the A and B buttons. The second microbit allows the player to see his real-time\
score which is what makes games like this popular. The same logic can be used for\
any game or application using two microbits, where you can have one of them dedicated\
to showing the real-time score. 

## Before we begin, lets get our gear ready
* Two microbits (One of the game, the other for the scoreboard)
* Two crocodile cables (Because two crocs are better than one)
* Type Micro USB cable to transfer the game hex

## The Setup
You can either connect the batteries to the microbits or plug them into two USB ports.\
Connect a crocodile cable from the P0 contact of one microbit to the P0 contact of another.\
Similiarly connect a crocodile cable from the GND contact of one microbit to the GND contact\
of the other. The microbit set to be the sender will show the game while the microbit set\
to receive messages will start at 0 and the numbers will increase as the bit progresses\
in the game. 

## How to install the game on your Micro:bit

### Flashing the hex file
1. First, download the flappy-bird.hex file in this repo.
2. Plug your microbit into your computer.
3. Copy the sender file into one microbit and receiver file into the other.  
4. Start Playing!

### Building from source (Online)

Mbed has an [online compiler](https://ide.mbed.com/compiler/) which makes it easy for you to build your project.

1. First you need to get an [mbed](ide.mbed.com) account.
2. Once you're logged in, open the compiler and create a new empty program.
3. Click import from the toolbar and search for "Microbit".
4. Import the lancaster DAL library.
5. Create your project's main.cpp file.
6. Take the code in main.cpp that's located in this repo and copy it into your main.
7. You can now hit the Compile button which will auto download a *.hex file.
8. Plug your Microbit and flash the hex file into it.
9. Start Playing!  

### Building from source (Offline)
1. Install the Yotta build system with the instructions found [here](http://docs.yottabuild.org/#installing).
2. Hit clone on this repo so you get a copy
3. Open the folder in the terminal and run the command "yotta build" in the folder.
4. Flash the {name}-combined.hex file onto your Microbit.
5. Start Playing!
You can find more information on yotta builds at this [link](http://docs.yottabuild.org/tutorial/building.html). 

## Micro:Bit Usage
Sender Microbit will display the game world as the bird moves between pipes. \
Receiver Microbit will show the score of how many pipes the bird has moved safely through. \
Button A: Moves the bird up one LED. \
Button B: Moves the bird down one LED. 

## Gameplay
The bird is represented by a single LED. The objective of the game is to go as far as \
possible without hitting the oncoming pipes. The player gets one point for each succesful\
crossing. This is shown on the receiver Microbit. The game speed increases as the game\
progress.As soon a the bird crashes into a pipe the game will end and the receiver will\
show the latest score. 

# FAQ
Make sure that your crocodile cables are making a stable connection in order for it\
to work properly and are connected to the correct contacts. If you come across an\
issue with the microbit, try one of the following fixes:

### How do we flash the hex onto the microbit?
Plug your microbit into your computer so that it appears as a USB device.\
Download the tracker.hex file in this repo and drag and drop onto the device.

### Game does not load
Try to compile the hex or download the file and try again OR reset the microbit.\
You can find the reset button located on the back.

### Why won't my Microbit show on the computer?
Check if the USB cable trasnfers data since some will only provide power. If that\
doesn't work, try to connect it to a different computer.

### Why won't my Microbit switch on?
If your Microbit is powered on using a cable try to see if it's properly connected.\
If it is then try a different cable. If you are connected to a battery pack try\
replacing the batteries.

### If you have any enquiries, find a bug or just want to say hello mail us at
mariyam2.yasmeen@live.uwe.ac.uk or ismath2.ibrahim@live.uwe.ac.uk

# Have Fun!