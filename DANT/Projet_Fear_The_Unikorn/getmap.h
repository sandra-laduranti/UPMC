#ifndef __GETMAP_H__
#define __GETMAP_H__

/* Includes */
	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	#include <SDL/SDL.h>
	#include <SDL/SDL_ttf.h>
	#include "main.h"
	// #include "getevent.h"



typedef struct
{
	SDL_Rect R;
	int mur;
	int end;
	int next;
	int ladder;
} TileProp;

typedef struct
{
	int width_tile,height_tile;
	int nbtilesX,nbtilesY;
	SDL_Surface* tileset;
	TileProp* props;
	Uint16** schema;
	int nbtiles_largeur_monde,nbtiles_hauteur_monde;
	int xscroll, yscroll;
	int largeur_fenetre, hauteur_fenetre;
} Map;

Map* ChargerMap(const char* level,int largeur_fenetre,int hauteur_fenetre);
int AfficherMap(Map* m,SDL_Surface* screen);
int LibererMap(Map* m);
// void MoveMap(Map* m,int* keys);
int CollisionDecor(Map* carte,SDL_Rect* perso);
int FocusScrollCenter(Map* carte,SDL_Rect* perso);
int FocusScrollBox(Map* carte,SDL_Rect* perso,SDL_Rect* limit);
int End(Map* screen,SDL_Rect* perso);
void Next(Map* m,SDL_Rect* perso, SDL_Surface* screen);	

int isGrounded(Map *screen, SDL_Rect* perso);

#endif
