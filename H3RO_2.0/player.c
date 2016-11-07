#include "player.h"


void initializePlayer(void)
{

    /* Charge le sprite de notre héros */
    player.sprite = loadImage("graphics/walkright.png");

    /* Coordonnées de démarrage de notre héros */
    player.x = 20;
    player.y = 304;

}

 void drawplayer()
{
    /* Rectangle de destination à blitter */
    SDL_Rect dest;

    dest.x = player.x;
    dest.y = player.y;
    dest.w = PLAYER_WIDTH;
    dest.h = PLAYER_HEIGTH;

    /* Rectangle source à blitter */
    SDL_Rect src;

    src.x = 0;
    src.y = 0;
    src.w = PLAYER_WIDTH;
    src.h = PLAYER_HEIGTH;

    /* Blitte notre héros sur l'écran aux coordonnées x et y */

    SDL_BlitSurface(player.sprite, &src, jeu.screen, &dest);

}
