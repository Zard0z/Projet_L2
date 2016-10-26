#include "Map.h"

void loadMap(char *name)
{
int x, y;
FILE *fp;

fp = fopen(name, "rb");

/* Si on ne peut pas ouvrir le fichier, on quitte */

if (fp == NULL)
{
    printf("Failed to open Map %s\n", name);
    exit(1);
}


/* Lit les donn�es du fichier dans la Map */

Map.maxX = Map.maxY = 0;

for (y = 0; y < MAX_MAP_Y; y++)
{
    for (x = 0; x < MAX_MAP_X; x++)
    {
        /* On lit le num�ro de la tile et on le copie dans notre tableau */

        fscanf(fp, "%d", &Map.tile[y][x]);

        /* Permet de d�terminer la taille de la map (voir plus bas) */

        if (map.tile[y][x] > 0)
        {
            if (x > Map.maxX)
            {
                Map.maxX = x;
            }

            if (y > Map.maxY)
            {
                Map.maxY = y;
            }
        }
    }
}


/* maxX et maxY sont les coordonn�es de fin de la map.
On les trouve d�s qu'il n'y a plus que des z�ros � la suite.
Comme �a, on peut faire des maps de tailles diff�rentes avec la m�me
structure de fichier. */

Map.maxX = (Map.maxX + 1) * TILE_SIZE;
Map.maxY = (Map.maxY + 1) * TILE_SIZE;


/* Remet � 0 les coordonn�es de d�part de la map */

Map.startX = Map.startY = 0;


/* Et on referme le fichier */

fclose(fp);

}




void drawMap(void)
{
int x, y, mapX, x1, x2, mapY, y1, y2, xsource, ysource, a;

/* Ces calculs compliqu�s serviront � calculer l'affichage de l'�cran pendant le scrolling

mapX = map.startX / TILE_SIZE;
x1 = (map.startX % TILE_SIZE) * -1;
x2 = x1 + SCREEN_WIDTH + (x1 == 0 ? 0 : TILE_SIZE);

mapY = map.startY / TILE_SIZE;
y1 = (map.startY % TILE_SIZE) * -1;
y2 = y1 + SCREEN_HEIGHT + (y1 == 0 ? 0 : TILE_SIZE); */


/* Mais pour l'instant, comme on ne scrolle pas, on peut les simplifier :
On va en effet dessiner la map du d�but (0;0) jusqu'au bout de l'�cran (640;480) */

MapX = 0;
x1 = 0;
x2 = SCREEN_WIDTH;

mapY = 0;
y1 = 0;
y2 = SCREEN_HEIGHT;



/* Dessine la carte en commen�ant par startX et startY */

/* On dessine ligne par ligne en commen�ant par y1 (0) jusqu'� y2 (480)
A chaque fois, on rajoute TILE_SIZE (donc 32), car on descend d'une ligne
de tile (qui fait 32 pixels de hauteur) */

for (y = y1; y < y2; y += TILE_SIZE)
{
    /* A chaque d�but de ligne, on r�initialise mapX qui contient la colonne
    (0 au d�but puisqu'on ne scrolle pas) */

    mapX = map.startX / TILE_SIZE;

    /* A chaque colonne de tile, on dessine la bonne tile en allant
    de x = 0 � x = 640 */

    for (x = x1; x < x2; x += TILE_SIZE)
    {

        /* Suivant le num�ro de notre tile, on d�coupe le tileset */

        a = Map.tile[mapY][mapX];

        /* Calcul pour obtenir son y (pour un tileset de 10 tiles
        par ligne, d'o� le 10 */

        ysource = a / 10 * TILE_SIZE;

        /* Et son x */

        xsource = a % 10 * TILE_SIZE;

        /* Fonction qui blitte la bonne tile au bon endroit */

        drawTile(map.tileSet, x, y, xsource, ysource);

        MapX++;
    }

    MapY++;
}
}
