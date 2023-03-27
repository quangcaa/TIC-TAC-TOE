#ifndef CORE_H
#define CORE_H
#include <SDL2/SDL.h>
#include <iostream>
#include <cmath>
#include "player.h"

extern SDL_Window *window ;
extern SDL_Renderer *renderer ;
extern const int SCREEN_WIDTH ;
extern const int SCREEN_HEIGHT ;
extern const int BOARD_SIZE ;
extern Player board[3][3] ;

void initSDL() ;
void resetBoard() ;
void loadIcon() ;
void closeSDL() ;

#endif