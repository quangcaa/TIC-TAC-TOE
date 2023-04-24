#pragma once 

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <cmath>
#include "player.h"
#include "global.h"
#include "drawXO.h"
#include "sideBar.h"
#include "score.h"

extern SDL_Renderer *renderer ;
extern Player board[][3] ;

using namespace std ;

void draw() ;
