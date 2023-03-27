#include "displayResImage.h"

void displayResImage(int p)
{
    SDL_Surface *image ;
    //load image for the winner
    if(p == 2)
    {
        image = SDL_LoadBMP("image/Owon.bmp") ; 
    }
    else if(p == 1)
    {
        image = SDL_LoadBMP("image/Xwon.bmp") ;
    }
    else if(p == 0)
    {
        image = SDL_LoadBMP("image/tie.bmp") ;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image) ;
    SDL_FreeSurface(image) ;

    SDL_RenderCopy(renderer, texture, NULL, NULL) ;
    SDL_RenderPresent(renderer) ;

    SDL_Delay(2000) ;

    SDL_DestroyTexture(texture) ;
}
