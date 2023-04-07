#ifndef DRAWXO_H
#define DRAWXO_H
#include <SDL.h>
#include <SDL_ttf.h>
#include <sstream>
#include <iostream>
#include <cmath>

using namespace std ;

extern SDL_Renderer *renderer ;
extern const int CELL_SIZE ;

void drawX(SDL_Renderer* renderer, int x, int y, int size) ;
void drawO(SDL_Renderer* renderer, int x, int y, int size) ;

#endif