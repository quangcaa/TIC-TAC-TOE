#include "Headers/Draw.h"

void drawX(SDL_Renderer *renderer , SDL_Texture *txX , int x , int y , int size)
{
    SDL_Rect Xrect = {x+2 , y+2 , 40 , 40 } ;
    SDL_RenderCopy(renderer , txX , nullptr , &Xrect) ;
}


void drawO(SDL_Renderer* renderer , SDL_Texture *txO , int x, int y, int size)
{
    SDL_Rect Orect = {x+2 , y+2 , 40 , 40 } ;
    SDL_RenderCopy(renderer , txO , nullptr , &Orect) ;
}


void draw()
{
    SDL_SetRenderDrawColor(renderer , 153 , 102 , 203 , 255) ; //background color
    SDL_RenderClear(renderer) ;

    SDL_SetRenderDrawColor(renderer , 111 , 45 , 168 , 255) ; //line color
    for(int i=0 ; i<=BOARD_SIZE ; i++) //draw line
    {
        if(i==0)
        {
            for(int j=0 ; j<3 ; j++) //draw line with width 3 pixel
            {
                SDL_RenderDrawLine(renderer , i*CELL_SIZE+j , 0 , i*CELL_SIZE+j , BOARD_HEIGHT) ; //column 
                SDL_RenderDrawLine(renderer , 0, i*CELL_SIZE+j , BOARD_WIDTH , i*CELL_SIZE+j) ;   //row 
            }
        }
        else if(i==BOARD_SIZE)
        {
            for(int j=-3 ; j<0 ; j++) //draw line with width 3 pixel
            {
                SDL_RenderDrawLine(renderer , i*CELL_SIZE+j , 0 , i*CELL_SIZE+j , BOARD_HEIGHT) ; //column 
                SDL_RenderDrawLine(renderer, 0, i*CELL_SIZE+j , BOARD_WIDTH , i*CELL_SIZE+j ) ;   //row 
            }
        }
        else
        {
            for(int j=-1 ; j<=1 ; j++) //draw line with width 3 pixel
            {
                SDL_RenderDrawLine(renderer , i*CELL_SIZE+j , 0 , i*CELL_SIZE+j , BOARD_HEIGHT) ; //column 
                SDL_RenderDrawLine(renderer, 0, i*CELL_SIZE+j , BOARD_WIDTH , i*CELL_SIZE+j ) ;   //row 
            }
        }
    }

    for(int i=0 ; i<BOARD_SIZE ; i++) //draw objects on board (X & O)
    {
        for(int j=0 ; j<BOARD_SIZE ; j++)
        {
            if(board[i][j] == Player::X)
            {
                int cellX = i * CELL_SIZE ; //get position
                int cellY = j * CELL_SIZE ; 
                drawX(renderer , txX , cellX , cellY , CELL_SIZE) ;
            }
            else if (board[i][j] == Player::O)
            {
                int cellX = i * CELL_SIZE ; //get position
                int cellY = j * CELL_SIZE ;
                drawO(renderer , txO , cellX , cellY , CELL_SIZE) ;
            }
        }
    }

    homeBut() ;
    scoreBoard() ;
    resetScore() ;
    scoring() ;

    SDL_RenderPresent(renderer) ; //update the screen
}