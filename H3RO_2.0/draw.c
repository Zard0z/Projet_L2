#include "draw.h"


void draw(void)
{

    /* Affiche l'écran */

    SDL_Flip(jeu.screen);


    /* Delai */

    SDL_Delay(1);

}



void delay(unsigned int frameLimit)
{

    /* Gestion des 60 fps (images/stories/seconde) */

    unsigned int ticks = SDL_GetTicks();

    if (frameLimit < ticks)
    {
        return;
    }

    if (frameLimit > ticks + 16)
    {
        SDL_Delay(16);
    }

    else
    {
        SDL_Delay(frameLimit - ticks);
    }
}
