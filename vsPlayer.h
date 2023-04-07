#ifndef VSPALYER_H
#define VSPLAYER_H
#include <SDL.h>
#include <SDL_ttf.h>
#include <sstream>
#include <iostream>
#include <cmath>
#include "player.h"

using namespace std ;

extern const int CELL_SIZE ;
extern Player board[3][3] ;
extern bool running ;

void handleVsPlayer(SDL_Event event) ;

#endif