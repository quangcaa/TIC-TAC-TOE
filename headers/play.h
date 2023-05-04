#pragma once 
#include <SDL.h>
#include <iostream>
#include "Check.h"
#include "Computer.h"
#include "Draw.h"
#include "Result.h"
#include "Core.h"
#include "Global.h"
#include "Run.h"

extern bool running ;
extern int x_score , o_score ; 
extern Player board[][15] ;

extern bool clicked_home ;

void handleVsComputer(SDL_Event event) ;
void handleVsPlayer(SDL_Event event) ;