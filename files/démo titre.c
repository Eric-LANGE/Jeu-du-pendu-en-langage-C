/*

Permet de tester l'affichage du titre du jeu

*/



#include <stdlib.h>
#include <stdio.h>
#include <time.h>


void delay(int number_of_seconds);

int main()
{
    FILE *fichier = NULL;
    int c = 0;
    
 
    fichier = fopen("Chemin vers le fichier titre.txt", "r");
 
    if (fichier != NULL)
    {
        while ((c= fgetc(fichier)) != EOF)
        {
	        printf("%c", c);
	        delay(4);
        }
     }  
    else
     {
         printf("Impossible d'ouvrir le fichier titre.txt");
     }
         
        fclose(fichier);
        
        printf("\n");
 
    return 0;
}


  
void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;
  
    // Storing start time
    clock_t start_time = clock();
  
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}


