#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"

void afficher_status_joueur(int position, int de,int argent)
{
    printf("AVANT:Position:%d\tLancer:%d\t Argent:%d\n",position,de,argent);
}
void afficher_argent_joueur(int argent)
{
    printf("Vous avez %d$\n",argent);
}
void afficher_case(int status_case[],int position)
{
    printf("Cout case:%d\n", status_case[position]);
}
