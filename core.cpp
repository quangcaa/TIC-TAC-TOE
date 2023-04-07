#include "core.h"

void initSDL()
{
    SDL_Init(SDL_INIT_EVERYTHING) ;
    IMG_Init(IMG_INIT_PNG) ;
    TTF_Init() ;
    window = SDL_CreateWindow("Tic Tac Toe" , SDL_WINDOWPOS_CENTERED , SDL_WINDOWPOS_CENTERED , SCREEN_WIDTH , SCREEN_HEIGHT , SDL_WINDOW_SHOWN) ;
    renderer = SDL_CreateRenderer(window, -1, 0) ;
} 

void resetBoard()
{
    for (int i=0 ; i<3 ; i++)
    {
        for (int j=0 ; j<3 ; j++)
        {
            board[i][j] = Player::None;
        }
    }
}

void closeSDL()
{
    SDL_DestroyRenderer(renderer) ;
    SDL_DestroyWindow(window) ;

    IMG_Quit() ;
    SDL_Quit() ;
}

void loadIcon()
{
    SDL_Surface *icon = IMG_Load("image/icon.png") ; //load the icon image

    SDL_SetWindowIcon(window, icon) ; //set the icon of the window

    SDL_FreeSurface(icon) ; //free 
}