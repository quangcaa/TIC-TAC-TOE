#include "core.h"

void initSDL()
{
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Tic Tac Toe" , SDL_WINDOWPOS_CENTERED , SDL_WINDOWPOS_CENTERED , SCREEN_WIDTH , SCREEN_HEIGHT , SDL_WINDOW_SHOWN) ;
    renderer = SDL_CreateRenderer(window, -1, 0);
}

void closeSDL()
{
    SDL_FreeSurface(icon) ;

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
}

void loadIcon()
{
    // Load the icon image
    icon = SDL_LoadBMP("image/icon.bmp");

    // Set the color key of the surface to transparent
    SDL_SetColorKey(icon, SDL_TRUE, SDL_MapRGB(icon->format, 255, 0, 255));

    // Set the icon of the window
    SDL_SetWindowIcon(window, icon);
}