#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <sstream>
#include <iostream>
#include <cmath>
#include "player.h"
#include "global.h"

extern Player board[][3] ;

using namespace std ;

void handleVsPlayer(SDL_Event event) ;
