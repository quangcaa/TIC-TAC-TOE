#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

using namespace std;

const int WIDTH = 900;
const int HEIGHT = 600;

int main(int argc, char *args[])
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << endl;
        return 1;
    }

    // Initialize SDL_image
    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
    {
        cout << "Failed to initialise SDL_image for PNG files: " << IMG_GetError() << endl;
        return 1;
    }

    // Load PNG image
    SDL_Surface* surface = IMG_Load("icon.png");
    if (!surface)
    {
        cout << "IMG_Load Error: " << IMG_GetError() << endl;
        return 1;
    }

    //Create window
    SDL_Window *window = SDL_CreateWindow("GAMESDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if (!window)
    {
        cout << "SDL_CreateWindow Error: " << SDL_GetError() << endl ;
        return 1 ;
    }

    //Create renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window , -1 , SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC) ;
    if(!renderer)
    {
        cout << "SDL_CreateRenderer Error: " << SDL_GetError() << endl ;
        return 1 ;
    }

    //Create texture from surface
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface) ;
    if (!texture) {
        cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << endl;
        return 1;
    }   

    // Clear screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    //Draw texture
    SDL_RenderCopy(renderer , texture , NULL , NULL ) ;

    //Update screen
    SDL_RenderPresent(renderer) ;

    //Wait for user to quit
    bool quit = false ;
    SDL_Event event ;
    while (!quit)
    {
        if (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit == true ;
            }
        }
    }

    SDL_DestroyTexture(texture) ;
    SDL_DestroyRenderer(renderer) ;
    SDL_DestroyWindow(window) ;
    SDL_FreeSurface(surface) ;
    IMG_Quit() ;
    SDL_Quit() ;

    return 0;
}