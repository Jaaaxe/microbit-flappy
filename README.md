# IoT Challenge 2
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

## What do you need?
* Two microbits
* Two crocodile cables
* Micro USB cable to transfer the game

## The Setup
You can either connect the batteries to the microbits or plug them into two USB ports.\
Connect a crocodile cable from the P0 contact of one microbit to the P0 contact of another.\
Similiarly connect a crocodile cable from the GND contact of one microbit to the GND contact\
of the other. The microbit set to be the sender will show the game while the microbit set\
to receive messages will start at 0 and the numbers will increase as the bit progresses\
in the game. 

## How to install the game on your Micro:bit

### Copying the hex file
1. Download the flappy-bird.hex file from this repository.
2. Connect your microbit to your computer.
3. Copy the sender file into one microbit and receiver file into the other.  
4. Start Playing!

### Building from source (Online)

1. Create an mbedOS account at [ide.mbed.com](ide.mbed.com).
2. Open up the mbedOS compiler and create two new empty programs.
3. Head to import and search for "microbit".
4. Import the library that has the tags: dal, lancaster, microbit.
5. Create new files called main.cpp in both projects.
6. Copy paste the code from the main.cpp in Sender directory to one and Reciever directory to the other
7. Click Compile for each prohect. Two *.hex files will be downloaded.
8. Copy the downloaded the sender hex into one Microbit and the receiver hex into the other.
9. Start Playing!  

### Building from source (Offline)
1. Install the Yotta build system with the instructions found [here](http://docs.yottabuild.org/#installing).
2. Clone this repository.
3. Open the Sender and the Receiver folders in the terminal and run the command `yotta build` in each folder.
4. Build files should be generated at "\build\bbc-microbit-classic-gcc\Source" within each of the folders.
5. Copy the {project name}-combined.hex file to their respective Microbits.
6. Start Playing!  

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

## Warnings
Make sure that your crocodile cables are making a stable connection in order for it\
to work properly and connected to the correct contacts. 

## Troubleshooting
If you are unable to play the game try one of the following fixes:

### Game does not load
Try to compile the hex or download the file and try again OR reset the microbit.\
You can find the reset button located on the back.

### Microbit is not detected on your computer
Try using a different micro USB cable or connect it to a different computer.

### Microbit won't power on
Check to see if your micro USB cable works or if the batteries in the external\
power pack need to be replaced.

### I have another issue 
Please mail your enquiries to mariyam2.yasmeen@live.uwe.ac.uk or ismath2.ibrahim@live.uwe.ac.uk

# Have Fun!

