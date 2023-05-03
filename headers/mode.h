#pragma once 
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include "Global.h"
using namespace std ;

extern SDL_Renderer *renderer ;
extern bool running ;

void modegame(string &mode) ;
