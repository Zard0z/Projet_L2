#include "player.h"


void initializePlayer(void)
{

    /* Charge le sprite de notre h�ros */
    player.sprite = loadImage("graphics/walkright.png");

    /* Coordonn�es de d�marrage de notre h�ros */
    player.x = 20;
    player.y = 304;

}

 void drawplayer()
{
    /* Rectangle de destination � blitter */
    SDL_Rect dest;

    dest.x = player.x;
    dest.y = player.y;
    dest.w = PLAYER_WIDTH;
    dest.h = PLAYER_HEIGTH;

    /* Rectangle source � blitter */
    SDL_Rect src;

    src.x = 0;
    src.y = 0;
    src.w = PLAYER_WIDTH;
    src.h = PLAYER_HEIGTH;

    /* Blitte notre h�ros sur l'�cran aux coordonn�es x et y */

    SDL_BlitSurface(player.sprite, &src, jeu.screen, &dest);

}
