#include "init.h"

/* Fonction qui initialise le jeu */

void init(char *title)
{

    /* Initialise SDL Video. Si la valeur de retour est inf�rieure � z�ro, la SDL n'a pas pu
     s'initialiser et on quite */

    if (SDL_Init(SDL_INIT_VIDEO ) < 0)
    {
        printf("Could not initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }


     /* On cr�e la fen�tre, repr�sent�e par le pointeur jeu.screen en utilisant la largeur et la
     hauteur d�finies dans les defines (defs.h). On utilise aussi la m�moire vid�o
     (SDL_HWPALETTE) et le double buffer pour �viter que �a scintille
     (SDL_DOUBLEBUF) */

    jeu.screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 0, SDL_HWPALETTE|SDL_DOUBLEBUF);

     /* Si on y arrive pas, on quitte */

    if (jeu.screen == NULL)
        {
            printf("Couldn't set screen mode to %d x %d: %s\n", SCREEN_WIDTH,
                     SCREEN_HEIGHT, SDL_GetError());
            exit(1);
        }


    /* On entre le titre de la fen�tre */

    SDL_WM_SetCaption(title, NULL);


    /* On cache le curseur de la souris */

    SDL_ShowCursor(SDL_DISABLE);

    /* Initialise SDL_TTF */

    if (TTF_Init() < 0)
    {
        printf("Couldn't initialize SDL TTF: %s\n", SDL_GetError());

        exit(1);
    }

    /* Charge la police en 32 points (taille) */

    font = loadFont("font/GenBasB.ttf", 32);
}

void loadGame(void)
{
    /* Charge l'image du fond */
    map.background = loadImage("graphics/background.png");

    map.tileSet = loadImage("graphics/tileset.png");

    map.tileSetB = loadImage("graphics/tilesetB.png");

    //On initialise le timer
    map.mapTimer = TIME_BETWEEN_2_FRAMES*3;
    map.tileSetNumber = 0;

    loadMap("map/map1.txt");

    /* On initialise les variables du jeu */
    jeu.vies = 3;
    jeu.etoiles = 0;

    /* On charge le HUD */
    jeu.HUD_vie = loadImage("graphics/life.png");
    jeu.HUD_etoiles = loadImage("graphics/stars.png");
}

/* Fonction qui quitte le jeu proprement */

void cleanup()
{
    int i;
    if (map.background != NULL)
    {
        SDL_FreeSurface(map.background);
    }

    /* Lib�re l'image du tileset */
    if (map.tileSet != NULL)
    {
        SDL_FreeSurface(map.tileSet);
    }

    if (map.tileSetB != NULL)
    {
        SDL_FreeSurface(map.tileSetB);
    }

    /* Lib�re le sprite du h�ros */
    if (player.sprite != NULL)
    {
        SDL_FreeSurface(player.sprite);
    }

    /* Lib�re le sprite des monstres */
    for(i = 0 ; i < MONSTRES_MAX ; i++)
    {
        if (monster[i].sprite != NULL)
        {
        SDL_FreeSurface(monster[i].sprite);
        }
    }

    //Lib�re le HUD
    if (jeu.HUD_etoiles != NULL)
    {
        SDL_FreeSurface(jeu.HUD_etoiles);
    }
    if (jeu.HUD_vie != NULL)
    {
        SDL_FreeSurface(jeu.HUD_vie);
    }

    /* Close the font */
    closeFont(font);

    /* Close SDL_TTF */
    TTF_Quit();

    /* Quitte la SDL */
    SDL_Quit();
}
