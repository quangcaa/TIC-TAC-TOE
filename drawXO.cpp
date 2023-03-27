#include "drawXO.h"

void drawX(SDL_Renderer* renderer, int x, int y, int size)
{
    SDL_SetRenderDrawColor(renderer, 255 , 255 , 255 , 255) ; //set color X

    //draw diagonal lines offset to avoid touching screen edges
    SDL_RenderDrawLine(renderer, x+25 , y+25, x+size-1-25 , y+size-1-25) ;
    SDL_RenderDrawLine(renderer, x+size-1-25 , y+25 , x+25 , y+size-1-25) ;

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255) ; //set color back to default
}

void drawO(SDL_Renderer* renderer, int x, int y, int size)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255) ; //set color O

    //find the center of circle
    int centerX = x + size/2;
    int centerY = y + size/2;

    //cal radius
    int radius = CELL_SIZE / 2 - 20;

    //draw the circle using dots 
    for (double angle=0; angle<2*M_PI ; angle+=0.001)
    {
        int dotX = centerX + radius * cos(angle);
        int dotY = centerY + radius * sin(angle);

        SDL_RenderDrawPoint(renderer, dotX, dotY);
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); //set color back to default
}