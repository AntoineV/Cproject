#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "fonction.h"

using namespace std;

int main()
{
    string nomJoueur;
    int nbcase = 40, de=0; //Conditions de jeu
    int position=0,argent=1500; //Variables de départ
    int MIN= 1, MAX=6; //Nb de face du dé
    int oui_non=0; //Choix de continuer ou pas
    int coutCase[40];
    string proprioCase[40];

    coutCase[0]=-200;
    coutCase[1]=60;
    coutCase[2]=0;
    coutCase[3]=60;
    coutCase[4]=200;
    coutCase[5]=200;
    coutCase[6]=100;
    coutCase[7]=0;
    coutCase[8]=100;
    coutCase[9]=120;
    coutCase[10]=0;
    coutCase[11]=140;
    coutCase[12]=150;
    coutCase[13]=140;
    coutCase[14]=160;
    coutCase[15]=200;
    coutCase[16]=180;
    coutCase[17]=0;
    coutCase[18]=180;
    coutCase[19]=200;
    coutCase[20]=0;
    coutCase[21]=220;
    coutCase[22]=0;
    coutCase[23]=220;
    coutCase[24]=240;
    coutCase[25]=200;
    coutCase[26]=260;
    coutCase[27]=260;
    coutCase[28]=150;
    coutCase[29]=280;
    coutCase[30]=0;
    coutCase[31]=300;
    coutCase[32]=300;
    coutCase[33]=0;
    coutCase[34]=320;
    coutCase[35]=200;
    coutCase[36]=0;
    coutCase[37]=350;
    coutCase[38]=100;
    coutCase[39]=400;


    srand(time(NULL));

    cout << "Entrez votre nom: "<<endl;
    cin >> nomJoueur;
    cin.ignore();

    for(int i=0;i<nbcase;i++)
    {
        cout << "Numero "<< i <<" Cout:"<<coutCase[i] << endl;
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
            if (position+de>=nbcase)
            {
                position = position - nbcase ;
                argent = argent + 100;
                cout<<"Vous avez fait un tour ! Vous gagnez 100 dollars"<<endl;
                afficher_argent_joueur(argent);
            }
            position = position + de;
            cout<<"APRES:Position:"<<position<<endl;
            afficher_cout_case(coutCase, position);
            afficher_argent_joueur(argent);
            int choix = 0;
            if(argent - coutCase[position] >= 0){
                cout << "Voulez vous acheter cette case ? OUI:1  NON:2" <<endl;
                cin >> choix;
                cin.ignore();
                if (choix == 1)
                {
                    argent = argent - coutCase[position];
                    proprioCase[position] = nomJoueur;
                    cout << "Vous avez aquis la case numéro " << position <<endl;
                    afficher_argent_joueur(argent);
                }
            }
        }
        else
        {
            cout<<"Merci et a bientot!"<<endl;
        }
    }while (oui_non==1 && argent >= 0);
    cout<<"Merci et casse toi pauvre con!!!"<<endl;
    return 0;
}
