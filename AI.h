#pragma once
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include "player.h"
#include "checkTie.h"
#include "checkWin.h"
using namespace std ;

extern Player board[][3] ;

const int MAX_SCORE = 10 ;
const int MIN_SCORE = -10 ; 


int minimax(Player board[][3] , int depth, bool is_maximizer)
{
    if(checkWin(Player::X))
    {
        return -1 ;
    }
    else if(checkWin(Player::O))
    {
        return 1 ;
    }
    else if(checkTie()==9)
    {
        return 0 ;
    }


    if(is_maximizer)
    {
        int best_score = MIN_SCORE ;
        for(int i=0 ; i<3 ; i++)
        {
            for(int j=0 ; j<3 ; j++)
            {
                if(board[i][j] == Player::None)
                {
                    board[i][j] = Player::O ;
                    best_score = max(best_score, minimax(board , depth-1, false)) ;
                    board[i][j] = Player::None ;
                }
            }
        }
        return best_score ;
    }
    else
    {
        int best_score = MAX_SCORE ;
        for(int i=0 ; i<3 ; i++)
        {
            for(int j=0 ; j<3 ; j++)
            {
                if(board[i][j] == Player::None)
                {
                    board[i][j] = Player::X ;
                    best_score = min(best_score, minimax(board , depth-1 , true)) ;
                    board[i][j] = Player::None ;
                }
            }
        }
        return best_score ;
    }
}

pair<int,int> get_best_move(Player board[][3])
{
    int best_score = MIN_SCORE ;
    pair<int,int> best_move ;

    for(int i=0 ; i<3 ; i++)
    {
        for (int j=0 ; j<3 ; j++)
        {
            if (board[i][j] == Player::None)
            {
                board[i][j] = Player::O ;
                int score = minimax(board , 3 , false) ;
                board[i][j] = Player::None ;

                if(score > best_score)
                {
                    best_score = score ;
                    best_move = {i , j} ;
                }
            }
        }
    }

    return best_move ;
}
