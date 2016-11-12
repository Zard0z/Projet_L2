#include "init.h"

/* Fonction qui initialise le jeu */

void init(char *title)
{

    /* Initialise SDL Video. Si la valeur de retour est inférieure à zéro, la SDL n'a pas pu
     s'initialiser et on quite */

    if (SDL_Init(SDL_INIT_VIDEO ) < 0)
    {
        printf("Could not initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }


     /* On crée la fenêtre, représentée par le pointeur jeu.screen en utilisant la largeur et la
     hauteur définies dans les defines (defs.h). On utilise aussi la mémoire vidéo
     (SDL_HWPALETTE) et le double buffer pour éviter que ça scintille
     (SDL_DOUBLEBUF) */

    jeu.screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 0, SDL_HWPALETTE|SDL_DOUBLEBUF);

     /* Si on y arrive pas, on quitte */

    if (jeu.screen == NULL)
        {
            printf("Couldn't set screen mode to %d x %d: %s\n", SCREEN_WIDTH,
                     SCREEN_HEIGHT, SDL_GetError());
            exit(1);
        }


    /* On entre le titre de la fenêtre */

    SDL_WM_SetCaption(title, NULL);

    /* On charge l'icone de la fenêtre */

    SDL_WM_SetIcon(SDL_LoadBMP("graphics/icone.bmp"), NULL);

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

     /* Initialise SDL_Mixer */
    int flags=MIX_INIT_MP3;
    int initted=Mix_Init(flags);
    if( (initted & flags) != flags)
    {
        printf("Mix_Init: Failed to init SDL_Mixer\n");
        printf("Mix_Init: %s\n", Mix_GetError());
        exit(1);
    }

    /* open 44.1KHz, signed 16bit, system byte order,
           stereo audio, using 1024 byte chunks */
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024)==-1) {
        printf("Mix_OpenAudio: %s\n", Mix_GetError());
        exit(1);
    }

    //Baise le son de la musique
    Mix_VolumeMusic(MIX_MAX_VOLUME/10);
    //Baisse le son dui canal des effets sonnores ingame
    Mix_Volume(-1, MIX_MAX_VOLUME/10);

    /* Définit le nombre de channels à mixer */
    Mix_AllocateChannels(32);
}

void loadGame(void)
{
    /* Charge l'image du fond et le tileset */
    map.background = loadImage("graphics/background.png");

    jeu.fondMenuStart = loadImage("graphics/fondMenuStart.jpg");

    //On commence au premier niveau
    jeu.level = 1;
    changeLevel();

    //On initialise le timer
     map.mapTimer = TIME_BETWEEN_2_FRAMES*3;
     map.tileSetNumber = 0;

    /* On initialise les variables du jeu */
    jeu.vies = 3;
    jeu.etoiles = 0;

    /* On charge le HUD */
    jeu.HUD_vie = loadImage("graphics/life.png");
    jeu.HUD_etoiles = loadImage("graphics/stars.png");

    //On charge la musique
    loadSong("music/Tezla - Music Is The Drug (Original Mix).mp3");

    /* On charge les sounds Fx */
    loadSound();

    //On commence par le menu start
    jeu.onMenu = 1;
    jeu.menuType = START;
}

/* Fonction qui quitte le jeu proprement */
void cleanup()
{
    int i;
    if (map.background != NULL)
    {
        SDL_FreeSurface(map.background);
    }

    if ( jeu.fondMenuStart != NULL )
    {
        SDL_FreeSurface(jeu.fondMenuStart);
    }

    /* Libère l'image du tileset */
    if (map.tileSet != NULL)
    {
        SDL_FreeSurface(map.tileSet);
    }

    if (map.tileSetB != NULL)
    {
        SDL_FreeSurface(map.tileSetB);
    }

    /* Libère le sprite du héros */
    if (player.sprite != NULL)
    {
        SDL_FreeSurface(player.sprite);
    }

    /* Libère le sprite des monstres */
    for(i = 0 ; i < MONSTRES_MAX ; i++)
    {
        if (monster[i].sprite != NULL)
        {
        SDL_FreeSurface(monster[i].sprite);
        }
    }

    //Libère le HUD
    if (jeu.HUD_etoiles != NULL)
    {
        SDL_FreeSurface(jeu.HUD_etoiles);
    }
    if (jeu.HUD_vie != NULL)
    {
        SDL_FreeSurface(jeu.HUD_vie);
    }

    /* On libère la chanson */
    if ( jeu.musique != NULL )
        Mix_FreeMusic(jeu.musique);

    //On libère les sons
    freeSound();

    // Quitte SDL_Mixer et décharge la mémoire
    Mix_CloseAudio();
    Mix_Quit();

    /* Close the font */
    closeFont(font);

    /* Close SDL_TTF */
    TTF_Quit();

    /* Quitte la SDL */
    SDL_Quit();
}
