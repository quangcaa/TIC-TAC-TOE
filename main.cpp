#include <SDL2/SDL.h>
#include <iostream>
#include <cmath>

#include "player.h"
#include "core.h"
#include "drawBoard.h"
#include "checkWin.h"
#include "checkTie.h"
#include "drawXO.h"
#include "displayResImage.h"
#include "modeGame.h"

using namespace std ;

const int SCREEN_WIDTH = 660 ;
const int SCREEN_HEIGHT = 660 ;
const int BOARD_SIZE = 3 ;
const int CELL_SIZE = 220 ;

SDL_Window *window = nullptr ;
SDL_Renderer *renderer = nullptr ;

Player board[3][3];

bool running = true;


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
                currentPlayer = Player::X ; //set first player to X in new game 
            }
            else if(checkTie(Player::X , board) + checkTie(Player::O , board) == 9)
            {
                displayResImage(0) ;
                resetBoard() ;
                currentPlayer = Player::X ; //set first player to X in new game 
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

    string Mode ;
    bool modeSelected = false ;

    while (!modeSelected)
    {
        // Display mode selection
        Mode = modeGame();

        // Check if a valid mode was selected
        if (Mode == "vs computer" || Mode == "vs player")
        {
            modeSelected = true;
        }
    }

    while (running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            handleEvent(event);
        }

        if(Mode == "vs computer")
        {

        }
        else if(Mode == "vs player")
        {

        }

        drawBoard() ;
    }

    closeSDL();

    return 0 ;
}