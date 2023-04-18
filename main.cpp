#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <iostream>
#include <cmath>
#include <thread>
#include <chrono>

#include "player.h"
#include "core.h"
#include "drawBoard.h"
#include "checkWin.h"
#include "checkTie.h"
#include "drawXO.h"
#include "displayResImage.h"
#include "modeGame.h"
#include "vsComputer.h"
#include "vsPlayer.h"
#include "run.h"

using namespace std ;

SDL_Window *window = nullptr ;
SDL_Renderer *renderer = nullptr ;
TTF_Font *font = nullptr ;

Player board[3][3] ;

bool running = true ;

int main(int argc, char *argv[])
{
    initSDL();

    loadIcon() ;

    resetBoard() ;

    run() ;

    closeSDL();

    return 0 ;
}