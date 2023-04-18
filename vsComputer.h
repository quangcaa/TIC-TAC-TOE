#pragma once 

#include <SDL.h>
#include <iostream>
#include <cmath>
#include "player.h"
#include "checkTie.h"
#include "checkWin.h"
#include "core.h"
#include "displayResImage.h"
#include "global.h"

extern Player board[][3] ;

void handleVsComputer(SDL_Event event) ;
