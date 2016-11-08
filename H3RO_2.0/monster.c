#include "monster.h"

void initializeMonster(int x, int y)
{
    //Si on n'est pas rendu au max, on rajoute un monstre dont le num�ro est �gal
    //� nombreMonstres : monster[0] si c'est le 1er, monster[1], si c'est le 2eme, etc...
    if (jeu.nombreMonstres < MONSTRES_MAX )
    {
        /* On charge son sprite */
        monster[jeu.nombreMonstres].sprite = loadImage("graphics/monster1.png");

        //On indique sa direction (il viendra � l'inverse du joueur, logique)
        monster[jeu.nombreMonstres].direction = LEFT;

        //On r�initialise le timer de l'animation et la frame comme pour le joueur
        monster[jeu.nombreMonstres].frameNumber = 0;
        monster[jeu.nombreMonstres].frameTimer = TIME_BETWEEN_2_FRAMES;

        /* Ses coordonn�es de d�marrage seront envoy�es par la fonction drawMap() en arguments */
        monster[jeu.nombreMonstres].x = x;
        monster[jeu.nombreMonstres].y = y;

        /* Hauteur et largeur de notre monstre (une tile ici, soit 32x32) */
        monster[jeu.nombreMonstres].w = TILE_SIZE;
        monster[jeu.nombreMonstres].h = TILE_SIZE;

        //Variables n�cessaires au fonctionnement de la gestion des collisions comme pour le h�ros
        monster[jeu.nombreMonstres].timerMort = 0;
        monster[jeu.nombreMonstres].onGround = 0;

        jeu.nombreMonstres++;

    }

}

void updateMonsters(void)
{

    int i;

    //On passe en boucle tous les monstres du tableau
    for ( i = 0; i < jeu.nombreMonstres; i++ )
    {
        //M�me fonctionnement que pour le joueur
        if (monster[i].timerMort == 0)
        {

            monster[i].dirX = 0;
            monster[i].dirY += GRAVITY_SPEED;


            if (monster[i].dirY >= MAX_FALL_SPEED)
                monster[i].dirY = MAX_FALL_SPEED;

            //Le monstre va toujours � gauche
            monster[i].dirX -= 1;

            //On d�tecte les collisions avec la map comme pour le joueur
            mapCollision(&monster[i]);

          }

        //Si le monstre meurt, on active une tempo
        if (monster[i].timerMort > 0)
        {
            monster[i].timerMort--;

            /* Et on le remplace simplement par le dernier du tableau puis on
            r�tr�cit le tableau d'une case (on ne peut pas laisser de case vide) */
            if (monster[i].timerMort == 0)
            {
                monster[i] = monster[jeu.nombreMonstres-1];
                jeu.nombreMonstres--;
            }
        }

    }

}
