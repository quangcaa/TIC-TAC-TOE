#pragma once 
#include <SDL.h>
#include <iostream>
#include <cmath>
#include "global.h"
#include "sideBar.h"

extern SDL_Renderer *renderer ;
extern Player board[][15] ;

void drawX(SDL_Renderer* renderer, int x, int y, int size) ;
void drawO(SDL_Renderer* renderer, int x, int y, int size) ;
void draw() ;

