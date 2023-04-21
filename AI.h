#pragma once

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include "player.h"

using namespace std ;

extern Player board[][3] ;

const int MAX_SCORE = 10 ;
const int TIE_SCORE = 0 ;
const int MIN_SCORE = -10 ; 

int evaluate_board(Player board[][3])
{
    for(int i=0 ; i<3 ; i++) //check rows
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            if(board[i][0] == Player::O)
            {
                return MAX_SCORE ;
            }
            else if(board[i][0] == Player::X)
            {
                return MIN_SCORE ;
            }
        }
    }

    for(int j=0 ; j<3 ; j++) //check columns
    {
        if(board[0][j] == board[1][j] && board[1][j] == board[2][j])
        {
            if (board[0][j] == Player::O)
            {
                return MAX_SCORE ;
            }
            else if (board[0][j] == Player::X)
            {
                return MIN_SCORE ;
            }
        }
    }

    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) //check diagonal 1
    {
        if(board[0][0] == Player::O)
        {
            return MAX_SCORE ;
        }
        else if(board[0][0] == Player::X)
        {
            return MIN_SCORE ;
        }
    }

    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) //check diagonal 2
    {
        if(board[0][2] == Player::O)
        {
            return MAX_SCORE ;
        }
        else if (board[0][2] == Player::X)
        {
            return MIN_SCORE ;
        }
    }

    return 0 ; //tie
}

int minimax(Player board[][3] , int depth, bool is_maximizer)
{
    int score = evaluate_board(board) ;
    if (score == MAX_SCORE || score == MIN_SCORE || depth == 0)
    {
        return score ;
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
