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
to receive messages will flash 'score' and the numbers will increase as the bit progresses\
in the game. 

## How to install the game on your Micro:bit

### Copying the hex file
1. Download the flappy-bird.hex file from this repository.
2. Connect your microbit to your computer.
3. Copy the sender file into one microbit and receiver file into the other.  
4. Start Playing!

### Building from source (Online)

1. Create an mbedOS account at [ide.mbed.com](ide.mbed.com).
2. Open up the mbedOS compiler and create a new empty program.
3. Head to import and search for "microbit".
4. Import the library that has the tags: dal, lancaster, microbit.
5. Create a new file called main.cpp and copy paste the code from the main in this repo.
6. Click Compile. A *.hex file will be downloaded.
7. Copy the downloaded the sender file into one Microbit and the receiver into the other.
8. Start Playing!  

### Building from source (Offline)
1. Install the Yotta build system with the instructions found [here](http://docs.yottabuild.org/#installing).
2. Create a new folder for your project.
3. Open the newly created folder in the terminal and type `yotta init` to initialise a new yotta project.
4. Download the main.cpp file from this repository and copy it into the source folder in your yotta project.
5. Run the following commands on your project folder:  
    `yotta target bbc-microbit-classic-gcc`  
    `yotta install lancaster-university/microbit`  
    `yotta build`  
6. A *.hex file should be generated at "\build\bbc-microbit-classic-gcc\Source" within your project folder.
7. Copy the *.hex file into your Microbit.
8. Start Playing!  

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
to work properly

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

