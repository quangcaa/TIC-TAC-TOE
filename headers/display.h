#pragma once 
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "mode.h"
#include "run.h"

extern SDL_Renderer *renderer ; 
extern SDL_Window *window ;
extern bool running ;

void displayResImage(int p) ;
