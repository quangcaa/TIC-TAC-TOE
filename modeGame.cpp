#include "modeGame.h"

string modeGame()
{
    SDL_Surface* image = SDL_LoadBMP("image/Cute1.bmp") ; //load the mode selection image

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer , image) ;
    SDL_FreeSurface(image) ;

    SDL_RenderCopy(renderer , texture , NULL , NULL) ;
    SDL_RenderPresent(renderer) ;

    //wait for the user to click the mouse
    bool clicked = false ;
    string gameMode = "" ;
    while (!clicked)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                running = false ;
                clicked = true ;
            }
            else if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                int x , y ;
                SDL_GetMouseState(&x, &y) ;
                if (x >= 160 && x <= 500 && y >= 341 && y <= 405) //vs_computer pos
                {
                    gameMode = "vs computer" ; 
                }
                else if (x >= 190 && x <= 431 && y >= 467 && y <= 490) //vs_player pos
                {
                    gameMode = "vs player" ; 
                }
                clicked = true ;
            }
        }
    }
    SDL_DestroyTexture(texture);


    if (gameMode == "vs computer")
    {
        return "vs computer" ;
    }
    else if (gameMode == "vs player")
    {
        return "vs player" ;
    }

    return "" ;
}