#pragma once 
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "Core.h"
#include "Run.h"
 
extern SDL_Renderer *renderer ;
extern bool running ;
extern int x_score , o_score ;

void displayResImage(int p) ;
