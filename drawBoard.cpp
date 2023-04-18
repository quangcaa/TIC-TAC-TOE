#include "drawBoard.h"

void drawBoard()
{
    SDL_SetRenderDrawColor(renderer, 153 , 102 , 203 , 255) ; //background color
    SDL_RenderClear(renderer) ;

    SDL_SetRenderDrawColor(renderer , 111 , 45 , 168 , 255) ; //line color

    for (int i=1 ; i<BOARD_SIZE ; i++) //draw line
    {
        for(int j=-2 ; j<=2 ; j++) //draw line with width 5 pixel
        {
            SDL_RenderDrawLine(renderer , i*CELL_SIZE+j , 0 , i*CELL_SIZE+j , SCREEN_HEIGHT) ; //column 
            SDL_RenderDrawLine(renderer, 0, i*CELL_SIZE+j , SCREEN_WIDTH , i*CELL_SIZE+j ) ; //row 
        }
    }

    for(int i=0 ; i<BOARD_SIZE ; i++) //draw objects on board
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