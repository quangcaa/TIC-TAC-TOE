#include "headers/gameOver.h"

bool checkTie()
{
    for(int i=0 ; i<BOARD_SIZE ; i++)
    {
        for (int j=0 ; j<BOARD_SIZE ; j++)
        {
            if (board[i][j] == Player::None)
            {
                return false ;
            }
        }
    }
    return true ;
}

bool checkWin(Player player)
{
    for(int i=0 ; i<BOARD_SIZE ; i++) //check rows for win
    {
        for(int j=0 ; j<BOARD_SIZE-WIN_SIZE ; j++)
        {
            if(board[i][j] == player)
            {
                bool win = true ;
                for(int k=1 ; k<WIN_SIZE ; k++)
                {
                    if(board[i][j+k] != player)
                    {
                        win = false ;
                        break ;
                    }
                }
                if(win)
                {
                    return true ;
                }
            }
        }
    }

    //check columns
    for(int j=0 ; j<BOARD_SIZE ; j++)
    {
        for(int i=0 ; i<BOARD_SIZE-WIN_SIZE ; i++)
        {
            if(board[i][j] == player)
            {
                bool win = true ;
                for(int k=1 ; k<WIN_SIZE ; k++)
                {
                    if(board[i+k][j] != player)
                    {
                        win = false ;
                        break ;
                    }
                }
                if(win)
                {
                    return true ;
                }
            }
        }
    }

    for(int i=0 ; i<BOARD_SIZE-WIN_SIZE ; i++) //check main diagonal
    {
        for(int j=0 ; j<BOARD_SIZE-WIN_SIZE ; j++)
        {
            bool win = true ;
            for(int k=1 ; k<WIN_SIZE ; k++)
            {
                if (board[i+k][j+k] != player)
                {
                    win = false ;
                    break ;
                }
            }
            if(win)
            {
                return true ;
            }
        }
    }

    for(int i=0 ; i<BOARD_SIZE-WIN_SIZE ; i++) //check anti diagonal
    {
        for(int j=WIN_SIZE-1 ; j<BOARD_SIZE ; j++)
        {
            bool win = true ;
            for(int k=0 ; k<WIN_SIZE ; k++)
            {
                if(board[i+k][j-k] != player)
                {
                    win = false ;
                    break ;
                }
            }
            if(win)
            {
                return true ;
            }
        }
    }

    return false ;
}
