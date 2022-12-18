/*

Jeu du Pendu

dico.c
------

Cette fonction va prendre un param�tre : un pointeur sur la zone en m�moire o� elle pourra �crire le mot tir� au hazard. 
Ce pointeur sera fourni par le main().

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "dico.h"

int piocherMot(char *motPioche)

{
	
const char chemin[] = "Chemin vers le fichier dico.txt";
	
FILE* dico = NULL; // Le pointeur de fichier qui va contenir notre fichier

int nombreMots = 0, numMotChoisi = 0;
 
   int caractereLu = 0;
   
   dico = fopen(chemin, "r"); 

   if (dico == NULL) 
   {
  printf("\nImpossible de charger le dictionnaire\n");
  return 1;

}

/*  On compte le nombre de mots dans le fichier (il suffit de compter les \n)
*/
   do
   {
   caractereLu = fgetc(dico);
   if (caractereLu == '\n')
   nombreMots++;
   } while(caractereLu != EOF);

   numMotChoisi = nombreAleatoire(nombreMots); 

   rewind(dico);

   while (numMotChoisi > 0)
   {
   caractereLu = fgetc(dico); // positionnement curseur
   if (caractereLu == '\n')
   numMotChoisi--;
   }

   fgets(motPioche, 100, dico);


   motPioche[strlen(motPioche) - 1] = '\0';
// on remplace \n en fin de mot par \0
  
	 fclose(dico);

   return 0; 
}

int nombreAleatoire(int nombreMax)
{
   srand( (unsigned int) time(NULL));
   return (rand() % nombreMax);
}

