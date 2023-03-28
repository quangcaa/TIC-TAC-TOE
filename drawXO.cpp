#include "drawXO.h"

void drawX(SDL_Renderer *renderer , int x , int y , int size)
{
    SDL_SetRenderDrawColor(renderer, 255 , 255 , 255 , 255) ; //set color X (white)

    SDL_RenderDrawLine(renderer, x+25 , y+25, x+size-25 , y+size-25) ; //draw diagonal lines offset to
    SDL_RenderDrawLine(renderer, x+size-25 , y+25 , x+25 , y+size-25) ; //avoid touching screen edges

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255) ; //set color back to default
}

void drawO(SDL_Renderer* renderer, int x, int y, int size)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255) ; //set color O (white)

    int centerX = x + size/2 ; //find the center 
    int centerY = y + size/2 ; //of circle

    int radius = CELL_SIZE / 2 - 20 ; //calculate radius (ban kinh) (value(20) == avoid touching screen edges)

    for (double angle=0 ; angle<=2*M_PI ; angle+=0.0001) //draw the circle using dots 
    {
        int dotX = centerX + radius * cos(angle) ; 
        int dotY = centerY + radius * sin(angle) ;

        SDL_RenderDrawPoint(renderer, dotX, dotY) ;
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255) ; //set color back to default
}