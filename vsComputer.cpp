#include "vsComputer.h"
#include "AI.h"

void handleVsComputer(SDL_Event event)
{
    static Player currentPlayer = Player::X ; //set role
    static Player computer = Player::O ;      //set role

    if(currentPlayer == computer)
    {
        if (event.type == SDL_QUIT)
        {
            running = false ;
        }
        else
        {
            pair<int,int> best = get_best_move(board) ;
            cout << best.first << " " << best.second << endl ;
            board[best.first][best.second] = computer ;
            if(checkWin(currentPlayer))
            {
                resetBoard() ;
                displayResImage(2) ;
                currentPlayer = Player::X ; //set first player to X in new game
            }
            else if(checkTie() == WIN_SIZE*WIN_SIZE)
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
            running = false ;
        }
        else if(event.type == SDL_MOUSEBUTTONDOWN)
        {
            int x , y ;
            SDL_GetMouseState(&x , &y) ; //get x , y coordinates 

            if(x>=0 && x<=BOARD_WIDTH && y>=0 && y<=BOARD_HEIGHT)
            {
                int cellX = x / CELL_SIZE ; //find cell
                int cellY = y / CELL_SIZE ; //in board

                if(board[cellX][cellY] == Player::None)
                {
                    board[cellX][cellY] = currentPlayer ; //set currentPlayer to empty cell
                    if(checkWin(currentPlayer))
                    {
                        resetBoard() ;
                        displayResImage(1) ;
                        currentPlayer = Player::X ; // set first player to X in new game
                    }
                    else if(checkTie() == WIN_SIZE*WIN_SIZE)
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
            else if(x>=0 && x<=RETURN_BUTTON_SIZE && y>=BOARD_HEIGHT+2 && y<=SCREEN_HEIGHT-2)
            {
                resetBoard() ;
                currentPlayer = Player::X ; // set first player to X in new game
                run() ;
            }
        }
    }
}