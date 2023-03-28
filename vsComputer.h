#ifndef VSCOMPUTER_H
#define VSCOMPUTER_H
#include <SDL2/SDL.h>
#include <iostream>
#include <cmath>
#include "player.h"
#include "checkTie.h"
#include "checkWin.h"
#include "core.h"
#include "displayResImage.h"

extern const int CELL_SIZE ;
extern Player board[3][3] ;
extern bool running ;

void handleVsComputer(SDL_Event event) ;

#endif