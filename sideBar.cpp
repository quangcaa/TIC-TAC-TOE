#include "sideBar.h"

void returnBut()
{
    SDL_Surface* image = IMG_Load("image/return_button.png") ;
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer , image) ;
    SDL_FreeSurface(image) ;

    SDL_Rect rBut = {0 , BOARD_HEIGHT+2 , RETURN_BUTTON_SIZE , RETURN_BUTTON_SIZE} ;
    SDL_RenderCopy(renderer , texture , NULL , &rBut) ;

    SDL_DestroyTexture(texture) ;
}