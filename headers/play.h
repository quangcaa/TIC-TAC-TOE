#pragma once 
#include <SDL.h>
#include <iostream>
#include "core.h"
#include "display.h"
#include "gameOver.h"
#include "global.h"

extern Player board[][15] ;

void handleVsComputer(SDL_Event event) ;
void handleVsPlayer(SDL_Event event) ;
