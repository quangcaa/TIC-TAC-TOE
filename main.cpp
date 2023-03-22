#include <SDL2/SDL.h>
#include <iostream>
#include <cmath>

#include "icon.h"
#include "checkWin.h"

using namespace std ;

const int SCREEN_WIDTH = 660 ;
const int SCREEN_HEIGHT = 660 ;
const int BOARD_SIZE = 3 ;
const int CELL_SIZE = 220 ;

SDL_Window *window = nullptr ;
SDL_Renderer *renderer = nullptr ;
SDL_Surface *icon = nullptr ;
SDL_Texture *imageTexture = nullptr ;


enum class Player
{
    None,
    X,
    O
};

Player board[BOARD_SIZE][BOARD_SIZE];


bool running = true;

void initSDL()
{
    SDL_Init(SDL_INIT_VIDEO );
    window = SDL_CreateWindow("Tic Tac Toe" , SDL_WINDOWPOS_CENTERED , SDL_WINDOWPOS_CENTERED , SCREEN_WIDTH , SCREEN_HEIGHT , SDL_WINDOW_SHOWN) ;
    renderer = SDL_CreateRenderer(window, -1, 0);
}

void closeSDL()
{
    SDL_FreeSurface(icon) ;

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
}


void printImageOnCell(SDL_Renderer* renderer, SDL_Texture* texture, int cellSize, int boardSize, int mouseX, int mouseY)
{
    // Get the cell position
    int cellX = mouseX / cellSize;
    int cellY = mouseY / cellSize;

    // Calculate the position and size of the image
    SDL_Rect destRect = { cellX * cellSize, cellY * cellSize, cellSize, cellSize };

    // Load the BMP image file
    SDL_Surface* surface = SDL_LoadBMP("image/X.bmp");
    if (surface == nullptr)
    {
        return;
    }

    // Create a texture from the surface
    SDL_Texture* imageTexture = SDL_CreateTextureFromSurface(renderer, surface);
    if (imageTexture == nullptr) 
    {
        SDL_FreeSurface(surface);
        return;
    }

    // Free the surface
    SDL_FreeSurface(surface);

    // Render the texture on the cell
    SDL_RenderCopy(renderer, imageTexture, nullptr, &destRect);

    // Destroy the texture
    SDL_DestroyTexture(imageTexture);
}


void drawBoard()
{
    //background color
    SDL_SetRenderDrawColor(renderer, 153 , 102 , 203 , 255) ;
    SDL_RenderClear(renderer) ;

    //line color
    SDL_SetRenderDrawColor(renderer , 111 , 45 , 168 , 255) ;


    for (int i = 1; i < BOARD_SIZE; i++)
    {
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
                // SDL_Event event ;
                // switch(event.type)
                // {
                //     case SDL_MOUSEBUTTONDOWN:
                //     {
                //         if(event.button.button == SDL_BUTTON_LEFT)
                //         {
                //             printImageOnCell(renderer , imageTexture , CELL_SIZE , 520 , event.button.x , event.button.y ) ;
                //         }
                //     }
                // }
                SDL_RenderDrawLine(renderer, i * CELL_SIZE + 10, j * CELL_SIZE + 10, (i + 1) * CELL_SIZE - 10, (j + 1) * CELL_SIZE - 10);
                SDL_RenderDrawLine(renderer, i * CELL_SIZE + 10, (j + 1) * CELL_SIZE - 10, (i + 1) * CELL_SIZE - 10, j * CELL_SIZE + 10);
            }
            else if (board[i][j] == Player::O)
            {
                int centerX = i * CELL_SIZE + CELL_SIZE / 2;
                int centerY = j * CELL_SIZE + CELL_SIZE / 2;
                int radius = CELL_SIZE / 2 - 10;
                for (double angle = 0; angle < 360; angle += 5)
                {
                    double radians = angle * 3.1415926 / 180;
                    int x = centerX + radius * cos(radians);
                    int y = centerY + radius * sin(radians);
                    SDL_RenderDrawPoint(renderer, x, y);
                }
            }
        }
    }

    SDL_RenderPresent(renderer);
}


int checkDraw(Player player)
{
    int cnt = 0 ;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == player)
            {
                cnt ++ ;
            }
        }
    }
    return cnt ;
}


void handleEvent(SDL_Event event)
{
    static Player currentPlayer = Player::X;

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
            if(checkDraw(Player::X) + checkDraw(Player::O) == 25)
            {
                cout << "Draw !!!" ;
                running = false ;
            }
            if (checkWin(currentPlayer , board))
            {
                cout << "Player " << static_cast<int>(currentPlayer) << " wins!" << std::endl;
                running = false;
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

    // Initialize board to empty
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = Player::None;
        }
    }

    while (running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            handleEvent(event);
        }
        drawBoard();
    }

    closeSDL();

    return 0;
}