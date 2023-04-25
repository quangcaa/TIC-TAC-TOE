#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include <cmath>
#include "core.h"
#include "draw.h"
#include "checkWin.h"
#include "checkTie.h"
#include "drawXO.h"
#include "displayResImage.h"
#include "modeGame.h"
#include "vsComputer.h"
#include "vsPlayer.h"
#include "run.h"
#include "score.h"
using namespace std ;

SDL_Window *window = nullptr ;
SDL_Renderer *renderer = nullptr ;
TTF_Font *font = nullptr ;

Player board[3][3] ;

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