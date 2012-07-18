#include <stdio.h>
#include <stdlib.h>
#include"fonction.h"
int main()
{
    int nbcase = 20, de=0; //Conditions de jeu
    int position=0,argent=100; //Variables de départ
    int MIN= 1, MAX=6; //Nb de face du dé
    int oui_non=0; //Choix de continuer ou pas
    int status_case[nbcase][2];
    int i;

    srand(time(NULL));

    for(i=0;i<nbcase;i++)
    {
        status_case[i][i] = 0;
    }
    for(i=0;i<nbcase;i=i+2)
    {
        status_case[i][i]=50;
    }
    for(i=0;i<nbcase;i++)
    {
        printf("Numero:%d \t Cout:%d\n",i,status_case[i]);
    }

    do
    {
        printf("Voulez vous lancer le de ? OUI:1 NON:2\n");
        scanf("%d",&oui_non);

        if (oui_non==1)
        {
            de = (rand() % (MAX - MIN + 1)) + MIN;
            afficher_status_joueur(position, de, argent);
            if (position+de>=nbcase)
            {
                position = position - nbcase ;
                argent = argent + 100;
                printf("Vous avez fait un tour ! Vous gagnez 100$");
                afficher_argent_joueur(argent);
            }
            position = position + de;
            argent = argent - status_case[position][1];
            printf("APRES:Position:%d",position);
            afficher_case(status_case, position);
            afficher_argent_joueur(argent);
        }
        else
        {
            printf("Merci et a bientot!");
        }
    }while (oui_non==1 && argent >= 0);
    printf("Merci et casse toi pauvre con!!!");
    return 0;
}
