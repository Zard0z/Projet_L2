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


/* Lit les données du fichier dans la Map */

Map.maxX = Map.maxY = 0;

for (y = 0; y < MAX_MAP_Y; y++)
{
    for (x = 0; x < MAX_MAP_X; x++)
    {
        /* On lit le numéro de la tile et on le copie dans notre tableau */

        fscanf(fp, "%d", &Map.tile[y][x]);

        /* Permet de déterminer la taille de la map (voir plus bas) */

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


/* maxX et maxY sont les coordonnées de fin de la map.
On les trouve dès qu'il n'y a plus que des zéros à la suite.
Comme ça, on peut faire des maps de tailles différentes avec la même
structure de fichier. */

Map.maxX = (Map.maxX + 1) * TILE_SIZE;
Map.maxY = (Map.maxY + 1) * TILE_SIZE;


/* Remet à 0 les coordonnées de départ de la map */

Map.startX = Map.startY = 0;


/* Et on referme le fichier */

fclose(fp);

}




void drawMap(void)
{
int x, y, mapX, x1, x2, mapY, y1, y2, xsource, ysource, a;

/* Ces calculs compliqués serviront à calculer l'affichage de l'écran pendant le scrolling

mapX = map.startX / TILE_SIZE;
x1 = (map.startX % TILE_SIZE) * -1;
x2 = x1 + SCREEN_WIDTH + (x1 == 0 ? 0 : TILE_SIZE);

mapY = map.startY / TILE_SIZE;
y1 = (map.startY % TILE_SIZE) * -1;
y2 = y1 + SCREEN_HEIGHT + (y1 == 0 ? 0 : TILE_SIZE); */


/* Mais pour l'instant, comme on ne scrolle pas, on peut les simplifier :
On va en effet dessiner la map du début (0;0) jusqu'au bout de l'écran (640;480) */

MapX = 0;
x1 = 0;
x2 = SCREEN_WIDTH;

mapY = 0;
y1 = 0;
y2 = SCREEN_HEIGHT;



/* Dessine la carte en commençant par startX et startY */

/* On dessine ligne par ligne en commençant par y1 (0) jusqu'à y2 (480)
A chaque fois, on rajoute TILE_SIZE (donc 32), car on descend d'une ligne
de tile (qui fait 32 pixels de hauteur) */

for (y = y1; y < y2; y += TILE_SIZE)
{
    /* A chaque début de ligne, on réinitialise mapX qui contient la colonne
    (0 au début puisqu'on ne scrolle pas) */

    mapX = map.startX / TILE_SIZE;

    /* A chaque colonne de tile, on dessine la bonne tile en allant
    de x = 0 à x = 640 */

    for (x = x1; x < x2; x += TILE_SIZE)
    {

        /* Suivant le numéro de notre tile, on découpe le tileset */

        a = Map.tile[mapY][mapX];

        /* Calcul pour obtenir son y (pour un tileset de 10 tiles
        par ligne, d'où le 10 */

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
