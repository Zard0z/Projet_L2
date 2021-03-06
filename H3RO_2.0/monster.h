#include "structs.h"

extern GameObject monster[];
extern Gestion jeu;
extern GameObject player;
extern Map map;

/* Prototypes des fonctions utilis�es */
extern SDL_Surface *loadImage(char *name);
extern void mapCollision(GameObject *entity);
extern int collide(GameObject *player, GameObject *monster);
extern int checkFall(GameObject monster);
extern void changeAnimation(GameObject *entity, char *name);
extern void playSoundFx(int type);
extern void monsterCollisionToMap(GameObject *entity);
