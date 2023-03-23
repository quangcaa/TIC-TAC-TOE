#include "checkDraw.h"

int checkDraw(Player player , Player board[][3])
{
    int turn = 0 ;
    for(int i=0 ; i<3 ; i++)
    {
        for (int j=0 ; j<3 ; j++)
        {
            if (board[i][j] == player)
            {
                turn ++ ;
            }
        }
    }
    return turn ;
}