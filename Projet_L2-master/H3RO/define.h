#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

/* definition de l'ecran */

#define SCREEN_length 1080
#define SCREEN_height 720

/* definition de la couleur transparente */

#define TRANS_R 255
#define TRANS_G 0
#define TRANS_B 255

/* Taille max de la map : 400 x 300 tiles */
#define MAX_MAP_X 400
#define MAX_MAP_Y 300

/* Taille d'une tile (32 x 32 pixels) */
#define TILE_SIZE 32
