#include "getmap.h"
#include "game.h"


/* Print Map:
 */


#define CACHE_SIZE 5000

SDL_Surface* LoadImage32(const char* fichier_image)
{
	SDL_Surface* image_result;
	SDL_Surface* image_ram = SDL_LoadBMP(fichier_image);	// charge l'image dans image_ram en RAM
	if (image_ram==NULL)
	{
		printf("Image %s introuvable !! \n",fichier_image);
		SDL_Quit();
		system("pause");
		exit(-1);
	}
	image_result = SDL_DisplayFormat(image_ram);
	SDL_FreeSurface(image_ram);
	return image_result;
}


void ChargerMap_tileset(FILE* F,Map* m)
{
	int numtile=0,i,j;
	char buf[CACHE_SIZE];  // un buffer, petite mémoire cache
	char buf2[CACHE_SIZE];  // un buffer, petite mémoire cache
	fscanf(F,"%s",buf); // #tileset
	fscanf(F,"%s",buf); // nom du fichier
	m->tileset = LoadImage32(buf);
	fscanf(F,"%d %d",&m->nbtilesX,&m->nbtilesY);
	m->width_tile = m->tileset->w / m->nbtilesX;
	m->height_tile = m->tileset->h / m->nbtilesY;
	m->props = malloc(m->nbtilesX*m->nbtilesY*sizeof(TileProp));
	for(j=0;j<m->nbtilesY;j++)
	{
		for(i=0;i<m->nbtilesX;i++,numtile++)
		{
			m->props[numtile].R.w = m->width_tile;
			m->props[numtile].R.h = m->height_tile;
			m->props[numtile].R.x = i*m->width_tile;
			m->props[numtile].R.y = j*m->height_tile;
			fscanf(F,"%s %s",buf,buf2);
			m->props[numtile].mur = 0;
			m->props[numtile].next = 0;
			m->props[numtile].end = 0;
			m->props[numtile].ladder = 0;
			if (strcmp(buf2,"mur")==0)
				m->props[numtile].mur = 1;
			if (strcmp(buf2,"next")==0)
				m->props[numtile].next = 1;
			if (strcmp(buf2,"end")==0)
				m->props[numtile].end = 1;
			if (strcmp(buf2,"ladder")==0)
				m->props[numtile].ladder = 1;
		}
	}
}

void ChargerMap_level(FILE* F,Map* m)
{
	int i,j;
	char buf[CACHE_SIZE];  // un buffer, petite mémoire cache
	fscanf(F,"%s",buf); // #level
	fscanf(F,"%d %d",&m->nbtiles_largeur_monde,&m->nbtiles_hauteur_monde);
	m->schema = malloc(m->nbtiles_largeur_monde*sizeof(Uint16*));
	for(i=0;i<m->nbtiles_largeur_monde;i++)
		m->schema[i] = malloc(m->nbtiles_hauteur_monde*sizeof(Uint16));
	for(j=0;j<m->nbtiles_hauteur_monde;j++)
	{
		for(i=0;i<m->nbtiles_largeur_monde;i++)
		{
			int tmp;
			fscanf(F,"%d",&tmp);
			if (tmp>=m->nbtilesX*m->nbtilesY)
			{
				printf("level tile hors limite\n");
				SDL_Quit();
				system("pause");
				exit(-1);
			}
			m->schema[i][j] = tmp;
		}
	}
}

Map* ChargerMap(const char* level,int largeur_fenetre,int hauteur_fenetre)
{
	FILE* F;
	Map* m;
	F = fopen(level,"r");
	if (!F)
	{
		printf("fichier %s introuvable !! \n",level);
		SDL_Quit();
		system("pause");
		exit(-1);
	}
	m = malloc(sizeof(Map));
	ChargerMap_tileset(F,m);
	ChargerMap_level(F,m);
	m->largeur_fenetre = largeur_fenetre;
	m->hauteur_fenetre = hauteur_fenetre;
	//A iniialiser selon la Map
	m->xscroll = 0;
	m->yscroll = 0;
	fclose(F);
	return m;
}

int AfficherMap(Map* m,SDL_Surface* screen)
{
	int i,j;
	SDL_Rect Rect_dest;
	int numero_tile;
	int minx,maxx,miny,maxy;
	minx = m->xscroll / m->width_tile;
	miny = m->yscroll / m->height_tile;
	maxx = (m->xscroll + m->largeur_fenetre)/m->width_tile;
	maxy = (m->yscroll + m->hauteur_fenetre)/m->height_tile;
	for(i=minx;i<=maxx;i++)
	{
		for(j=miny;j<=maxy;j++)
		{
			Rect_dest.x = i*m->width_tile - m->xscroll;
			Rect_dest.y = j*m->height_tile - m->yscroll;
			if (i<0 || i>=m->nbtiles_largeur_monde || j<0 || j>=m->nbtiles_hauteur_monde)
				numero_tile = 0;
			else
				numero_tile = m->schema[i][j];
			SDL_BlitSurface(m->tileset,&(m->props[numero_tile].R),screen,&Rect_dest);
		}
	}
	return 0;
}

int LibererMap(Map* m)
{
	int i;
	SDL_FreeSurface(m->tileset);
	for(i=0;i<m->nbtiles_hauteur_monde;i++)
		free(m->schema[i]);
	free(m->schema);
	free(m->props);
	free(m);
	return 0;
}

int CollisionDecor(Map* screen,SDL_Rect* perso)
{
	int xmin,xmax,ymin,ymax,i,j,indicetile;
	xmin = perso->x / screen->width_tile;
	ymin = perso->y / screen->height_tile;
	xmax = (perso->x + perso->w -1) / screen->width_tile;
	ymax = (perso->y + perso->h -1) / screen->height_tile;
	if (xmin<0 || ymin<0 || xmax>=screen->nbtiles_largeur_monde || ymax>=screen->nbtiles_hauteur_monde)
		return 1;
	for(i=xmin;i<=xmax;i++)
	{
		for(j=ymin;j<=ymax;j++)
		{
			indicetile = screen->schema[i][j];
			if (screen->props[indicetile].mur)
				return 1;

		}
	}
	return 0;
}

int isGrounded(Map *screen, SDL_Rect* perso){

  int xmin, xmax, ymin, i, j, indicetiledown;
  xmin = perso->x / screen->width_tile;
  ymin = perso->y / screen->height_tile;
  xmax = (perso->x + perso->w -1) / screen->width_tile;

  for (i = xmin; i <= xmax; i++){
    j = ymin+1;
    indicetiledown = screen->schema[i][j];
    if (screen->props[indicetiledown].mur){
      return 1;
    }
  }
  return 0;
}


int End(Map* screen,SDL_Rect* perso)
{
	int xmin,xmax,ymin,ymax,i,j,indicetile;
	xmin = perso->x / screen->width_tile;
	ymin = perso->y / screen->height_tile;
	xmax = (perso->x + perso->w -1) / screen->width_tile;
	ymax = (perso->y + perso->h -1) / screen->height_tile;
	for(i=xmin;i<=xmax;i++)
	{
		for(j=ymin;j<=ymax;j++)
		{
			indicetile = screen->schema[i][j];
			if (screen->props[indicetile].end)
				return 1;
			if (screen->props[indicetile].next)
				return 2;
			if (screen->props[indicetile].ladder)
				return 3;
		}
	}
	return 0;
}

void Next(Map* m,SDL_Rect* perso, SDL_Surface* screen){
	if(End(m,perso)==1){
		SDL_Surface* end = SDL_LoadBMP("the-end.bmp");
		SDL_Rect the_end;
		the_end.x=0;
		the_end.y=0;
		SDL_FillRect(screen,NULL,0x000000);
		SDL_BlitSurface(end, NULL, screen, &the_end);
		SDL_Flip(screen);
		SDL_Delay(2000);
		SDL_FreeSurface(end);
		game_End(m);
		game_Quit(1);
		exit(1);
	}
	if(End(m, perso)==2){
		LibererMap(m);
		m=ChargerMap("Map1.txt",WIDTH,HEIGHT);
		perso->x = 30;
  		perso->y = 30;
	}

}

void ClampScroll(Map* m)
{
	if (m->xscroll<0)
		m->xscroll=0;
	if (m->yscroll<0)
		m->yscroll=0;
	if (m->xscroll>m->nbtiles_largeur_monde*m->width_tile-m->largeur_fenetre-1)
		m->xscroll=m->nbtiles_largeur_monde*m->width_tile-m->largeur_fenetre-1;
	if (m->yscroll>m->nbtiles_hauteur_monde*m->height_tile-m->hauteur_fenetre-1)
		m->yscroll=m->nbtiles_hauteur_monde*m->height_tile-m->hauteur_fenetre-1;
}

int FocusScrollCenter(Map* screen,SDL_Rect* perso)
{
	screen->xscroll = perso->x + perso->w/2 - screen->largeur_fenetre/2;
	screen->yscroll = perso->y + perso->h/2 - screen->hauteur_fenetre/2;
	ClampScroll(screen);
	return 0;
}

int FocusScrollBox(Map* screen,SDL_Rect* perso,SDL_Rect* limit)
{
	int cxperso,cyperso,xlimmin,xlimmax,ylimmin,ylimmax;
	cxperso = perso->x + perso->w/2;
	cyperso = perso->y + perso->h/2;
	xlimmin = screen->xscroll + limit->x;
	ylimmin = screen->yscroll + limit->y;
	xlimmax = xlimmin + limit->w;
	ylimmax = ylimmin + limit->h;
	if (cxperso<xlimmin)
		screen->xscroll -= (xlimmin-cxperso);
	if (cyperso<ylimmin)
		screen->yscroll -= (ylimmin-cyperso);
	if (cxperso>xlimmax)
		screen->xscroll += (cxperso-xlimmax);
	if (cyperso>ylimmax)
		screen->yscroll += (cyperso-ylimmax);
	ClampScroll(screen);
	return 0;
}
