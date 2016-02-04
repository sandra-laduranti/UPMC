#include "getchar.h"

#define SGN(X) (((X)==0)?(0):(((X)<0)?(-1):(1)))
#define ABS(X) ((((X)<0)?(-(X)):(X)))
int tmp;

void RecupererVecteur(Input* in, int* vx,int* vy, Map*m, SDL_Rect* perso)
{
	int vitesse = 2;
	*vx = *vy = 0;
	if (in->key[SDLK_UP] && (End(m,perso)==3))
		*vy = -vitesse;
	if (in->key[SDLK_DOWN] || (End(m,perso)!=3))
		*vy = vitesse;
	if ((in->key[SDLK_UP] && (End(m,perso) !=3)) && isGrounded(m,perso)){
	  tmp = 40;	  
	}
	if (tmp > 0){
	  *vy = -tmp/10;
	  tmp --;
	}
	if (in->key[SDLK_LEFT])
		*vx = -vitesse;
	if (in->key[SDLK_RIGHT])
		*vx = vitesse;
}

int EssaiDeplacement(Map* carte,SDL_Rect* perso,int vx,int vy)
{
	SDL_Rect test;
	test = *perso;
	test.x+=vx;
	test.y+=vy;
	if(test.x<0 ||test.y<0)
		return 0;
	if(CollisionDecor(carte,&test)==0)
	{
		*perso = test;
		return 1;
	}
	return 0;
}

void Deplace(Map* carte,SDL_Rect* perso,int vx,int vy,int width_tile,int height_tile)
{
	int i;
	if(vx>=width_tile || vy>=height_tile)
	{
		Deplace(carte,perso,vx/2,vy/2,width_tile,height_tile);
		Deplace(carte,perso,vx-vx/2,vy-vy/2,width_tile,height_tile);
		return;
	}
	if(EssaiDeplacement(carte,perso,vx,vy)==1)
		return;
// affine
	for(i=0;i<ABS(vx);i++)
	{
		if(EssaiDeplacement(carte,perso,SGN(vx),0)==0)
			break;
	}
	for(i=0;i<ABS(vy);i++)
	{
		if(EssaiDeplacement(carte,perso,0,SGN(vy))==0)
			break;
	}
}

void Evolue(Input* in,Map* carte,SDL_Rect* perso,int width_tile,int height_tile)
{
	int vx,vy;
	RecupererVecteur(in,&vx,&vy,carte,perso);
	Deplace(carte,perso,vx,vy,width_tile,height_tile);
}

void AfficherPerso(SDL_Rect* perso,SDL_Surface* screen,int xscroll,int yscroll)
{
	SDL_Rect positionsurecran = *perso;
	positionsurecran.x -= xscroll;
	positionsurecran.y -= yscroll;
	SDL_FillRect(screen,&positionsurecran,0x00FF00); 
}
