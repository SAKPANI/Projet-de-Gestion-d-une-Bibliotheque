#include<stdio.h>
#include "livre.h"
#include "emprunt.h"
#include "lecteur.h"
#include "fichier.h"



int main(){
    //Appels des fonction du livre
    abrLivre *racine=NULL;
    collection tete;
    livre Livre[MAX];
    livre l;
    Initialiser(&tete);
    l.annee =2024;
    strcpy(l.auteur, "SAKPANI");
    strcpy(l.isbn, "CODE1");
    strcpy(l.titre, "GODO");

    AjoutLivre(&tete, l);
    AffichageTrier(Livre, &tete);




        
    return 0;
}