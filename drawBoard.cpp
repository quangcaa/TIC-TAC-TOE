#include "drawBoard.h"
#include "drawXO.h"

void drawBoard()
{
    //background color
    SDL_SetRenderDrawColor(renderer, 153 , 102 , 203 , 255) ;
    SDL_RenderClear(renderer) ;

    //line color
    SDL_SetRenderDrawColor(renderer , 111 , 45 , 168 , 255) ;
    //draw line
    for (int i=1 ; i<BOARD_SIZE ; i++)
    {
        //draw line with width (for)
        for(int j=0 ; j<=5 ; j++)
        {
            SDL_RenderDrawLine(renderer , i*CELL_SIZE+j , 0 , i*CELL_SIZE+j , SCREEN_HEIGHT) ;
        }
        for(int j=0 ; j<=5 ; j++)
        {
            SDL_RenderDrawLine(renderer, 0, i*CELL_SIZE+j , SCREEN_WIDTH, i*CELL_SIZE+j) ;
        }
    }

    for (int i=0 ; i<BOARD_SIZE ; i++)
    {
        for (int j=0 ; j<BOARD_SIZE ; j++)
        {
            if (board[i][j] == Player::X)
            {
                int cellX = i * CELL_SIZE ;
                int cellY = j * CELL_SIZE ;
                drawX(renderer, cellX, cellY, CELL_SIZE) ;
            }
            else if (board[i][j] == Player::O)
            {
                int cellX = i * CELL_SIZE ;
                int cellY = j * CELL_SIZE ;
                drawO(renderer, cellX, cellY, CELL_SIZE) ;
            }
        }
    }

    SDL_RenderPresent(renderer);
}