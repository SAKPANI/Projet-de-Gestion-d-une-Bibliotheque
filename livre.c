#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "livre.h"


//Operation  sur les prototypes des liste chaine
liste_livre *CreerMaillon(livre l){
    liste_livre *nouveau=(collection*)malloc(sizeof(collection));
    if(nouveau == NULL){
        printf("Erreur de malloc");
        exit(1);
    }
    strncpy(nouveau->donne.isbn, l.isbn, 30);
    strncpy(nouveau->donne.titre, l.titre, 99);
    strncpy(nouveau->donne.auteur, l.auteur, 99);

    nouveau->donne.annee=l.annee;
    nouveau->donne.exemplaires_totales=l.exemplaires_totales;
    nouveau->donne.exemplaires_reste=l.exemplaires_reste;

    //Securite sur le fonctionnemnt des chaines de caractere
    nouveau->donne.auteur[99]="\0";
    nouveau->donne.titre[99]="\0";
    nouveau->donne.isbn[13]="\0";

    nouveau->suivant=NULL;

    return nouveau;
}


//Fonction d'ajpou d'un livre (insertion en tete de liste)
void AjoutLivre(collection *tete, livre l){
    liste_livre *nouveau=CreerMaillon(l);
    nouveau->suivant=tete->premier;
    tete->premier=nouveau;
    if(tete->premier == NULL){
        tete->dernier=nouveau;
    }
    tete->nombreLivre ++;
}



//Fonction de ABR

abrLivre *CreerNoeud(livre l){

    abrLivre *nouveau=(abrLivre*)malloc(sizeof(abrLivre));
    if(nouveau == NULL){
        printf("Erreur malocc de l'ABR");
        exit(1);
    }
    strncpy(nouveau->donne.isbn, l.isbn, 13);
    strncpy(nouveau->donne.titre, l.titre, 99);
    strncpy(nouveau->donne.auteur ,l.auteur, 99);
    nouveau->donne.annee=l.annee;
    nouveau->donne.exemplaires_totales=l.exemplaires_totales;
    nouveau->donne.exemplaires_reste=l.exemplaires_reste;

    //Securite sur les tableau de chaine de caractere
    nouveau->donne.isbn[13]= "\0";
    nouveau->donne.titre[99]= "\0";
    nouveau->donne.auteur[99]= "\0";

    nouveau->gauche=NULL;
    nouveau->droit =NULL;

    return nouveau;
}


//Ajout d'un element dans un ABR
abrLivre *InsererLivre(abrLivre *racine, livre l){
    if(racine == NULL){
        return CreerNoeud(l);
    }
    else if(l.annee < racine->donne.annee){
        racine->gauche=InsererLivre(racine->gauche, l);
    }
    else if(l.annee > racine->donne.annee){
        racine->droit=InsererLivre(racine->droit, l);
    }
    return racine;
}



//Recherche par isbn
abrLivre *RechercheLivre(abrLivre *racine, livre l){
    int comparaisonCaractere=strcmp(l.isbn, racine->donne.isbn) ;
    if(racine == NULL){
        return NULL;
    }
    else if(comparaisonCaractere <0 ){
        return RechercheLivre(racine->gauche, l);
    }
    else if(comparaisonCaractere > 0){
        return RechercheLivre(racine->droit, l);
    }
    else if(comparaisonCaractere == 0){
        return racine;
    }
    return NULL;
}


//Affichage par trie par auteur et titre 

void AffichageTrier(livre Livre[MAX], collection *tete){
    
    int taille=tete->nombreLivre;
    livre temp=Livre[0];

    for(int i = 0; i<taille - 1; i++){
        for(int j=i+1; j<taille - 1; j++){
            int comparaison1=strcmp(Livre[i].isbn, Livre[j].isbn);
            int comparaison2=strcmp(Livre[i].auteur, Livre[j].auteur);

            if(comparaison1 > 0 || comparaison2 > 0){
                temp=Livre[i];
                Livre[i]=Livre[j];
                Livre[j] = temp;
            }
        }

    }
    printf("==============================================================\n");
    printf("         AFFICHAGES DES INFORMATION DE CHAQUE LIVRE DISPONIBLE\n");
    printf("==============================================================\n\n");
    
    printf("ISBN\tTITRE\tAUTEUR\tANNEE\tEXTOTO\tEXETOTO_RESTE\n");
    printf("--------------------------------------------------------------------\n");
    for(int i=0; i<taille; i++){
        printf("%s\t%s\t%s\t%d\t%d\t%d\n",
            Livre[i].isbn,
            Livre[i].titre,
            Livre[i].auteur,
            Livre[i].annee,
            Livre[i].exemplaires_totales,
            Livre[i].exemplaires_reste
        );
        printf("\n==================================================================\n");
    }

}

