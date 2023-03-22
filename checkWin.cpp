#include "checkWin.h"

bool checkWin(Player player , Player board[][3])
{
    //Check rows
    for(int i=0 ; i<3 ; i++)
    {
        bool win = true ;
        for(int j=0; j<3 ; j++)
        {
            if(board[i][j] != player)
            {
                win = false;
                break;
            }
        }
        if(win)
        {
            return true;
        }
    }

    //Check columns
    for(int j=0 ; j<3 ; j++)
    {
        bool win = true;
        for(int i=0 ; i<3 ; i++)
        {
            if(board[i][j] != player)
            {
                win = false;
                break;
            }
        }
        if(win)
        {
            return true;
        }
    }

    //Check diagonal 1
    bool win = true;
    for(int i=0 ; i<3 ; i++)
    {
        if(board[i][i] != player)
        {
            win = false;
            break;
        }
    }
    if(win)
    {
        return true;
    }

    //Check diagonal 2
    win = true ;
    for(int i=0; i<3 ; i++)
    {
        if(board[i][3-i-1] != player)
        {
            win = false;
            break;
        }
    }
    if(win)
    {
        return true;
    }

    return false;
}
