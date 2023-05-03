#include "Headers/Result.h"

void displayResImage(int p)
{
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND) ; //set the blend mode to blend

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 128) ; //render a semi-transparent black rectangle over the board zone
    SDL_Rect rect = {0, 0, BOARD_WIDTH , BOARD_HEIGHT} ;
    SDL_RenderFillRect(renderer, &rect) ;

    SDL_Surface *image ;
    if(p == 2)//load result 
    {
        image = IMG_Load("Image/RS_O.png") ; 
    }
    else if(p == 1)
    {
        image = IMG_Load("Image/RS_X.png") ;
    }
    else if(p == 0)
    {
        image = IMG_Load("Image/RS_NN.png") ;
    }

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer , image) ;
    SDL_FreeSurface(image) ;

    SDL_Rect result = {BOARD_WIDTH/6 , BOARD_HEIGHT/4 , BOARD_WIDTH/6*4 , BOARD_HEIGHT/2} ;
    SDL_RenderCopy(renderer, texture, NULL, &result) ;
    SDL_RenderPresent(renderer) ;

    bool clicked = false ;
    while(!clicked)
    {
        SDL_Event event ;
        if(SDL_PollEvent(&event))
        {
            if(event.type==SDL_QUIT || event.key.keysym.scancode==SDL_SCANCODE_ESCAPE)
            {
                running = false ;
                clicked = true ;
                break ;
            }
            else if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                int x , y ;
                SDL_GetMouseState(&x , &y) ;

                if(x>=0 && x<=BOARD_WIDTH && y>=0 && y<=BOARD_HEIGHT)
                {
                    clicked = true ;
                    break ;
                }
                else if(x>=0 && x<=RETURN_BUTTON_SIZE && y>=BOARD_HEIGHT+2 && y<=SCREEN_HEIGHT-2) //home position
                {
                    run() ;
                }
                else if(x>=SCREEN_WIDTH-56-2 && x<=SCREEN_WIDTH && y>=BOARD_HEIGHT+2 && y<=SCREEN_HEIGHT-2) //reset position
                {
                    x_score = 0 ; 
                    o_score = 0 ;
                    resetBoard() ;

                    clicked = true ;
                    break ;
                }
            }
        }
    }

    SDL_DestroyTexture(texture) ;
}