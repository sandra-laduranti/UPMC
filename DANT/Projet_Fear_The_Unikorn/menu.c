#include "menu.h"
#include "game.h"


/* Menus :
 * - New game
 * - Load game
 * - Settings
 * - Credit
 * - Quit
 * Let's do this */
int menu_initMenu(SDL_Surface *screen, str_game_Head* head){
  printf("INIT: Menu\n");
  int steps = HEIGHT/6 ; 
  int TPosX = WIDTH/2;
  int selection = 1; // The currently selected button

  //The surfaces 
  SDL_Surface *text_NewGame = NULL;
  SDL_Surface *text_LoadGame = NULL;
  SDL_Surface *text_Settings = NULL;
  SDL_Surface *text_Credit = NULL;
  SDL_Surface *text_Quit = NULL;

  //The font that's going to be used
  TTF_Font *font = NULL;
  
  //The color of the font
  SDL_Color textColor = { 255, 255, 255 };

  //Inits
  
  if(TTF_Init() == -1){
    printf("ERROR: INIT_TTF_LIB\n");
    return -1;
  }

  //Open the font 
  if((font = TTF_OpenFont( "./Data/Fonts/towerruins.ttf", 28 )) == NULL){
    printf("ERROR: Can't load font\n");
    return -1;
  }
  
  str_game_Rects* ButtNewGame = game_AddRects(head);
  str_game_Rects* ButtLoadGame = game_AddRects(head);
  str_game_Rects* ButtSettings = game_AddRects(head);
  str_game_Rects* ButtCredit = game_AddRects(head);
  str_game_Rects* ButtQuit = game_AddRects(head);

  ButtNewGame->screen = screen;
  ButtLoadGame->screen = screen;
  ButtSettings->screen = screen;
  ButtCredit->screen = screen;
  ButtQuit->screen = screen;

  ButtNewGame->color = SDL_MapRGB(ButtNewGame->screen->format,DEF_R,DEF_G,DEF_B);
  ButtLoadGame->color = SDL_MapRGB(ButtLoadGame->screen->format,DEF_R,DEF_G,DEF_B);
  ButtSettings->color = SDL_MapRGB(ButtSettings->screen->format,DEF_R,DEF_G,DEF_B);
  ButtCredit->color = SDL_MapRGB(ButtCredit->screen->format,DEF_R,DEF_G,DEF_B);
  ButtQuit->color = SDL_MapRGB(ButtQuit->screen->format,DEF_R,DEF_G,DEF_B);

  ButtNewGame->rect = FillRect(ButtNewGame->screen,(TPosX - (BUTT_W/2)),(steps*1),BUTT_W,BUTT_H,ButtNewGame->color);
  ButtLoadGame->rect = FillRect(ButtLoadGame->screen,(TPosX - (BUTT_W/2)),(steps*2),BUTT_W,BUTT_H,ButtLoadGame->color);
  ButtSettings->rect = FillRect(ButtSettings->screen,(TPosX - (BUTT_W/2)),(steps*3),BUTT_W,BUTT_H,ButtSettings->color);
  ButtCredit->rect = FillRect(ButtCredit->screen,(TPosX - (BUTT_W/2)),(steps*4),BUTT_W,BUTT_H,ButtCredit->color);
  ButtQuit->rect = FillRect(ButtQuit->screen,(TPosX - (BUTT_W/2)),(steps*5),BUTT_W,BUTT_H,ButtQuit->color);

  //Render the texts
  text_NewGame = TTF_RenderText_Solid( font, "New Game", textColor ); 
  BlitSurface((TPosX - (BUTT_W/2) + 20),(steps*1)+10, text_NewGame, screen, NULL);

  text_LoadGame = TTF_RenderText_Solid( font, "Load Game", textColor ); 
  BlitSurface((TPosX - (BUTT_W/2) + 15),(steps*2)+10, text_LoadGame, screen, NULL);

  text_Settings = TTF_RenderText_Solid( font, "Settings", textColor ); 
  BlitSurface((TPosX - (BUTT_W/2) + 25),(steps*3)+10, text_Settings, screen, NULL);

  text_Credit = TTF_RenderText_Solid( font, "Credit", textColor ); 
  BlitSurface((TPosX - (BUTT_W/2) + 42),(steps*4)+10, text_Credit, screen, NULL);

  text_Quit = TTF_RenderText_Solid( font, "Quit", textColor ); 
  BlitSurface((TPosX - (BUTT_W/2) + 60),(steps*5)+10, text_Quit, screen, NULL);

  head->pos = selection;
  head->length = 5;

  gstatus = 1;
  SDL_Flip(screen);
  return 0;
}


int menu_event(SDL_Surface *screen, Input* in, str_game_Head* menu_head){
	int move=0;

	if(menu_head->length==0){
		printf("-1");
		return -1;/* No menu items */
	}
	if(menu_head->pos==0){
		printf("-2");
		return -2;/* No position */
	}

	if(in->key[SDLK_UP]){
      	if(menu_head->pos > 1){
      		menu_head->pos--;
      		move=1;
          in->key[SDLK_UP]=0;
      		if(DEBUG>6){printf("DBG: pos:%d\n",menu_head->pos);}
      	}
    }
    else if(in->key[SDLK_DOWN]){
  		if(menu_head->pos < menu_head->length){
  			menu_head->pos++;
  			move=1;
        in->key[SDLK_DOWN]=0;
  			if(DEBUG>6){printf("DBG: pos:%d\n",menu_head->pos);}
  		} 
    }
    else if(in->key[SDLK_RETURN]){
    	return menu_exec(menu_head->pos, screen, in);

    }


	if(move==1){
		menu_redrawMenu(screen,menu_head);
	}

	return 0;
	
}


int menu_redrawMenu(SDL_Surface *screen, str_game_Head* menu_head){
	int i;
	int steps = HEIGHT/6 ; 
	int TPosX = WIDTH/2;

	str_game_Rects* menu_rects = menu_head->first;

	//The font that's going to be used
	TTF_Font *font = NULL;
	
	//The color of the font
	SDL_Color textColor = { 255, 255, 255 };


	/* Every bg before the selected are grey */
	for(i=1;i<menu_head->pos;i++){
		menu_rects->color = SDL_MapRGB(menu_rects->screen->format,DEF_R,DEF_G,DEF_B);
		menu_rects = menu_rects->next;
	}

    /* Selected is red */
	menu_rects->color = SDL_MapRGB(menu_rects->screen->format,200,0,0);
	menu_rects = menu_rects->next;

	/* Every bg after after selected are grey */
	for(i=menu_head->pos+1;i<=menu_head->length;i++){
	 	menu_rects->color = SDL_MapRGB(menu_rects->screen->format,DEF_R,DEF_G,DEF_B);
		menu_rects = menu_rects->next;
	}

	/** DRAWING **/

	if((font = TTF_OpenFont( "./Data/Fonts/towerruins.ttf", 28 )) == NULL){
	  printf("ERROR: Can't load font\n");
	  return -1;
	}

	menu_rects = menu_head->first;

	for(i=1;i<=menu_head->length;i++){
		ReFillRect(menu_rects,menu_rects->color);
		menu_rects = menu_rects->next;
	}

	SDL_Surface *text_update = NULL;

	text_update = TTF_RenderText_Solid( font, "New Game", textColor );
	BlitSurface((TPosX - (BUTT_W/2) + 20),(steps*1)+10, text_update, screen, NULL);

	text_update = TTF_RenderText_Solid( font, "Load Game", textColor ); 
	BlitSurface((TPosX - (BUTT_W/2) + 15),(steps*2)+10, text_update, screen, NULL);

	text_update = TTF_RenderText_Solid( font, "Settings", textColor ); 
	BlitSurface((TPosX - (BUTT_W/2) + 25),(steps*3)+10, text_update, screen, NULL);

	text_update = TTF_RenderText_Solid( font, "Credit", textColor ); 
	BlitSurface((TPosX - (BUTT_W/2) + 42),(steps*4)+10, text_update, screen, NULL);

	text_update = TTF_RenderText_Solid( font, "Quit", textColor ); 
	BlitSurface((TPosX - (BUTT_W/2) + 60),(steps*5)+10, text_update, screen, NULL);

	SDL_Flip(screen);

	return 0;

}

int menu_exec(int pos, SDL_Surface* screen, Input* in){
	if(pos == 5){
		printf("Exit: MENU_QUIT\n");
		game_Quit(1);
    exit(1);
	}

  if(pos == 1){
    printf("MENU_NEWGAME\n");
    gstatus = 2;
    return 2;
  }

	return 0;
}

int menu(SDL_Surface *screen, Input* in, str_game_Head* menu_head){
  int menu;
  while(!in->key[SDLK_ESCAPE] || !in->quit){
    UpdateEvents(in);
    if((menu = menu_event(screen,in,menu_head)))
      return menu;
  }
  return 0;
}

