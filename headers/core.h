#pragma once 
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include "Global.h"

extern SDL_Window *window ;
extern SDL_Renderer *renderer ;
extern Player board[][15] ;

void initSDL() ;
void resetBoard() ;
void loadIcon() ;
void closeSDL() ;