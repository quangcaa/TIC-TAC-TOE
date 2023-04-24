#pragma once 

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include <cmath>
#include "global.h"

extern SDL_Renderer *renderer ;
extern SDL_Window *window ; 
extern Player board[][3] ;

void initSDL() ;
void resetBoard() ;
void loadIcon() ;
void closeSDL() ;
