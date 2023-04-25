#include "score.h"

void scoring()
{
    font = TTF_OpenFont("font/score.ttf" , SCORE_HEIGHT) ; //load font 

    const char *x = to_string(x_score).c_str() ; // X
    SDL_Surface *scoreX_surface = TTF_RenderText_Solid(font , x , {255,255,255}) ; 
    SDL_Texture *scoreX_texture = SDL_CreateTextureFromSurface(renderer , scoreX_surface) ;
    SDL_FreeSurface(scoreX_surface) ;

    const char *o = to_string(o_score).c_str() ; // O
    SDL_Surface *scoreO_surface = TTF_RenderText_Solid(font , o , {255,255,255}) ; 
    SDL_Texture *scoreO_texture = SDL_CreateTextureFromSurface(renderer , scoreO_surface) ;
    SDL_FreeSurface(scoreO_surface) ;

    SDL_Rect scoreX_rect , scoreO_rect ;

    if(x_score < 10)
    {
        scoreX_rect = {(BOARD_WIDTH/2)-50-9 , BOARD_HEIGHT+2+21+2 , SCORE_WIDTH_1 , SCORE_HEIGHT} ;
    }
    else
    {
        scoreX_rect = {(BOARD_WIDTH/2)-50-18 , BOARD_HEIGHT+2+21+2 , SCORE_WIDTH_2 , SCORE_HEIGHT} ;
    }
    if(o_score < 10)
    {
        scoreO_rect = {(BOARD_WIDTH/2)+50-9 , BOARD_HEIGHT+2+21+2 , SCORE_WIDTH_1 , SCORE_HEIGHT} ;
    }
    else
    {
        scoreO_rect = {(BOARD_WIDTH/2)+50-18 , BOARD_HEIGHT+2+21+2 , SCORE_WIDTH_2 , SCORE_HEIGHT} ;
    }

    SDL_RenderCopy(renderer , scoreX_texture , NULL , &scoreX_rect) ;
    SDL_RenderCopy(renderer , scoreO_texture , NULL , &scoreO_rect) ;

    SDL_DestroyTexture(scoreX_texture) ;
    SDL_DestroyTexture(scoreO_texture) ;

    TTF_CloseFont(font) ;
}