#ifndef DRAWXO_H
#define DRAWXO_H
#include <SDL2/SDL.h>
#include <iostream>
#include <cmath>

extern SDL_Renderer *renderer ;
extern const int CELL_SIZE ;

void drawX(SDL_Renderer* renderer, int x, int y, int size) ;
void drawO(SDL_Renderer* renderer, int x, int y, int size) ;

#endif