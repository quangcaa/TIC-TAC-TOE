#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include "Headers/Check.h"
#include "Headers/Computer.h"
#include "Headers/Core.h"
#include "Headers/Draw.h"
#include "Headers/Global.h"
#include "Headers/Mode.h"
#include "Headers/Play.h"
#include "Headers/Player.h"
#include "Headers/Result.h"
#include "Headers/Run.h"
#include "headers/SideBar.h"

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