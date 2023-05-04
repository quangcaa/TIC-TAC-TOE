#pragma once 
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "SideBar.h"
#include "Global.h"

extern SDL_Renderer *renderer ;
extern Player board[][15] ;
extern SDL_Texture *txX , *txO ;

void drawX(SDL_Renderer* renderer , SDL_Texture *txX , int x , int y , int size) ;
void drawO(SDL_Renderer* renderer , SDL_Texture *txO , int x , int y , int size) ;
void draw() ;