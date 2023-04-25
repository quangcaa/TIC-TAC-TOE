#include "displayResImage.h"

void displayResImage(int p)
{
    SDL_Surface *image ;
    if(p == 2)//load image for the winner
    {
        image = IMG_Load("image/Owin.png") ; 
    }
    else if(p == 1)
    {
        image = IMG_Load("image/Xwin.png") ;
    }
    else if(p == 0)
    {
        image = IMG_Load("image/tie.png") ;
    }

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer , image) ;
    SDL_FreeSurface(image) ;

    SDL_Rect result = {0 , 0 , BOARD_WIDTH , BOARD_HEIGHT} ;
    SDL_RenderCopy(renderer, texture, NULL, &result) ;
    SDL_RenderPresent(renderer) ;

    bool clicked = false ;
    while(!clicked)
    {
        SDL_Event event ;
        if(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT || event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
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
                else if(x>=SCREEN_WIDTH-56 && x<=SCREEN_WIDTH && y>=BOARD_HEIGHT+2 && y<=SCREEN_HEIGHT-2) //reset position
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
