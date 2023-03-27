#include "core.h"

void initSDL()
{
    SDL_Init(SDL_INIT_VIDEO) ;
    window = SDL_CreateWindow("Tic Tac Toe" , SDL_WINDOWPOS_CENTERED , SDL_WINDOWPOS_CENTERED , SCREEN_WIDTH , SCREEN_HEIGHT , SDL_WINDOW_SHOWN) ;
    renderer = SDL_CreateRenderer(window, -1, 0);
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
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
}

void loadIcon()
{
    SDL_Surface *icon = SDL_LoadBMP("image/icon.bmp"); //load the icon image

    SDL_SetColorKey(icon, SDL_TRUE, SDL_MapRGB(icon->format, 255, 0, 255)); //set the color key of the surface to transparent

    SDL_SetWindowIcon(window, icon); //set the icon of the window

    SDL_FreeSurface(icon) ; //free 
}