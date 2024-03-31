# Mouse and Cats
### 1.  Description

* Purpose:

    - This C program simulates a game where a cat tries to catch mice in a world represented by a grid.
    - The player controls the cat's movement using arrow keys.
    - Mice move randomly within the grid boundaries.
    - The game ends when all mice are caught.

* Key Features:

    - Text-based world representation using curses library.
    - Random mouse movement.
    - Cat movement based on user input.
    - Mouse catching logic.
    - Basic game state management (playing, winning).
    - File I/O for saving and loading game states (not implemented fully).

### 2. How to translate and run the program ?

- Install Libraries: Ensure you have the curses library installed. 
It might come pre-installed on your system or require separate installation.


- Compile the program
    ````c
    make
    ````

- Run the program using the command: 
    ````c
    ./game
    ````


### 3. How the program is programmed?

* Key Functions:
    - init_game(): Initializes the game state, allocating memory for the game structure and setting initial positions for the cat and mice.
    - game_event(): Handles different game events like key presses, timeouts, and checks for game over conditions.
        * Updates the cat's position based on user input (arrow keys).
        * Implements random mouse movement within the grid boundaries.
        * Detects mouse capture by checking if the cat's position overlaps with a live mouse.
        * Handles game over logic when all mice are caught (not fully implemented in this snippet).
        * Provides basic message display and screen clearing functionalities.
    - save_game() and load_game(): (not fully implemented) 
    These functions seem intended for saving and loading game states to/from a file.


### 4. Links to source code and websites that were used in the solution

-   [GitHub Game World](https://github.com/hladek/world)
-   [ncurses](https://man7.org/linux/man-pages/man3/ncurses.3x.html)
