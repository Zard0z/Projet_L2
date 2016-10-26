#include "define.h"

/* Structures qui seront utilis�es pour g�rer le jeu */

/* Structure pour g�rer l'input (clavier puis joystick) */

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


/* Structure pour g�rer le niveau (� compl�ter plus tard) */

typedef struct Operate
{

    SDL_Surface *screen;

} Operate;

typedef struct Depth
{

    SDL_Surface *background, *tileSet;

     /* Coordonn�es de d�but, lorsqu'on doit dessiner la map */
    int startX, startY;

    /* Coordonn�es max de fin de la map */
    int maxX, maxY;

    /* Tableau � double dimension repr�sentant la map de tiles */
    int tile[MAX_MAP_Y][MAX_MAP_X];


} Depth;

