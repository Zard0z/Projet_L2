#include "sounds.h"

 void loadSong( char filename[200] )
{

 /* On lib�re la chanson pr�c�dente s'il y en a une */
 if ( jeu.musique != NULL )
 {
    Mix_HaltMusic();
    Mix_FreeMusic(jeu.musique);
 }

 /* On charge la nouvelle chanson */
 jeu.musique = Mix_LoadMUS( filename );
 if (jeu.musique == NULL)
    {
        fprintf(stderr, "Can't read the music \n");
        exit(1);
    }

 /* On active la r�p�tition de la musique � l'infini */

     if(Mix_PlayMusic(jeu.musique, -1)==-1)
     {
        printf("Mix_PlayMusic: %s\n", Mix_GetError());
     }

}
