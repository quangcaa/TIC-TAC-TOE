GameMode displayMenu(SDL_Renderer* renderer)
{
    SDL_Surface* singlePlayerSurface = SDL_LoadBMP("single_player.bmp");
    SDL_Surface* multiPlayerSurface = SDL_LoadBMP("multi_player.bmp");

    SDL_Texture* singlePlayerTexture = SDL_CreateTextureFromSurface(renderer, singlePlayerSurface);
    SDL_Texture* multiPlayerTexture = SDL_CreateTextureFromSurface(renderer, multiPlayerSurface);

    SDL_Rect singlePlayerRect = { 200, 200, 200, 50 };
    SDL_Rect multiPlayerRect = { 200, 300, 200, 50 };

    SDL_RenderCopy(renderer, singlePlayerTexture, NULL, &singlePlayerRect);
    SDL_RenderCopy(renderer, multiPlayerTexture, NULL, &multiPlayerRect);

    SDL_RenderPresent(renderer);

    GameMode gameMode = GameMode::SinglePlayer;
    bool done = false;

    while (!done)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                done = true;
                gameMode = GameMode::SinglePlayer;
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                int x, y;
                SDL_GetMouseState(&x, &y);

                if (x >= singlePlayerRect.x && x <= singlePlayerRect.x + singlePlayerRect.w &&
                    y >= singlePlayerRect.y && y <= singlePlayerRect.y + singlePlayerRect.h)
                {
                    gameMode = GameMode::SinglePlayer;
                    done = true;
                }

                if (x >= multiPlayerRect.x && x <= multiPlayerRect.x + multiPlayerRect.w &&
                    y >= multiPlayerRect.y && y <= multiPlayerRect.y + multiPlayerRect.h)
                {
                    gameMode = GameMode::MultiPlayer;
                    done = true;
                }
            }
        }
    }

    SDL_FreeSurface(singlePlayerSurface);
    SDL_FreeSurface(multiPlayerSurface);
    SDL_DestroyTexture(singlePlayerTexture);
    SDL_DestroyTexture(multiPlayerTexture);

    return gameMode;
}