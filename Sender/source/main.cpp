    /**
     * UFCFVK-15-2 Internet of Things
     * Challenge 02
     * Description: The game flappy bird reinvented for a microbit with communication
                   in order to show the real time score using a second microbit
     * File: main.cpp for the sender microbit
     * Authors: Mariyam Yasmeen (S1800367) & Ismath Ibrahim (S1900094)          
     * Version: 1.2.500 
     * Modified: 18 April 2020 
     * Setup: Connect crocodile cables from P0 to P0 and from GND to GND on two microbits                  
    */
    
    #include "MicroBit.h"
    
    /**
     * Data structure to implement the bird.
     * Represents a single LED on the microbit display.
     * Has two properties, x and y value to hold the bird's location on the display.
    */
    struct Point
    {
        int x;
        int y;
    };
    
    MicroBit uBit;           // Microbit object instance that would provide the drivers and functions to control the microbit
    MicroBitImage map(5, 5); // The game world
    float score;             // Holds the game score
    bool crashed = false;    // Holds the crash state
    float speed = 650;       // The speed at which the bird moves
    Point bird;              
    MicroBitPin P0(MICROBIT_ID_IO_P0, MICROBIT_PIN_P0, PIN_CAPABILITY_DIGITAL); //Provides control over the P0 GPIO Pin
    
    /**
     * Moves the bird up and down when the buttons A and B are pressed.
     * 
     * Is a callback function provided for button press event.
     * @param MicroBitEvent
     * @return Void
     */
    void moveBird(MicroBitEvent e)
    {
    
        // If Button A is pressed, move the bird up by 1 LED
        if (e.source == MICROBIT_ID_BUTTON_A)
        {
            if (bird.y > 0)
            {
                bird.y--;
            }
        }
    
        // If Button B is pressed, move the bird down by 1 LED
        if (e.source == MICROBIT_ID_BUTTON_B)
        {
            if (bird.y < 4)
            {
                bird.y++;
            }
        }
    }
    
    /**
     * Adds a new pipe followed by two empty columns.
     * @param None
     * @return Void
     */
    void addPipe()
    {
    
        // Calculate a random y value for pipe gap
        int gap = uBit.random(4);
    
        // Fill an entire column for a pipe
        for (int x = 0; x < 5; x++)
        {
            map.setPixelValue(4, x, 255);
        }
    
        // Add pipe gap
        map.setPixelValue(4, gap, 0);
    
        uBit.sleep(speed);
    
        // Add an empty column
        map.shiftLeft(1);
    
        uBit.sleep(speed);
    
        // Add an empty column
        map.shiftLeft(1);
    
        uBit.sleep(speed);
    
        map.shiftLeft(1);
    }
    
    /**
     * Move pipes from right to left on the screen.
     * Is a callback function to create a new fiber.
     * @param None
     * @return Void
     */
    void movePipes()
    {
    
        map.clear();
    
        while (!crashed)
        {
            addPipe();
        }
    }
    
    /**
     * Detects if the bird's position is lit on the map, as a pipe, therefore accounting for a crash.
     * @param None
     * @return Void
     */
    void detectCrash()
    {
        if (map.getPixelValue(bird.x, bird.y) != 0)
        {
            crashed = true;
        }
    }
   
    /**
     * Send a pulse of a specific length to trigger a response on the receiver
     * @param PulseLength The length of the pulse to be sent to the receiver
     * @return Void
     */
   void SendPulse(int PulseLength) { 
       P0.setDigitalValue(1); 
       uBit.sleep(PulseLength); 
       P0.setDigitalValue(0); 
       uBit.sleep(100);
   }
     
    
    /**
     * Increase the game score everytime a pipe reaches column 0.
     * @param None
     * @return Void
     */
    void updateScore()
    {
        bool passedPipe = false;

            if (map.getPixelValue(0, 4) == 255)
            {
                // If the fifth led on the first column is lit that means the bird has crossed a pipe
                passedPipe = true;   
            }

            if (passedPipe) {
                // Sends a pulse of length "300 "to make the counter on the reciever add one
                SendPulse(300);
                score++; // Keeps track of the score on the sender microbit to increase difficulty
            }
    }
    
    /**
     * Increases the game speed based on the game score.
     * @param None
     * @return Void
     */
    void updateSpeed()
    {
        if (score > 10)
            speed = 600;
        if (score > 20)
            speed = 500;
        if (score > 30)
            speed = 400;
        if (score > 40)
            speed = 300;
        if (score > 50)
            speed = 200;
    }
    
    /**
     * Asynchronously updates the game state.
     * Is a callback function to create a fiber.
     * @param None
     * @return Void
     */
    void gameStateUpdate()
    {
        while (!crashed)
        {
            detectCrash();
            
            uBit.sleep(100);
    
            updateSpeed();
    
            uBit.sleep(100);
    
            updateScore();
            
            uBit.sleep(100);
        }
    }
    
    /**
     * Display Game Over and show the score.
     * @param None
     * @return Void
     */
    void gameOver()
    {
        
        uBit.sleep(600); // Required to let the reciever finish scrolling double digits before receiving the game over pulse
        uBit.display.clear();
        SendPulse(200); // Sends a pulse of length "200" to trigger the receiver to display final score and reset
        uBit.display.scroll("GAME OVER!");
        uBit.sleep(100);
    }
    
    /**
     * Primary gameplay function
     * @param None
     * @return Void
    */
    void flappyBird()
    {
    
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
    
        while (!crashed)
        {
            uBit.sleep(10);
            uBit.display.image.paste(map);
            uBit.display.image.setPixelValue(bird.x, bird.y, 255);
        }
    
        // Ends the game and displays Game Over
        gameOver();
    }
    
    int main()
    {
        // Initialise the micro:bit runtime.
        uBit.init();
    
        // Welcome message
        uBit.display.scroll("Flappy Bird", 100);
    
        // Keep playing with auto restart
        while (1)
            flappyBird();
    }