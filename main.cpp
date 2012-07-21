#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include"fonction.h"
using namespace std;

int main()
{
    int nbcase = 20, de=0; //Conditions de jeu
    int position=0,argent=100; //Variables de départ
    int MIN= 1, MAX=6; //Nb de face du dé
    int oui_non=0; //Choix de continuer ou pas
    int status_case[nbcase];

    srand(time(NULL));

    for(int i=0; i < nbcase; i++)
    {
        status_case[i] = 0;
    }
    for(int i=0; i < nbcase; i=i+2)
    {
        status_case[i]=50;
    }
    for(int i=0; i < nbcase; i++)
    {
        cout << "Numero: "<< i << "Cout: " << status_case[i] << endl;
    }

    do
    {
        cout << "Voulez vous lancer le de ? OUI:1 NON:2" << endl;
        cin >> oui_non;
        cin.ignore();

        if (oui_non==1)
        {
            de = (rand() % (MAX - MIN + 1)) + MIN;
            afficher_status_joueur(position, de, argent);
            if (position + de >= nbcase)
            {
                position = position - nbcase ;
                argent = argent + 100;
                cout << "Vous avez fait un tour ! Vous gagnez 100$" << endl;
                afficher_argent_joueur(argent);
            }
            position = position + de;
            argent = argent - status_case[position];
            cout << "APRES:Position: " << position << endl;
            afficher_case(status_case, position);
            afficher_argent_joueur(argent);
        }
        else
        {
            cerr << "Merci et a bientot!" << endl;
        }
    }while (oui_non == 1 && argent >= 0);
    
    cout << "Merci et casse toi pauvre con!!!" << endl;
    
    return 0;
}
