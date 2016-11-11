#include "structs.h"

extern Gestion jeu;
extern GameObject player;
extern Input input;
extern Map map;

/* Prototype des fonctions externes que nous allons utiliser ensuite */
extern SDL_Surface *loadImage(char *name);
extern void centerScrollingOnPlayer(void);
extern void mapCollision(GameObject *entity);
extern void loadMap(char *name);
extern void changeAnimation(GameObject *entity, char *name);
extern void playSoundFx(int type);
