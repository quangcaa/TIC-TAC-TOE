#include "checkTie.h"

int checkTie()
{
    int turn = 0 ;
    for(int i=0 ; i<BOARD_SIZE ; i++)
    {
        for (int j=0 ; j<BOARD_SIZE ; j++)
        {
            if (board[i][j] == Player::X || board[i][j] == Player::O)
            {
                turn ++ ;
            }
        }
    }
    return turn ;
}