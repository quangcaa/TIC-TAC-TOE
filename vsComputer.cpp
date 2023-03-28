#include "vsComputer.h"

void handleVsComputer(SDL_Event event)
{
    static Player currentPlayer = Player::X ; //set role
    static Player computer = Player::O ;      //set role

    if(currentPlayer == computer)
    {
        if (event.type == SDL_QUIT)
        {
            running = false;
        }
        else
        {
            int x , y ;
            do
            {
                x = rand() % BOARD_SIZE;
                y = rand() % BOARD_SIZE;
            } while(board[x][y] != Player::None) ;
            board[x][y] = computer ;
            if(checkWin(currentPlayer, board))
            {
                resetBoard() ;
                displayResImage(2) ;
                currentPlayer = Player::X ; //set first player to X in new game
            }
            else if(checkTie(Player::X, board) + checkTie(Player::O, board) == 9)
            {
                resetBoard() ;
                displayResImage(0) ;
                currentPlayer = Player::X ; //set first player to X in new game
            }
            currentPlayer = Player::X ;
        }
    }
    else
    {
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
                if(checkWin(currentPlayer, board))
                {
                    resetBoard() ;
                    displayResImage(1) ;
                    currentPlayer = Player::X ; // set first player to X in new game
                }
                else if(checkTie(Player::X, board) + checkTie(Player::O, board) == 9)
                {
                    resetBoard() ;
                    displayResImage(0) ;
                    currentPlayer = Player::X ; // set first player to X in new game
                }
                else
                {
                    currentPlayer = (currentPlayer == Player::X) ? Player::O : Player::X ;
                }
            }
        }
    }
}