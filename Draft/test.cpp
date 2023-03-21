if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT) &&
    SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_RIGHT))
{
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);

    if (mouseX >= i * CELL_SIZE && mouseX <= (i + 1) * CELL_SIZE && mouseY >= j * CELL_SIZE &&
        mouseY <= (j + 1) * CELL_SIZE)
    {
        SDL_Texture *imageTexture = IMG_LoadTexture(renderer, "image.png");
        SDL_Rect destRect = {i * CELL_SIZE, j * CELL_SIZE, CELL_SIZE, CELL_SIZE};
        SDL_RenderCopy(renderer, imageTexture, NULL, &destRect);
    }
}

SDL_RenderDrawLine(renderer, i * CELL_SIZE + 10, j * CELL_SIZE + 10, (i + 1) * CELL_SIZE - 10, (j + 1) * CELL_SIZE - 10);
                SDL_RenderDrawLine(renderer, i * CELL_SIZE + 10, (j + 1) * CELL_SIZE - 10, (i + 1) * CELL_SIZE - 10, j * CELL_SIZE + 10);



void printImageOnCell(SDL_Renderer* renderer, SDL_Texture* texture, int cellSize, int boardSize, int mouseX, int mouseY)
{
    // Get the cell position
    int cellX = mouseX / cellSize;
    int cellY = mouseY / cellSize;

    // Check if the cell is inside the board
    if (cellX >= boardSize || cellY >= boardSize) {
        return;
    }

    // Calculate the position and size of the image
    SDL_Rect destRect = { cellX * cellSize, cellY * cellSize, cellSize, cellSize };

    // Load the BMP image file
    SDL_Surface* surface = SDL_LoadBMP("image.bmp");
    if (surface == nullptr) {
        printf("Failed to load image: %s\n", SDL_GetError());
        return;
    }

    // Create a texture from the surface
    SDL_Texture* imageTexture = SDL_CreateTextureFromSurface(renderer, surface);
    if (imageTexture == nullptr) {
        printf("Failed to create texture: %s\n", SDL_GetError());
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
