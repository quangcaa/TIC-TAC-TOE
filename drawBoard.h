#ifndef DRAWBOARD_H
#define DRAWBOARD_H
#include <SDL.h>
#include <iostream>
#include <cmath>
#include "player.h"

extern const int BOARD_SIZE ;
extern const int SCREEN_HEIGHT ;
extern const int SCREEN_WIDTH ;
extern Player board[3][3] ;

void drawBoard() ;

#endif
