#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
#include <stdbool.h>
#include <string.h>
#include"produit.h"
void main()
{
	int i,x,nbp;
	PRODUIT* produit;
	nbp=saisir();
	produit=allocation_produit(nbp);
	for(i=0;i<nbp;i++)
		*(produit+i)=remplir_stock();
    do
    {

	switch(menu())
	{
		case 1:
			Ajouter(produit,nbp);
			break;
		case 2:
			Supprimer(produit,nbp);
			break;
		case 3:
			Modifier(produit,nbp);
			break;
		case 4:
			Afficher(produit,nbp);
			break;
		case 5:
			Recherche(produit,nbp);
			break;
		case 6:
			printf("vous avez choisit de quitter.\n");
			break;
		case 7:
		    system("cls");
			printf("l'histroque de votre stock est:\n");
			Historique();
			break;
		default:
        printf("Erreur:s'il vous plait taper un choix compris entre 1 et 7\n");
    }
    printf("\npour faire autre modification tappez (1) \n");
    scanf("%d",&x);
    }while(x==1);
    return 0;
}
