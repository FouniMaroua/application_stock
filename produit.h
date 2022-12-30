#ifndef PRODUIT_H_INCLUDED
#define PRODUIT_H_INCLUDED
#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
#include <stdbool.h>
struct produit{
char nom_produit[25];
int quantite_produit;
float prix_produit;
char type_produit[30];
};
typedef struct produit PRODUIT;
int saisir();
int menu();
PRODUIT* allocation_stock(int);
PRODUIT remplir_stock();
void Afficher(PRODUIT*,int);
void Supprimer(PRODUIT*,int);
void Modifier(PRODUIT*,int);
void Recherche(PRODUIT*,int);
void Ajouter(PRODUIT*,int);
void Historique();

#endif // PRODUIT_H_INCLUDED
