#ifndef CORE_H
#define CORE_H
#include <SDL2/SDL.h>
#include <iostream>
#include <cmath>

enum class Player ;
extern SDL_Window *window ;
extern SDL_Renderer *renderer ;
extern SDL_Surface *icon ;
extern const int SCREEN_WIDTH ;
extern const int SCREEN_HEIGHT ;
extern const int BOARD_SIZE ;

void initSDL() ;
void loadIcon() ;
void closeSDL() ;

#endif