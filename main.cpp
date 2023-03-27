#include <SDL2/SDL.h>
#include <iostream>
#include <cmath>

//#include "player.h"
#include "core.h"
#include "drawBoard.h"
#include "checkWin.h"
#include "checkTie.h"
#include "drawXO.h"
#include "displayResImage.h"

using namespace std ;

const int SCREEN_WIDTH = 660 ;
const int SCREEN_HEIGHT = 660 ;
const int BOARD_SIZE = 3 ;
const int CELL_SIZE = 220 ;

SDL_Window *window = nullptr ;
SDL_Renderer *renderer = nullptr ;
SDL_Surface *icon = nullptr ;

enum class Player
{
    None,
    X,
    O
};

Player board[3][3];

bool running = true;

void resetBoard()
{
    for (int i=0 ; i<BOARD_SIZE ; i++)
    {
        for (int j=0 ; j<BOARD_SIZE ; j++)
        {
            board[i][j] = Player::None;
        }
    }
}


void drawBoard()
{
    //background color
    SDL_SetRenderDrawColor(renderer, 153 , 102 , 203 , 255) ;
    SDL_RenderClear(renderer) ;

    //line color
    SDL_SetRenderDrawColor(renderer , 111 , 45 , 168 , 255) ;
    //draw line
    for (int i = 1; i < BOARD_SIZE; i++)
    {
        //line width 
        for(int j=0 ; j<=5 ; j++)
        {
            SDL_RenderDrawLine(renderer , i * CELL_SIZE + j , 0 , i * CELL_SIZE + j , SCREEN_HEIGHT) ;
        }

        for(int j=0 ; j<=5 ; j++)
        {
            SDL_RenderDrawLine(renderer, 0, i * CELL_SIZE + j , SCREEN_WIDTH, i * CELL_SIZE + j);
        }
    }

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == Player::X)
            {
                int cellX = i * CELL_SIZE;
                int cellY = j * CELL_SIZE;
                drawX(renderer, cellX, cellY, CELL_SIZE);
            }
            else if (board[i][j] == Player::O)
            {
                int cellX = i * CELL_SIZE;
                int cellY = j * CELL_SIZE;
                drawO(renderer, cellX, cellY, CELL_SIZE);
            }
        }
    }

    SDL_RenderPresent(renderer);
}

void handleEvent(SDL_Event event)
{
    static Player currentPlayer = Player::X ;

    if (event.type == SDL_QUIT)
    {
        running = false;
    }
    else if (event.type == SDL_MOUSEBUTTONDOWN)
    {
        int x, y;
        SDL_GetMouseState(&x, &y);
        int cellX = x / CELL_SIZE;
        int cellY = y / CELL_SIZE;
        if (board[cellX][cellY] == Player::None)
        {
            board[cellX][cellY] = currentPlayer;
            if (checkWin(currentPlayer , board))
            {
                if(currentPlayer == Player::X)
                {
                    displayResImage(1) ;
                }
                else
                {
                    displayResImage(2) ;
                }
                resetBoard() ;
            }
            else if(checkTie(Player::X , board) + checkTie(Player::O , board) == 9)
            {
                displayResImage(0) ;
                resetBoard() ;
            }
            else
            {
                currentPlayer = (currentPlayer == Player::X) ? Player::O : Player::X;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    initSDL();

    loadIcon() ;

    resetBoard() ;

    while (running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            handleEvent(event);
        }
        drawBoard() ;
    }

    closeSDL();

    return 0 ;
}