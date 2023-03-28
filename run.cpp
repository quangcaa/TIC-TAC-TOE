#include "run.h"

void run()
{
    string Mode ;
    bool modeSelected = false ;

    while(!modeSelected)
    {
        Mode = modeGame() ; //display mode selection

        if(Mode == "vs computer" || Mode == "vs player") //check if a valid mode was selected
        {
            modeSelected = true ;
        }
    }

    while(running)
    {
        SDL_Event event;

        if(Mode == "vs computer")
        {
            while(SDL_PollEvent(&event))
            {
                handleVsComputer(event) ;
            }
        }
        else if(Mode == "vs player")
        {
            while(SDL_PollEvent(&event))
            {
                handleVsPlayer(event) ;
            }
        }

        drawBoard() ;
    }
}