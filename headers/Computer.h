#pragma once
#include <iostream>
#include "Global.h"
using namespace std ;

extern Player board[][15] ;

/*
    score_1 = row score
    score_2 = column score 
    score_3 = main diagonal 
    score_4 = anti diagonal 
*/

int score_1(int x , int y , Player player , Player board[][15]) ;
int score_2(int x , int y , Player player , Player board[][15]) ;
int score_3(int x , int y , Player player , Player board[][15]) ;
int score_4(int x , int y , Player player , Player board[][15]) ;
int checkNeighbor(int i , int j , Player board[][15]) ;
void best_move(Player board[][15]) ;
