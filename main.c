#include "game.h"
#include "world.h"
#include <stdlib.h>


int main(int argc, char** argv)
{
    
    
    initscr();
    noecho();    
    start_color();
    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    attron(COLOR_PAIR(1));

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    
    mvprintw(10, (xMax-strlen("|||||||||   ||||||||||  ||||        |||      |||||             |||  || |||||  |||||||||    |||||||||    |||       |||"))/2, "|||||||||   ||||||||||  ||||        |||      |||||          |||  || |||||  |||||||||    |||||||||    |||       |||");
    attron(COLOR_PAIR(1));
    mvprintw(11, (xMax-strlen("|||||||||   ||||||||||  ||||        |||      |||||             |||  || |||||  |||||||||    |||||||||    |||       |||"))/2, "   |||      |||    |||  ||| ||   || |||    |||     ||       |||  |||       |||     |||  |||     |||    |||   |||");
    attron(COLOR_PAIR(1));    
    mvprintw(12, (xMax-strlen("|||||||||   ||||||||||  ||||        |||      |||||             |||  || |||||  |||||||||    |||||||||    |||       |||"))/2, "   |||      |||    |||  |||    |    |||     |||||||         |||  ||||||||  ||||||||     ||||||||           ||");
    attron(COLOR_PAIR(1));      
    mvprintw(13, (xMax-strlen("|||||||||   ||||||||||  ||||        |||      |||||             |||  || |||||  |||||||||    |||||||||    |||       |||"))/2, "   |||      |||    |||  |||         |||    |||              |||  |||       |||    ||    |||    ||          ||");
    attron(COLOR_PAIR(1));    
    mvprintw(14, (xMax-strlen("|||||||||   ||||||||||  ||||        |||      |||||             |||  || |||||  |||||||||    |||||||||    |||       |||"))/2, "   |||      ||||||||||  |||         |||    |||||||    |||||||||  ||||||||  |||     ||_  |||     ||_        ||");


    mvprintw(yMax/2+5, (xMax-strlen("Game menu"))/2, "Game menu");
    mvprintw(yMax/2+10, (xMax-strlen("1. Start new game"))/2,"1. Start new game");
    mvprintw(yMax/2+12, (xMax-strlen("2. Exit"))/2, "2. Exit"); 
       

    attroff(COLOR_PAIR(1));
    attroff(COLOR_PAIR(1));
    attroff(COLOR_PAIR(1)); 
    attroff(COLOR_PAIR(1));
    attroff(COLOR_PAIR(1));   



 //   move(event->width, event->height);

    struct game* state;

    int choice = 0;
    do 
    {
	
        choice = getch() - '0';
    } 
    while (choice < 1 || choice > 2);

    
    switch (choice) 
    {
        case 1:
	    endwin();
	    clear();	    
            start_world(init_game, game_event, free);
            break;
        case 2:
            endwin();
            break;
	
    }




  return 0;
}
