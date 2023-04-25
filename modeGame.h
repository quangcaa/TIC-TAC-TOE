#pragma once 

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <iostream>
#include <cmath>
#include <string>
#include "global.h"
using namespace std ;

extern SDL_Renderer *renderer ; 
extern bool running ;

void modegame(string &mode) ;
