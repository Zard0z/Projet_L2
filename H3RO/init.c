#include "init.h"

/* Fonction qui initialise le jeu */

void init(char *title)
{

/* Initialise SDL Video. Si la valeur de retour est inférieure à zéro, la SDL n'a pas pu
 s'initialiser et on quite */

if (SDL_Init(SDL_INIT_VIDEO) < 0)
{
    printf("Impossible de lancer la SDL : %s\n", SDL_GetError());
    exit(1);
}


 /* On crée la fenêtre, représentée par le pointeur jeu.screen en utilisant la largeur et la
 hauteur définies dans les defines (def.h). On utilise aussi la mémoire vidéo
 (SDL_HWPALETTE) et le double buffer pour éviter que ça scintille
 (SDL_DOUBLEBUF) */

jeu.screen = SDL_SetVideoMode(SCREEN_length, SCREEN_height, 0, SDL_HWPALETTE|SDL_DOUBLEBUF);

 /* Si on n'y arrive pas, on quitte */

if (jeu.screen == NULL)
{
    printf("Couldn't set screen mode to %d x %d: %s\n", SCREEN_length,
             SCREEN_height, SDL_GetError());
    exit(1);
}


/* On entre le titre de la fenêtre */

SDL_WM_SetCaption(title, NULL);


/* On cache le curseur de la souris */

SDL_ShowCursor(SDL_DISABLE);

}

void loadGame(void)
{

    /* Charge l'image du fond */
    Map.background = loadImage("images/background.png");

}

/* Fonction qui quitte le jeu proprement */

void cleanup()
{

    if (Map.background != NULL)
    {
        SDL_FreeSurface(Map.background);
    }

    /* Quitte la SDL */
    SDL_Quit();

}
