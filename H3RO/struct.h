#include "define.h"

/* Structures qui seront utilisées pour gérer le jeu */

/* Structure pour gérer l'input (clavier puis joystick) */

typedef struct Input
{

int left,
    right,
    up,
    down,
    jump,
    attack,
    enter,
    erase,
    pause;

} Input;


/* Structure pour gérer le niveau (à compléter plus tard) */

typedef struct Operate
{

    SDL_Surface *screen;

} Operate;

typedef struct Depth
{

    SDL_Surface *background, *tileSet;

     /* Coordonnées de début, lorsqu'on doit dessiner la map */
    int startX, startY;

    /* Coordonnées max de fin de la map */
    int maxX, maxY;

    /* Tableau à double dimension représentant la map de tiles */
    int tile[MAX_MAP_Y][MAX_MAP_X];


} Depth;

