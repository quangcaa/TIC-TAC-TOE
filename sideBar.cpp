#include "sideBar.h"

void homeBut()
{
    SDL_Surface* image = IMG_Load("image/home_button.png") ;
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer , image) ;
    SDL_FreeSurface(image) ;

    SDL_Rect rBut = {0 , BOARD_HEIGHT+2 , RETURN_BUTTON_SIZE , RETURN_BUTTON_SIZE} ;
    SDL_RenderCopy(renderer , texture , NULL , &rBut) ;

    SDL_DestroyTexture(texture) ;
}

void scoreBoard()
{
    SDL_Surface* image = IMG_Load("image/score_board.png") ;
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer , image) ;
    SDL_FreeSurface(image) ;

    SDL_Rect sB = {(SCREEN_WIDTH/2)-100 , BOARD_HEIGHT+2 , SCORE_BOARD_WIDTH , SCORE_BOARD_HEIGHT} ;
    SDL_RenderCopy(renderer , texture , NULL , &sB) ;

    SDL_DestroyTexture(texture) ;
}

void resetScore()
{
    SDL_Surface* image = IMG_Load("image/reset_button.png") ;
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer , image) ;
    SDL_FreeSurface(image) ;

    SDL_Rect rS = {SCREEN_WIDTH-56 , BOARD_HEIGHT+2 , RESET_SCORE_SIZE , RESET_SCORE_SIZE} ;
    SDL_RenderCopy(renderer , texture , NULL , &rS) ;

    SDL_DestroyTexture(texture) ;
}