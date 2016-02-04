#ifndef __MAIN_H__
#define __MAIN_H__

/* Includes */
	#include <stdlib.h>
	#include <stdio.h>
	#include <SDL/SDL.h>
	#include "getevent.h"

/* Defines */
	#define HEIGHT 600
	#define WIDTH 800
	#define SPEED 6
	#define DEBUG 6
	enum status{WAIT, MENU, GAME, QUIT};
  	extern enum status gstatus; //status 0=WAIT, 1=MENU, 2=GAME, 3=EXIT
	
/* Structs */
	typedef struct str_game_Head{

	  struct str_game_Rects* first;
	  int length;
	  int pos;

	} str_game_Head ;

	typedef struct str_game_Rects{
	
	  struct str_game_Rects* prev;

	  SDL_Surface* screen;
	  SDL_Rect rect;
	  Uint32 color;

	  struct str_game_Rects* next;

	} str_game_Rects ;

/* Prototypes */
	/** Pure SDL Functions **/
		/* SDL_FillRect Shortcut*/
		SDL_Rect FillRect(SDL_Surface *screen, int x, int y, int w, int h,Uint32 color);

		int ReFillRect(str_game_Rects* rect,Uint32 color);

		/* SDL_BlitSurface shortcut */
		void BlitSurface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip);

	/** Game backend functions **/
		/* Initialise the chained list of elements */
		str_game_Head* game_InitList();
		str_game_Rects* game_AddRects(str_game_Head* head);
		/* Function triggered on quit */
		int game_Quit(int x);
		/* On move (After each tick) */
		int game_Move(SDL_Rect *rect,int x,int y);
		/* Do the moves if the key is pressed, then show it (Exec game_Move, draw_Redraw)*/
		int game_key(Input* in,str_game_Rects* rect);

	/** Draw frontend functions **/
		/* Function to (re)draw something */
		int draw_Redraw(str_game_Rects* rects);

	/** TESTS functions **/
		str_game_Rects* test_DrawRect(SDL_Surface *screen, str_game_Head* head);

#endif


