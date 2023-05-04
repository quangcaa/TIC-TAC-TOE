#include "Headers/Core.h"

void initSDL()
{
    SDL_Init(SDL_INIT_EVERYTHING) ;
    IMG_Init(IMG_INIT_PNG) ;
    TTF_Init() ;
    window = SDL_CreateWindow("Tic Tac Toe" , SDL_WINDOWPOS_CENTERED , SDL_WINDOWPOS_CENTERED , SCREEN_WIDTH , SCREEN_HEIGHT , SDL_WINDOW_SHOWN) ;
    renderer = SDL_CreateRenderer(window, -1, 0) ;

    SDL_Surface *X = IMG_Load("Image/IM_X.png");
    SDL_Surface *O = IMG_Load("Image/IM_O.png");
    SDL_Surface *HB = IMG_Load("Image/SB_Home.png") ;
    SDL_Surface *SB = IMG_Load("Image/SB_ScoreBoard.png") ;
    SDL_Surface *RSB = IMG_Load("Image/SB_Reset.png") ;
    txX = SDL_CreateTextureFromSurface(renderer, X);
    txO = SDL_CreateTextureFromSurface(renderer, O);
    txHB = SDL_CreateTextureFromSurface(renderer, HB) ;
    txSB = SDL_CreateTextureFromSurface(renderer, SB) ;
    txRSB = SDL_CreateTextureFromSurface(renderer, RSB) ;
    SDL_FreeSurface(X) ;
    SDL_FreeSurface(O) ;
    SDL_FreeSurface(HB) ;
    SDL_FreeSurface(SB) ;
    SDL_FreeSurface(RSB) ;
} 

void resetBoard()
{
    for (int i=0 ; i<BOARD_SIZE ; i++)
    {
        for (int j=0 ; j<BOARD_SIZE ; j++)
        {
            board[i][j] = Player::None ;
        }
    }
}

void closeSDL()
{
    SDL_DestroyRenderer(renderer) ;
    SDL_DestroyWindow(window) ;
    SDL_DestroyTexture(txX) ;
    SDL_DestroyTexture(txO) ;
    SDL_DestroyTexture(txHB) ;
    SDL_DestroyTexture(txSB) ;
    SDL_DestroyTexture(txRSB) ;

    IMG_Quit() ;
    TTF_Quit() ;
    SDL_Quit() ;
}

void loadIcon()
{
    SDL_Surface *icon = IMG_Load("Image/Icon.png") ; //load the icon image

    SDL_SetWindowIcon(window, icon) ; //set the icon of the window

    SDL_FreeSurface(icon) ; //free 
}