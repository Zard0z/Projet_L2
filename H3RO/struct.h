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

    SDL_Surface *background;

} Depth;

