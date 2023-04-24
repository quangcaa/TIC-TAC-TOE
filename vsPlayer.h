#pragma once

#include <SDL.h>
#include <iostream>
#include <cmath>
#include "checkTie.h"
#include "checkWin.h"
#include "core.h"
#include "displayResImage.h"
#include "global.h"
using namespace std ;

extern Player board[][3] ;

void handleVsPlayer(SDL_Event event) ;
