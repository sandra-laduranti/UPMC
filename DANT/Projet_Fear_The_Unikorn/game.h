#ifndef __GAME_H__
#define __GAME_H__

/* Includes */
	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	#include <SDL/SDL.h>
	#include <SDL/SDL_ttf.h>
	#include "main.h"
	#include "getmap.h"
	#include "getevent.h"




Map* game_Init(SDL_Surface* screen, SDL_Rect* perso, SDL_Rect* limit);
void game_Exec(SDL_Surface* screen, Map* m, Input* in, SDL_Rect* perso, SDL_Rect* limit);
void game_End(Map* m);

#endif
