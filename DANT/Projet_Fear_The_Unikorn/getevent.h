#ifndef __GETEVENT_H__
#define __GETEVENT_H__

/* Includes */
	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	#include <SDL/SDL.h>
	#include <SDL/SDL_ttf.h>
	// #include "main.h"

typedef struct{
	char key[SDLK_LAST];
	int quit;
} Input;

void UpdateEvents(Input* in);

#endif