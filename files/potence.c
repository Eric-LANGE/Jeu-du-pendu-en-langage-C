/*

Permet un affichage progressif de la potence.
Cette option n'est pas utilisée pour le jeu.
Il est nécessaire pour que cela fonctionne de créer les fichiers texte représentant les différentes étapes de construction de la potence.
Les fichiers doivent être nommés p.1, p.2...

*/



#include <stdio.h>
#include <stdlib.h>
#define TAILLE_MAX 1000





// if (!fil) { perror(filepath); exit(EXIT_FAILURE); };





 
int main()
{
    FILE* fichier = NULL;
    char chaine[TAILLE_MAX/10] = {0};
    char buf[100];
    const char chemin[] = "Chemin vers les différents fichiers qui simulent la construction de la potence, syntaxe : p.%d";

    int coupsRestants = 1;

snprintf(buf, sizeof(buf), chemin, coupsRestants);
	
    fichier = fopen(buf, "r");
 
    if (fichier != NULL)
    {
        while (fgets(chaine, TAILLE_MAX, fichier) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
        {
            printf("%s", chaine); // On affiche la chaîne qu'on vient de lire
            system("sleep 0.1");
        }
 
        fclose(fichier);
        
        printf("\n\n");
}

else
{
// On affiche un message d'erreur si on veut
printf("\nImpossible d'ouvrir le fichier %s\n\n", buf);
}


    return 0;
}







