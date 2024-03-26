#include <curses.h>
#include <stdlib.h>
#include <string.h>
#include "world.h"
#include "game.h"

// Start is called one in the beginning
void* init_game(){
    // Allocate memory for the state
    struct game* st = calloc(1,(sizeof(struct game)));
    // Initialize state
    st->mousex[0] = 5;
    st->mousey[0] = 5;
    st->catx = 0;
    st->caty = 0;
    st->catx_position = 15;
    st->caty_position = 15;
    st->mouse_alive = MOUSE_COUNT;
    // Store pointer to the state to the world variable
    return st;
}

// Step is called in a loop once in interval.
// It should modify the state and draw it.
int game_event(struct event* event,void* game)
{
    // Get state pointer
    struct game* state = game;
    char msg[200];
 //   int choice_2 = 0;
    sprintf(msg,"%d",event->type);
    set_message(msg,10,0);
    if ( event->type == EVENT_ESC)
    {
        // Non zero means finish the loop and stop the game.
        return 1;
    }
    // Read game variable and update the  eventstate

    // Is mouse caught ?
    for (int i = 0; i < MOUSE_COUNT; i++) 
    {
    // Проверяем, жива ли мышь
        if (state->mousex[i] >= 0) 
	{
        // Проверяем, поймала ли кошка мышь
           if (state->mousex[i] == state->catx_position && state->mousey[i] == state->caty_position) 
	   {
            // Если да, то мышь считается "съеденной"
            state->mouse_state[i] = 1;
	    state->mouse_alive--;
//	    set_message("HAM",12,13);
           }
        }
    }
   


    if(state->mouse_alive == 0)
    {
//		clear_screen();
//		 endwin();
//         exit(0);
         
  //      initscr();
//	int xMax = 0;	
	
//	clear_screen();
//	initscr();

	
//	mvprintw(20, (xMax-strlen("Congratulation! You won!"))/2, "Congratulation! You won!");
//	mvprintw(21, (xMax-strlen("What do you want to play next?"))/2, "What do you want to play next?");
//	mvprintw(22, (xMax-strlen("1.Save game"))/2, "1.Save game");
  //      mvprintw(23, (xMax-strlen("2.New game"))/2, "2.New game");
    //    mvprintw(24, (xMax-strlen("3.Exit"))/2, "3.New game");
     //   mvprintw(24, (xMax-strlen("4.Load game"))/2, "4.Load game");
//	do 
  //      {
    //    	choice_2 = getch() - '0';
   // 	} 
    //	while (choice_2 < 1 || choice_2 > 3);

    
      /*  switch (choice_2) 
        {

		case 1:
		     
 		     save_game("save.bin", state);
		     
		     break;
        	case 2:
	    	   endwin();
	    	   clear();	    
            	   start_world(init_game,game_event,free);
                   break;
                case 3:
                   endwin();
                   break;
		case 4:
		state = load_game("save.bin");
		if (state == NULL) {
    			// Failed to load the game state
		}
		start_world(init_game,game_event,free);
		break; 
 */   	
	endwin();
	exit(0);
	return 0;
	
    
}

    if(event->type == EVENT_TIMEOUT) 
    {
        // Move cat
        //state->catx_position += state->catx;
        //state->caty_position += state->caty;
        int cx = state->catx_position + state->catx;
        int cy = state->caty_position + state->caty;
        
	if (cx < 0 || cy < 0 || cx >= event->width || cy >= event->height)
	{
        // кошка вышла за границы поля, не делаем ничего
    	}
    	else 
	{
        state->catx_position = cx;
        state->caty_position = cy;
    	}
	

        //state->catx_position += state->catx;
        //state->caty_position += state->caty;
        //state->caty_position += state->caty;
        // random mouse movement
     	for (int i = 0; i < MOUSE_COUNT; i++)
	{
    		if (state->mousex[i] >= 0)
    		{
        		// Случайное движение мыши
        		int m = rand() % 4;
        		if (m == 0 && state->mousey[i] > 0)
        		{
            			state->mousey[i] -= 1;
        		}
        	else if (m == 1 && state->mousey[i] < event->height - 1)
        	{
            		state->mousey[i] += 1;
        	}
        	else if (m == 2 && state->mousex[i] > 0)
        	{
            		state->mousex[i] -= 1;
        	}
        	else if (m == 3 && state->mousex[i] < event->width - 1)
        	{
            		state->mousex[i] += 1;
        	}
    		}
	}


    }
    else if (event->type == EVENT_KEY){
        // Move cat according to keyboard
        if ( event->key == KEY_UP){
            state->catx = 0;
            state->caty = -1;
        }
        else if ( event->key == KEY_DOWN){
            state->catx = 0;
            state->caty = 1;
        }
        else if ( event->key == KEY_LEFT){
            state->catx = -1;
            state->caty = 0;
        }
        else if ( event->key == KEY_RIGHT){
            state->catx = +1;
            state->caty = 0;
        }
    }


    clear_screen();

//    mvprintw("+----------------------------------------+", 21, 1);

    
	start_color();
        init_pair(1, COLOR_BLUE,COLOR_BLACK);    

         attron(COLOR_PAIR(1));

	// Draw world state 
	int x = 0, y = 0;
    
  
    for (x = 1; x < event->width-1; x++) {
        mvaddch(0, x, '-');
    }

    // Draw sides and empty space
    for (y = 1; y < event->height-1; y++) {
        mvaddch(y, 0, '|');
        for (x = 1; x < event->width; x++) {
            mvaddch(y, x, ' ');
        }
        mvaddch(y, event->width-1, '|');
    }

    // Draw bottom border
    for (x = 1; x < event->width-1; x++) {
        mvaddch(event->height-1, x, '-');
    }

    attroff(COLOR_PAIR(1));
    //
    // Draw cat
//    clear_screen();

//set_cell(state->catx_position, 10, 10);

if(state->catx_position >= 0 && state->catx_position < event->width-1 && state->caty_position >= 0 && state->caty_position < event->height)
{

    if(state->caty_position == 0)
    {
	state->caty_position = state->caty_position + 1;	
    }

    if(state->caty_position == event->height -1)
    {
	state->caty_position = state->caty_position - 1;
    }

    if(state->catx_position == event->width - 3)
    {
	state->catx_position = state->catx_position - 1;
    }
    
    if(state->catx_position >= 0) // Проверка на то, что символ не находится на левой границе поля
    {
        set_color_cell('-',state->catx_position+1,state->caty_position,COLOR_YELLOW,COLOR_GREEN);
	set_color_cell('c',state->catx_position+2,state->caty_position,COLOR_YELLOW,COLOR_RED);   
    }

 //else if(state->catx_position < event->width) 
// {
  //      set_color_cell('c',state->catx_position,state->caty_position,COLOR_YELLOW,COLOR_RED);
//	set_color_cell('-',state->catx_position-1,state->caty_position,COLOR_YELLOW,COLOR_GREEN);
 //}

    
 //   if(state->catx_position < event->width-1) // Проверка на то, что символ не находится на правой границе поля
   // {
     //   set_color_cell('-',state->catx_position+1,state->caty_position,COLOR_YELLOW,COLOR_GREEN);
    //}
    
//    set_color_cell('c',state->catx_position+1,state->caty_position,COLOR_YELLOW,COLOR_RED);
}

//if(state->catx_position == event->width-1)
//{
//	  set_color_cell('c',state->catx_position,state->caty_position,COLOR_YELLOW,COLOR_RED);
//	  set_color_cell('-',state->catx_position-1,state->caty_position,COLOR_YELLOW,COLOR_GREEN);
//}



//printf("state->catx_position = %d\n", state->catx_position);
//set_cell('c',state->catx_position,state->caty_position);
    // Draw mouse

 //  for (int i = 0; i < MOUSE_COUNT; i++)
//{
	
   // if(k == 4)
    //{
//	endwin();
//	return 0;
  //  }   	
 
    for (int i = 0; i < MOUSE_COUNT; i++)
    {
    	if (((struct game*) game)->mousex[i] >= 0 && ((struct game*) game)->mousey[i] >= 0 && ((struct game*) game)->mousex[i] < event->width-1 && ((struct game*) game)->mousey[i] < event->height)
    {
	if(state->mousey[i] == event->height-2)
	{
	 	state->mousey[i] = state->mousey[i]-1;
	}
	
	if(state->mousex[i] == event->width - 2)
	{
		state->mousex[i] = state->mousex[i] - 1;
	}
	if(state->mousex[i] >= 0 && state->mouse_state[i] == 0)
	{
        	set_color_cell('m', ((struct game*) game)->mousex[i]+1, ((struct game*) game)->mousey[i]+1, COLOR_BLACK, COLOR_YELLOW);
    	}

	else
	{
		state->mousex[i] = -1;
        	state->mousey[i] = -1;
	//		k++;		
	}
    }

	

    }

   
//}

    //set_cell('m',state->mousex,state->mousey);
    set_message( state->message,1,0);
    return 0;
}

int save_game(const char* filename, struct game* state)
{
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        return 0;
    }
    fwrite(state, sizeof(struct game), 1, file);
    fclose(file);
    return 1;
}


struct game* load_game(const char* filename)
{
    struct game* state = calloc(1, sizeof(struct game));
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        free(state);
        return NULL;
    }
    fread(state, sizeof(struct game), 1, file);
    fclose(file);
    return state;
}

