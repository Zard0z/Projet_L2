#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

/* Valeur RGB pour la transparence (canal alpha) */
 #define TRANS_R 255
 #define TRANS_G 0
 #define TRANS_B 255


 /* Taille maxi de la map : on voit large : 400 x 300 tiles */
 #define MAX_MAP_X 400
 #define MAX_MAP_Y 300

 /* Taille d'une tile (32 x 32 pixels) */
 #define TILE_SIZE 32

/* Taille du sprite de notre héros (largeur = width et hauteur = heigth) */
#define PLAYER_WIDTH 40
#define PLAYER_HEIGTH 80

/* Constantes pour l'animation  POUR LA COKE!!!!!!!!!*/
#define TIME_BETWEEN_2_FRAMES 8
