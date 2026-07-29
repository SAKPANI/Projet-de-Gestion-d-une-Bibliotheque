#ifndef LIVRE_H
#define LIVRE_H
#define MAX 1000

typedef struct Livre{
    char isbn[14];
    char titre[100];
    char auteur[100];
    int annee;
    int exemplaires_totales;
    int exemplaires_reste;
}livre;


// Liste chaînée des livres

typedef struct Tlivre{
    livre donne;
    struct Tlivre *suivant;
}liste_livre;


// Contrôle de la collection

typedef struct {
    liste_livre *premier;
    liste_livre *dernier;
    int nombreLivre;
}collection;


// ABR des livres

typedef struct abrLivre{
    livre donne;
    struct abrLivre *gauche;
    struct abrLivre *droit;
}abrLivre;


// Fonctions liste
void Initialiser(collection *l);

liste_livre *CreerMaillon(livre l);

void AjoutLivre(collection *tete, livre l);


// Fonctions ABR

abrLivre *CreerNoeud(livre l);

abrLivre *InsererLivre(abrLivre *racine, livre l);

abrLivre *RechercheLivre(abrLivre *racine, char isbn[]);

abrLivre *SupprimerLivre(abrLivre *racine, char isbn[]);

void Affichage_Trie(abrLivre *racine);


#endif