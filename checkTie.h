#ifndef CHECKTIE_H
#define CHECKTIE_H
#include <SDL2/SDL.h>
#include <iostream>
#include <cmath>

enum class Player ;

int checkTie(Player player , Player board[][3]) ;

#endif