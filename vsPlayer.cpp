#include "vsPlayer.h"
#include "checkTie.h"
#include "checkWin.h"
#include "core.h"
#include "displayResImage.h"

void handleVsPlayer(SDL_Event event)
{
    static Player currentPlayer = Player::X ;

    if(event.type == SDL_QUIT)
    {
        running = false;
    }
    else if(event.type == SDL_MOUSEBUTTONDOWN)
    {
        int x , y ;
        SDL_GetMouseState(&x , &y) ; //get x , y coordinates 

        int cellX = x / CELL_SIZE ; //find cell 
        int cellY = y / CELL_SIZE ; //in board

        if(board[cellX][cellY] == Player::None)
        {
            board[cellX][cellY] = currentPlayer ; //set currentPlayer to empty cell
            if(checkWin(currentPlayer))
            {
                resetBoard() ;
                if(currentPlayer == Player::X)
                {                  
                    displayResImage(1) ;
                }
                else
                {
                    displayResImage(2) ;
                }
                currentPlayer = Player::X ; //set first player to X in new game 
            }
            else if(checkTie() == WIN_SIZE*WIN_SIZE)
            {
                resetBoard() ;
                displayResImage(0) ;
                currentPlayer = Player::X ; //set first player to X in new game 
            }
            else
            {
                currentPlayer = (currentPlayer == Player::X) ? Player::O : Player::X ;
            }
        }
        else if(x>=0 && x<=RETURN_BUTTON_SIZE && y>=BOARD_HEIGHT+2 && y<=SCREEN_HEIGHT-2)
        {
            resetBoard() ;
            currentPlayer = Player::X ; // set first player to X in new game
            run() ;
        }
    }
}