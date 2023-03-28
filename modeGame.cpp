#include "modeGame.h"

string modeGame()
{
    SDL_Surface* image = SDL_LoadBMP("image/mode_selection.bmp") ; //load the mode selection image

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer , image) ;
    SDL_FreeSurface(image) ;

    SDL_RenderCopy(renderer , texture , NULL , NULL) ;
    SDL_RenderPresent(renderer) ;

    //wait click the mouse
    bool clicked = false ;
    string gameMode = "" ;

    while (!clicked)
    {
        SDL_Event event ;
        SDL_PollEvent(&event) ;
        switch(event.type)
        {
            case(SDL_QUIT) :
            {
                running = false ;
                clicked = true ;
                break ;
            }
            case(SDL_MOUSEBUTTONDOWN) :
            {
                int x , y ;
                SDL_GetMouseState(&x, &y) ;
                if (x >= 160 && x <= 500 && y >= 341 && y <= 405) //vs_computer pos
                {
                    gameMode = "vs computer" ; 
                    clicked = true ;
                }
                else if (x >= 190 && x <= 431 && y >= 467 && y <= 490) //vs_player pos
                {
                    gameMode = "vs player" ; 
                    clicked = true ;
                }
                break ;
            }
            default :
            {
                break ;
            }
        }
    }

    SDL_DestroyTexture(texture);

    return gameMode ;
}