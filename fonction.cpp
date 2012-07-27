#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "fonction.h"
using namespace std;

void afficher_status_joueur(int position, int de,int argent)
{
    cout<<"AVANT:Position:"<<position<<"Lancer:"<<de<<"Argent:"<<argent<<endl;
}
void afficher_argent_joueur(int argent)
{
    cout<<"Vous avez "<<argent<<"$"<<endl;
}
void afficher_cout_case(int coutCase[],int position)
{
    cout<<"Cout case:"<<coutCase[position]<<endl;
}
