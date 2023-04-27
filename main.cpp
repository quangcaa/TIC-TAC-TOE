#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include "headers/core.h"
#include "headers/draw.h"
#include "headers/gameOver.h"
#include "headers/display.h"
#include "headers/mode.h"
#include "headers/play.h"
#include "headers/run.h"
using namespace std ;

SDL_Window *window = nullptr ;
SDL_Renderer *renderer = nullptr ;
TTF_Font *font = nullptr ;

Player board[15][15] ;

int x_score = 0 ;
int o_score = 0 ;

bool running = true ;

int main(int argc, char *argv[])
{
    initSDL();

    loadIcon() ;

    run() ;

    closeSDL();

    return 0 ;
}