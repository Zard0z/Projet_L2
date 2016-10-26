#include "struct.h"

/* Prototypes des fonctions utilis�es */

extern void init(char *);
extern void cleanup(void);
extern void getInput(void);
extern void draw(void);

extern void loadGame(void);
extern void delay(unsigned int);


/* D�claration des structures globales utilis�es par le jeu */

Input input;

Operate jeu;
Depth Map;
