#ifndef __MENU_H__
#define __MENU_H__

/* Includes */
	#include <stdlib.h>
	#include <stdio.h>
	#include <SDL/SDL.h>
	#include <SDL/SDL_ttf.h>
	#include "main.h"
	#include "getmap.h"
	#include "getevent.h"


#define DEF_R 61
#define DEF_G 61
#define DEF_B 61

#define BUTT_H 50
#define BUTT_W 175


/* Menu Initialisation function */
/* Menus :
 * - New game
 * - Load game
 * - Settings
 * - Credit
 * - Quit */
 int menu_initMenu(SDL_Surface *screen, str_game_Head* head);
 int menu_event(SDL_Surface *screen, Input* in, str_game_Head* menu_head);
 int menu_redrawMenu(SDL_Surface *screen, str_game_Head* menu_head);
 int menu_exec(int pos, SDL_Surface* screen, Input* in);
 int menu(SDL_Surface *screen, Input* in, str_game_Head* menu_head);
 

#endif