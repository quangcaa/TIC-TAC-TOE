#include "icon.h"

void loadIcon()
{
    // Load the icon image
    icon = SDL_LoadBMP("image/icon.bmp");

    // Set the color key of the surface to transparent
    SDL_SetColorKey(icon, SDL_TRUE, SDL_MapRGB(icon->format, 255, 0, 255));

    // Set the icon of the window
    SDL_SetWindowIcon(window, icon);
}