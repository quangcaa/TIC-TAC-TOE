#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
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

const int SCREEN_WIDTH = 660 ;
const int SCREEN_HEIGHT = 660 ;
const int BOARD_SIZE = 3 ;
const int CELL_SIZE = 220 ;

SDL_Window *window = nullptr ;
SDL_Renderer *renderer = nullptr ;

Player board[3][3];

bool running = true;

int main(int argc, char *argv[])
{
    initSDL();

    loadIcon() ;

    resetBoard() ;

    run() ;

    closeSDL();

    return 0 ;
}