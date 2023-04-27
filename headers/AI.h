#pragma once
#include "gameOver.h"
#include "player.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

extern Player board[][15];

const int MAX_SCORE = 1000;
const int MIN_SCORE = -1000;

int evaluate(Player board[][15])
{
    Player player = Player::O ;
    Player opponent = Player::X;

    // Check rows for win
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j <= BOARD_SIZE - WIN_SIZE; j++)
        {
            int countPlayer = 0, countOpponent = 0;
            for (int k = j; k < j + WIN_SIZE; k++)
            {
                if (board[i][k] == player)
                {
                    countPlayer++;
                }
                else if (board[i][k] == opponent)
                {
                    countOpponent++;
                }
            }
            if (countPlayer == WIN_SIZE)
            {
                return MAX_SCORE;
            }
            else if (countOpponent == WIN_SIZE)
            {
                return MIN_SCORE;
            }
        }
    }

    // Check columns for win
    for (int j = 0; j < BOARD_SIZE; j++)
    {
        for (int i = 0; i <= BOARD_SIZE - WIN_SIZE; i++)
        {
            int countPlayer = 0, countOpponent = 0;
            for (int k = i; k < i + WIN_SIZE; k++)
            {
                if (board[k][j] == player)
                {
                    countPlayer++;
                }
                else if (board[k][j] == opponent)
                {
                    countOpponent++;
                }
            }
            if (countPlayer == WIN_SIZE)
            {
                return MAX_SCORE;
            }
            else if (countOpponent == WIN_SIZE)
            {
                return MIN_SCORE;
            }
        }
    }

    // Check diagonal from top-left to bottom-right for win
    for (int i = 0; i <= BOARD_SIZE - WIN_SIZE; i++)
    {
        for (int j = 0; j <= BOARD_SIZE - WIN_SIZE; j++)
        {
            int countPlayer = 0, countOpponent = 0;
            for (int k = 0; k < WIN_SIZE; k++)
            {
                if (board[i + k][j + k] == player)
                {
                    countPlayer++;
                }
                else if (board[i + k][j + k] == opponent)
                {
                    countOpponent++;
                }
            }
            if (countPlayer == WIN_SIZE)
            {
                return MAX_SCORE;
            }
            else if (countOpponent == WIN_SIZE)
            {
                return MIN_SCORE;
            }
        }
    }

    // Check diagonal from top-right to bottom-left for win
    for (int i = 0; i <= BOARD_SIZE - WIN_SIZE; i++)
    {
        for (int j = WIN_SIZE - 1; j < BOARD_SIZE; j++)
        {
            int countPlayer = 0, countOpponent = 0;
            for (int k = 0; k < WIN_SIZE; k++)
            {
                if (board[i + k][j - k] == player)
                {
                    countPlayer++;
                }
                else if (board[i + k][j - k] == opponent)
                {
                    countOpponent++;
                }
                if (countPlayer == WIN_SIZE)
                {
                    return MAX_SCORE;
                }
                else if (countOpponent == WIN_SIZE)
                {
                    return MIN_SCORE;
                }
            }
        }

        return 0;
    }
}

int evaluate1() {
    if (checkWin(Player::O)) {
        return MAX_SCORE; // player wins, return maximum value
    }
    if (checkWin(Player::X)) {
        return MIN_SCORE; // opponent wins, return minimum value
    }
    int score = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == Player::O) {
                score += 10; // add points for own pieces on board
            } else if (board[i][j] == Player::X) {
                score -= 10; // subtract points for opponent pieces on board
            }
        }
    }
    return score;
}

int minimax(Player board[][15] , int depth , bool is_maximizing , int alpha , int beta)
{
    int score = evaluate(board) ;

    if (score == MAX_SCORE || score == MIN_SCORE)
    { 
        return score ;
    }
    if(checkTie())
    {
        return 0 ;
    }
    if(depth == 0)
    {
        return score ;
    }

    // if(checkWin(Player::X))
    // {
    //     return -1 ;
    // }
    // else if(checkWin(Player::O))
    // {
    //     return 1 ;
    // }
    // else if(checkTie())
    // {
    //     return 0 ;
    // }


    if(is_maximizing)
    {
        int best_score = MIN_SCORE ;
        for(int i=0 ; i<BOARD_SIZE ; i++)
        {
            for(int j=0 ; j<BOARD_SIZE ; j++)
            {
                if(board[i][j] == Player::None)
                {
                    board[i][j] = Player::O ;
                    best_score = max(best_score, minimax(board , depth-1 , false , alpha , beta)) ;
                    board[i][j] = Player::None ;

                    alpha = max(alpha, best_score) ;
                    if(beta <= alpha) 
                    {
                        break ;
                    }
                }
            }
        }
        return best_score ;
    }
    else
    {
        int best_score = MAX_SCORE ;
        for(int i=0 ; i<BOARD_SIZE ; i++)
        {
            for(int j=0 ; j<BOARD_SIZE ; j++)
            {
                if(board[i][j] == Player::None)
                {
                    board[i][j] = Player::X ;
                    best_score = min(best_score , minimax(board , depth-1 , true , alpha , beta)) ;
                    board[i][j] = Player::None ;

                    beta = min(beta , best_score) ;
                    if(beta <= alpha)
                    {
                        break ;
                    }
                }
            }
        }
        return best_score ;
    }
}

pair<int,int> get_best_move(Player board[][15])
{
    int best_score = MIN_SCORE ;
    pair<int,int> best_move ;

    for(int i=0 ; i<BOARD_SIZE ; i++)
    {
        for(int j=0 ; j<BOARD_SIZE ; j++)
        {
            if(board[i][j] == Player::None)
            {
                board[i][j] = Player::O ;
                int score = minimax(board , 2 , false , MIN_SCORE , MAX_SCORE) ;
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
