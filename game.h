#ifndef _GAME_H_INCLUDE_
#define _GAME_H_INCLUDE_
#include "world.h"
#define MOUSE_COUNT 5

// Set of variables that expresses state of the game.
// 
struct game {
    // X speed of the cat
    int catx;
    // Y speed  of the cat
    int caty;
    // X position of the cat
    int catx_position;
    // Y opsition of the cat
    int caty_position;;
    // X position of the mouse
    int mousex[MOUSE_COUNT];
    // Y position of the mouse
    int mousey[MOUSE_COUNT];
    // Funky message
    char message[100];
    
    int mouse_state[MOUSE_COUNT];

    int mouse_alive;
};

// Returns pointer to  newly allocated state
void* init_game();

// Changes world according to the game state (pressed key, screen size or other event)
int game_event(struct event* event,void* game);

int save_game(const char* filename, struct game* state);

struct game* load_game(const char* filename);


#endif
