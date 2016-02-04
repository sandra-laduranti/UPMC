#include "getmap.h"
#include "getevent.h"
#include "game.h"
#include "getchar.h"




Map* game_Init(SDL_Surface* screen, SDL_Rect* perso, SDL_Rect* limit){
	Map* m;
 	SDL_FillRect(screen,NULL,0x000000);
	m = ChargerMap("Map2.txt",WIDTH,HEIGHT);
            // printf("game_Init : %d\n",m->xscroll);


	AfficherMap(m,screen);
	AfficherPerso(perso,screen,m->xscroll,m->yscroll);

	SDL_Flip(screen);
	return m;
}

void game_Exec(SDL_Surface* screen, Map* m,Input* in, SDL_Rect* perso, SDL_Rect* limit){
	
	while(!in->key[SDLK_ESCAPE] && !in->quit){
		UpdateEvents(in);
		Evolue(in,m,perso,m->width_tile,m->height_tile);
		FocusScrollCenter(m,perso);
		FocusScrollBox(m,perso,limit);
		AfficherMap(m,screen);
		AfficherPerso(perso,screen,m->xscroll,m->yscroll);
		SDL_Flip(screen);
		SDL_Delay(5);
		Next(m,perso,screen);
	}
	
}

void game_End(Map* m){
	LibererMap(m);
}
