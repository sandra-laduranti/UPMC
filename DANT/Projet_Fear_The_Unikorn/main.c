#include "main.h"
#include "menu.h"
#include "game.h"
#include "getmap.h"

enum status gstatus;

/** Pure SDL Functions **/

SDL_Rect FillRect(SDL_Surface *screen, int x, int y, int w, int h,Uint32 color) {
  SDL_Rect rect = {x,y,w,h};
  if(SDL_FillRect(screen, &rect, color)!=0){
    fprintf(stderr,"Error: FillRect x:%d y:%d w:%d h:%d \n",x,y,w,h);
    return rect;
  }
  return rect;
}

int ReFillRect(str_game_Rects* rect,Uint32 color){
  if(SDL_FillRect(rect->screen, &rect->rect, color)!=0){
    return -1;
  }
  return 0;
}

void BlitSurface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip) { 
  //Holds offsets 
  SDL_Rect offset; 
  //Get offsets 
  offset.x = x; offset.y = y; 
  //Blit 
  SDL_BlitSurface( source, clip, destination, &offset ); 
}


/** Game backend functions **/

/* Function triggered on quit */
int game_Quit(int x){
  SDL_Quit();
  return 1;
}

/* Initialise the chained list of elements */
str_game_Head* game_InitList(){
  str_game_Head* strHead = (str_game_Head *)calloc(1,sizeof(str_game_Head));

  
  strHead->first = NULL;
  strHead->length = 0;
  return strHead;
}

str_game_Rects* game_AddRects(str_game_Head* game_head){
  str_game_Rects* strRects = (str_game_Rects *)calloc(1,sizeof(str_game_Rects));
  str_game_Rects* cNode;
   
  game_head->length++;
  if((cNode = game_head->first) != NULL){
    while(cNode->next != NULL){
      cNode = cNode->next;
    }
    cNode->next = strRects;
    strRects->prev = cNode;
    strRects->next = NULL;
  }
  else{
    game_head->first = strRects;
    strRects->next = NULL;
    strRects->prev = NULL;
  }
  
  return strRects;
}

/* On move (After each tick) */
int game_Move(SDL_Rect *rect,int x,int y){
  rect->x+=x;
  rect->y+=y;
  return 0;
}

/* Do the moves if the key is pressed, then show it (Exec game_Move, draw_Redraw)*/
int game_key(Input* in,str_game_Rects* rect){
  if(in->key[SDLK_RIGHT]){
      game_Move(&(rect->rect),SPEED,0);
    }
    if(in->key[SDLK_LEFT]){
      game_Move(&(rect->rect),(-SPEED),0);
    }
    if(in->key[SDLK_UP]){
      game_Move(&(rect->rect),0,(-SPEED));
    }
    if(in->key[SDLK_DOWN]){
      game_Move(&(rect->rect),0,SPEED);
    }
    if(in->key[SDLK_LEFT]||in->key[SDLK_RIGHT]||in->key[SDLK_UP]||in->key[SDLK_DOWN]){
	    draw_Redraw(rect);
	    SDL_Flip(rect->screen);
    }
    return 0;
}


/** Draw frontend functions **/

/* Function to (re)draw something */
int draw_Redraw(str_game_Rects* rects){
  SDL_FillRect(rects->screen,NULL,0x000000);
  FillRect(rects->screen,(&rects->rect)->x,(&rects->rect)->y,(&rects->rect)->w,(&rects->rect)->h,rects->color);
  return 0;
}


/** TESTS functions **/

str_game_Rects* test_DrawRect(SDL_Surface *screen, str_game_Head* game_head){
/* Vars */
  /* Base X and Y pos of rectangle */
  int TPosX = (HEIGHT/2)-50 ;
  int TPosY = (WIDTH/2)-50 ;

/* Code */
  str_game_Rects* rects = game_AddRects(game_head);
  rects->screen = screen;
  rects->color =  SDL_MapRGB(rects->screen->format,255,0,255);
  rects->rect = FillRect(rects->screen,TPosY,TPosX,100,100,rects->color);
  SDL_Flip(rects->screen);
  return rects;
}

/** MAIN **/ 
int main(int argc, char *argv[])
{
  printf("--LOADING--\n");

  /* SDL Structs */
  SDL_Surface *screen = NULL;

  /* Inits */
  if(SDL_Init(SDL_INIT_VIDEO) != 0){
    fprintf(stderr,"Error: INIT\n");
    return EXIT_FAILURE;
  }

  /*Map*/
  Map* m;
  /*position perso*/
  SDL_Rect perso,limit;
  perso.x = 0;
  perso.y = 608;
  perso.w = 24;
  perso.h = 32;
  limit.x = 200;
  limit.y = 150;
  limit.w = 400;
  limit.h = 300;

  screen = SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
  if(screen == NULL){
    fprintf(stderr,"Error: SCREEN\n");
    game_Quit(-1);
    return EXIT_FAILURE;
  }

  SDL_WM_SetCaption("Nahalbuk The Game",NULL);


  Input in;
  memset(&in,0,sizeof(in));
  in.quit=0;

  /* Load info */
  printf("Keys: [%d-%d]\n",SDLK_FIRST,SDLK_LAST);
  // str_game_Head* game_head = 
  game_InitList();
  str_game_Head* menu_head = game_InitList();

  /* Tests */
  printf("--GAME--\n");
  // str_game_Rects* rects = test_DrawRect(screen,game_head);
  menu_initMenu(screen,menu_head);
	printf("\n%d", gstatus);
  menu_redrawMenu(screen,menu_head);


  /*Main code*/
  while(1){
  	printf("\n%d", gstatus);
  	if(gstatus == 1)
  	  if(menu(screen,&in,menu_head)==2) m = game_Init(screen, &perso, &limit); 	
  	printf("\n%d", gstatus);
  	if(gstatus == 2)
  	  game_Exec(screen, m, &in, &perso, &limit);
  	printf("\n%d %d", gstatus, in.quit);
  	if(gstatus == 3 || in.quit || in.key[SDLK_ESCAPE]){
      if(gstatus==2)
      	game_End(m);
      game_Quit(1);
  	  return EXIT_SUCCESS;
  	}
  }
}



