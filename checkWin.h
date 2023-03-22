#ifndef CHECKWIN_H
#define CHECKWIN_H
#include <SDL2/SDL.h>
#include <iostream>
#include <cmath>

enum class Player ;

bool checkWin(Player player , Player board[][3]) ;

#endif