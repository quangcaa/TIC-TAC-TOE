#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include <iostream>
#include "global.h"

using namespace std ;

extern SDL_Renderer *renderer ;
extern TTF_Font *font ;
extern int x_score ;
extern int o_score ;

void scoring() ;