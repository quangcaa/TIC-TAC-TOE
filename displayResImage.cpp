#include "displayResImage.h"
#include "modeGame.h"

void displayResImage(int p)
{
    SDL_Surface *image ;

    //load image for the winner
    if(p == 2)
    {
        image = IMG_Load("image/Owon_ct.png") ; 
    }
    else if(p == 1)
    {
        image = IMG_Load("image/Xwon_ct.png") ;
    }
    else if(p == 0)
    {
        image = IMG_Load("image/tie_ct.png") ;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image) ;
    SDL_FreeSurface(image) ;

    SDL_RenderCopy(renderer, texture, NULL, NULL) ;
    SDL_RenderPresent(renderer) ;

    bool clicked = false ;
    while(!clicked)
    {
        SDL_Event event ;
        if(SDL_PollEvent(&event))
        {
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
                    SDL_GetMouseState(&x , &y) ;
                    if(x>=245 && x<=313 && y>=429 && y<=487)
                    {
                        clicked = true ;
                        run() ;
                    }
                    else if(x>=340 && x<=413 && y>=429 && y<=487)
                    {
                        clicked = true ;
                        SDL_Delay(200) ;
                    }
                }
            }
        }
    }

    SDL_DestroyTexture(texture) ;
}