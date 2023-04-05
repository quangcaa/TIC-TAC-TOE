#include "drawBoard.h"
#include "drawXO.h"

void drawBoard()
{
    //background color
    SDL_SetRenderDrawColor(renderer, 153 , 102 , 203 , 255) ; //HEX #9966cb
    SDL_RenderClear(renderer) ;

    //line color
    SDL_SetRenderDrawColor(renderer , 111 , 45 , 168 , 255) ; //HEX #6f2da8
    //draw line
    for (int i=1 ; i<BOARD_SIZE ; i++)
    {
        //draw line with width 5 pixel
        for(int j=-2 ; j<=2 ; j++)
        {
            SDL_RenderDrawLine(renderer , i*CELL_SIZE+j , 0 , i*CELL_SIZE+j , SCREEN_HEIGHT) ; //column 
        }
        for(int j=-2 ; j<=2 ; j++)
        {
            SDL_RenderDrawLine(renderer, 0, i*CELL_SIZE+j , SCREEN_WIDTH, i*CELL_SIZE+j) ; //row 
        }
    }

    for(int i=0 ; i<BOARD_SIZE ; i++)
    {
        for(int j=0 ; j<BOARD_SIZE ; j++)
        {
            if(board[i][j] == Player::X)
            {
                int cellX = i * CELL_SIZE ;
                int cellY = j * CELL_SIZE ;
                drawX(renderer , cellX , cellY , CELL_SIZE) ;
            }
            else if (board[i][j] == Player::O)
            {
                int cellX = i * CELL_SIZE ;
                int cellY = j * CELL_SIZE ;
                drawO(renderer , cellX , cellY , CELL_SIZE) ;
            }
        }
    }

    SDL_RenderPresent(renderer);
}