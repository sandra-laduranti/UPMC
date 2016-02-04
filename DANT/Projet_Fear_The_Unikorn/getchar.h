#ifndef __GETCHAR_H__
#define __GETCHAR_H__

/* Includes */
	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	#include <SDL/SDL.h>
	#include <SDL/SDL_ttf.h>
	#include "main.h"
	#include "getmap.h"
	#include "getevent.h"







void RecupererVecteur(Input* in, int* vx,int* vy, Map*m, SDL_Rect* perso);
int EssaiDeplacement(Map* carte,SDL_Rect* perso,int vx,int vy);
void Deplace(Map* carte,SDL_Rect* perso,int vx,int vy,int LARGEUR_TILE,int HAUTEUR_TILE);
void Evolue(Input* in,Map* carte,SDL_Rect* perso,int width_tile,int height_tile);
void AfficherPerso(SDL_Rect* perso,SDL_Surface* screen,int xscroll,int yscroll);



#endif