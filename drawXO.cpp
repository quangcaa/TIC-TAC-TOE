#include "drawXO.h"

void drawX(SDL_Renderer* renderer, int x, int y, int size)
{
    //set color X
    SDL_SetRenderDrawColor(renderer, 255 , 255 , 255 , 255) ; // white

    //draw diagonal lines with specified width and offset to avoid touching window edges
    SDL_RenderDrawLine(renderer, x+25 , y+25, x+size-1-25 , y+size-1-25) ;
    SDL_RenderDrawLine(renderer, x+size-1-25 , y+25 , x+25 , y+size-1-25) ;

    //set color back to default
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}


void drawO(SDL_Renderer* renderer, int x, int y, int size)
{
    //set color O 
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255) ; // white

    //find the center of circle
    int centerX = x + size/2;
    int centerY = y + size/2;

    //cal radius
    int radius = CELL_SIZE / 2 - 20;

    //draw the circle using dots 
    for (double angle=0; angle<2*M_PI ; angle+=0.01)
    {
        int dotX = centerX + radius * cos(angle);
        int dotY = centerY + radius * sin(angle);

        SDL_RenderDrawPoint(renderer, dotX, dotY);
    }


    //set color back to default
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}