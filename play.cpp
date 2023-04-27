#include "headers/play.h"
#include "headers/AI.h"

void handleVsComputer(SDL_Event event)
{
    static Player currentPlayer = Player::X ; //set role
    static Player computer = Player::O ;      //set role

    if(currentPlayer == computer)
    {
        if(event.type == SDL_QUIT || event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) //quit game
        {
            running = false ;
        }
        else
        {
            pair<int,int> best = get_best_move(board) ;
            board[best.first][best.second] = computer ;

            if(checkWin(currentPlayer))
            {
                resetBoard() ; //clear board
                o_score += 1 ; //update score
                displayResImage(2) ; //show result
                currentPlayer = Player::X ; //set for new round
            }
            else if(checkTie() == BOARD_SIZE*BOARD_SIZE)
            {
                resetBoard() ; //clear board 
                displayResImage(0) ; //show result
                currentPlayer = Player::X ; //set for new round
            }
            else
            {
                currentPlayer = Player::X ; //round isnt over , continue
            }
        }
    }
    else
    {
        if(event.type == SDL_QUIT || event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) // quit game
        {
            running = false ;
        }
        else if(event.type == SDL_MOUSEBUTTONDOWN)
        {
            int x , y ;
            SDL_GetMouseState(&x , &y) ; //get x , y coordinates 

            if(x>=0 && x<=BOARD_WIDTH && y>=0 && y<=BOARD_HEIGHT) //valid position
            {
                int cellX = x / CELL_SIZE ; //find cell
                int cellY = y / CELL_SIZE ; //in board

                if(board[cellX][cellY] == Player::None)
                {
                    board[cellX][cellY] = currentPlayer ; //set currentPlayer to empty cell

                    if(checkWin(currentPlayer))
                    {
                        resetBoard() ;
                        x_score += 1 ;
                        displayResImage(1) ;
                        currentPlayer = Player::X ;
                    }
                    else if(checkTie() == BOARD_SIZE*BOARD_SIZE)
                    {
                        resetBoard() ;
                        displayResImage(0) ;
                        currentPlayer = Player::X ;
                    }
                    else
                    {
                        currentPlayer = Player::O ;
                    }
                }
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
                currentPlayer = Player::X ;
            }
        }
    }
}


void handleVsPlayer(SDL_Event event)
{
    static Player currentPlayer = Player::X ;

    if(event.type == SDL_QUIT || event.key.keysym.sym == SDL_SCANCODE_ESCAPE)
    {
        running = false ;
    }
    else if(event.type == SDL_MOUSEBUTTONDOWN)
    {
        int x , y ;
        SDL_GetMouseState(&x , &y) ; //get x , y coordinates 

        if(x>=0 && x<=BOARD_WIDTH && y>=0 && y<=BOARD_HEIGHT) //valid position
        {
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
                        x_score += 1 ;
                        displayResImage(1) ;
                    }
                    else
                    {
                        o_score += 1 ;
                        displayResImage(2) ;
                    }
                
                    currentPlayer = Player::X ; //set first player to X in new game 
                }
                else if(checkTie() == BOARD_SIZE*BOARD_SIZE)
                {
                    resetBoard() ;
                    displayResImage(0) ;
                    currentPlayer = Player::X ;
                }
                else
                {
                    currentPlayer = (currentPlayer == Player::X) ? Player::O : Player::X ; //round isnt over , continue
                }
            }
        }
        else if(x>=0 && x<=RETURN_BUTTON_SIZE && y>=BOARD_HEIGHT+2 && y<=SCREEN_HEIGHT-2) //home position
        {
            currentPlayer = Player::X ;
            run() ;
        }
        else if(x>=SCREEN_WIDTH-56 && x<=SCREEN_WIDTH && y>=BOARD_HEIGHT+2 && y<=SCREEN_HEIGHT-2) //reset position
        {
            x_score = 0 ; 
            o_score = 0 ;
            resetBoard() ;
            currentPlayer = Player::X ;
        }
    }
}