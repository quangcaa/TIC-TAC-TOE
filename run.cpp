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


    vector<SDL_Event> events ; //create a vector to store events

    while(running)
    {
        SDL_Event event ; //poll for events and add them to the event vector
        while (SDL_PollEvent(&event))
        {
            events.push_back(event) ;
        }

        for(auto &event : events) //process all events in the event vector
        {
            if (Mode == "vs computer")
            {
                handleVsComputer(event);
            }
            else if (Mode == "vs player")
            {
                handleVsPlayer(event);
            }
        }

        events.clear() ; //clear the event vector

        drawBoard() ;
    }

}