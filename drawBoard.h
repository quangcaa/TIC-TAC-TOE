#ifndef DRAWBOARD_H
#define DRAWBOARD_H
#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <sstream>
#include <cmath>
#include "player.h"

using namespace std ;

extern const int BOARD_SIZE ;
extern const int SCREEN_HEIGHT ;
extern const int SCREEN_WIDTH ;
extern Player board[3][3] ;  

void drawBoard() ;

#endif
