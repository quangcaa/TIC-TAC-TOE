#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include <string>
#include "Global.h"
using namespace std ;

extern SDL_Renderer *renderer ;
extern TTF_Font *font ;
extern int x_score , o_score ;
extern SDL_Texture *txHB , *txSB , *txRSB ;

void homeBut() ;
void scoreBoard() ;
void scoring() ;
void resetScore() ;