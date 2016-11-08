#include "structs.h"

/* Prototypes des fonctions utilisées */
extern void drawImage(SDL_Surface *, int, int);
extern void drawTile(SDL_Surface *image, int destx, int desty, int srcx, int srcy);
extern void mapCollision(GameObject *entity);
extern void initializeMonster(int x, int y);


extern Gestion jeu;
extern Map map;
