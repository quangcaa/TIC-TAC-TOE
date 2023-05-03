#include "Headers/Run.h"

void run()
{
    resetBoard() ;

    x_score = 0 ;
    o_score = 0 ;

    string mode ;
    bool modeSelected = false ;

    while(!modeSelected && running)
    {
        modegame(mode) ; //display mode selection

        if(mode == "vs computer" || mode == "vs player") //check if a valid mode was selected
        {
            modeSelected = true ;
        }
    }

    // vector<SDL_Event> events ; //create a vector to store events

    while(running)
    {
        SDL_Event event ; //poll for events and add them to the event vector
        while(SDL_PollEvent(&event))
        {
            // events.push_back(event) ;
            if (event.type == SDL_QUIT || event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
            {
                running = false ;
            }
            else
            {
                if(mode == "vs computer")
                {
                    handleVsComputer(event) ;
                }
                else if(mode == "vs player")
                {
                    handleVsPlayer(event) ;
                }
            }
        }

        // for(auto &event : events) //process all events in the event vector
        // {
        //     if (Mode == "vs computer")
        //     {
        //         handleVsComputer(event) ;
        //     }
        //     else if (Mode == "vs player")
        //     {
        //         handleVsPlayer(event) ;
        //     }
        // }

        // events.clear() ; //clear the event vector

        draw() ;
    }
}