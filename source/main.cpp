/*
The MIT License (MIT)

Copyright (c) 2016 British Broadcasting Corporation.
This software is provided by Lancaster University by arrangement with the BBC.

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the "Software"),
to deal in the Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense,
and/or sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.

--------------------------------------------------------------------------------

* UFCFVK-15-2 Internet of Things
* Challenge 02
* Description: Flappy Bird game implemented on the BBC Micro:bit
* File: main.cpp
* Author: Ismath Ibrahim (S1900094)          
* Version: 0.0.0 
* Modified: 12 March 2020              
*/



#include "MicroBit.h"

/*
    Data structure to implement the bird.
    
    Represents a single LED on the microbit display.
    
    Has two properties, x and y value to hold the bird's location on the display.
*/
struct Point {
    int     x;
    int     y;
};

MicroBit uBit;  // Microbit object instance that would provide the drivers and functions to control the microbit
MicroBitImage map(5,5); // The game world
float score;    // Holds the game score
bool crashed = false; // Holds the crash state
float speed = 650;    // The speed at which the bird moves    
Point bird;

/*
    Moves the bird up and down when the buttons A and B are pressed.
    
    Is a callback function provided for button press event.
    
    @param MicroBitEvent
    @return Void
 */
void moveBird(MicroBitEvent e) {
    
    // If Button A is pressed, move the bird up by 1 LED
    if (e.source == MICROBIT_ID_BUTTON_A) {
        if(bird.y > 0) {
            bird.y--;
        }
        
    }
    
    // If Button B is pressed, move the bird down by 1 LED
    if (e.source == MICROBIT_ID_BUTTON_B) {
        if(bird.y < 4) {
            bird.y++;
        } 
    }
}

/*
    Adds a new pipe followed by two empty columns.
    
    @param None
    @return Void
 */
void addPipe() {
    
    // Calculate a random y value for pipe gap
    int gap = uBit.random(4);
        
    // Fill an entire column for a pipe    
    for (int x=0; x<5; x++) {
        map.setPixelValue(4,x,255);
    }
    
    // Add pipe gap
    map.setPixelValue(4,gap,0);
    
    uBit.sleep(speed);
    
    // Add an empty column
    map.shiftLeft(1);
    
    uBit.sleep(speed);
    
    // Add an empty column
    map.shiftLeft(1);
    
    uBit.sleep(speed);
    
    map.shiftLeft(1);
}

/*
    Move pipes from right to left on the screen.
    
    Is a callback function to create a new fiber.
    
    @param None
    @return Void
 */
void movePipes() {
    
    map.clear();
    
    while(!crashed) {
        addPipe();
    }
}

/*
    Detects if the bird's position is lit on the map, as a pipe, therefore accounting for a crash.
    
    @param None
    @return Void
 */
void detectCrash() {
    if(map.getPixelValue(bird.x, bird.y) != 0) {
            crashed = true;
    }
}

/*
    Increase the game score everytime a pipe reaches column 0.
    
    @param None
    @return Void
 */
void updateScore() {
    for(int i = 0; i<5; i++) {
        if(map.getPixelValue(0,i) == 255) {
            // Each column would have 4 LEDs lit. Hence, add 4 fractions to increase the score by 1
            score = score+0.25;
        }
    }
}

/*
    Increases the game speed based on the game score.
    
    @param None
    @return Void
 */
void updateSpeed() {
    if(score>5) speed = 650;
    if(score>10) speed = 600;
    if(score>15) speed = 550;
    if(score>20) speed = 500;
    if(score>25) speed = 450;
    if(score>30) speed = 400;
    if(score>35) speed = 350;
    if(score>40) speed = 300;
    if(score>45) speed = 250;
    if(score>50) speed = 200;
}

/*
    Asynchronously updates the game state.
    
    Is a callback function to create a fiber.
    
    @param None
    @return Void
 */
void gameStateUpdate() {
    while(!crashed) {
        uBit.sleep(speed);
        
        updateSpeed();
        
        detectCrash();
        
        updateScore();
    }
}

/*
    Display Game Over and show the score.
    
    @param None
    @return Void
 */
void gameOver() {
    uBit.display.clear();

    uBit.display.scroll("GAME OVER! SCORE:");
    uBit.display.scroll((int)score);
    
    uBit.sleep(1000);
}

/*
    Primary gameplay function
    
    @param None
    @return Void
*/
void flappyBird() {

    // Reset all game state.
    crashed = false;
    score = 0;
    speed = 650;
    bird.x = 1;
    bird.y = 4;
        
    // Spawn independent fibers to handle async functions
    create_fiber(movePipes);
    create_fiber(gameStateUpdate);

    // Register event handlers for button presses
    uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_CLICK, moveBird);
    uBit.messageBus.listen(MICROBIT_ID_BUTTON_B, MICROBIT_BUTTON_EVT_CLICK, moveBird);

    while (!crashed) {   
        uBit.sleep(10);
        uBit.display.image.paste(map);
        uBit.display.image.setPixelValue(bird.x, bird.y, 255);
        
    }

    // Display GAME OVER and score
    gameOver();
}

int main() {
    // Initialise the micro:bit runtime.
    uBit.init();

    // Welcome message
    uBit.display.scroll("Flappy Bird");

    // Keep playing forever
    while(1)
        flappyBird();
}

