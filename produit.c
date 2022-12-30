#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include<stdlib.h>
#include <string.h>
#include "produit.h"
int saisir()
{   int nbp;
    printf("saisir le nombre du produits de votre stock : ");
    scanf("%d",&nbp);
    return nbp;
}
PRODUIT* allocation_produit(int nbp)
{   PRODUIT* produit;
    produit=(PRODUIT*)malloc(nbp*sizeof(PRODUIT));
    return produit ;
}
PRODUIT remplir_stock()
{
        PRODUIT produit;
        printf("saisir le nom du produit:");
        scanf("%s",&produit.nom_produit);
        printf("saisir la quantite du produit : ");
        scanf("%d",&produit.quantite_produit);
        printf("saisir le prix du produit");
        scanf("%f",&produit.prix_produit);
        printf("saisir le type du produit : ");
        scanf("%s",&produit.type_produit);
        return produit ;
}
void Ajouter(PRODUIT* produit,int nbp){
    system("cls");
    printf("vous avez choisit l'option ajout\n");
	char nom[25];
	printf("donner le nom du produit a ajouter\n");
	scanf("%s",&nom);
	bool test=false;
	int Q;
	for(int i=0;i<nbp;i++){
		if(*(produit+i)->nom_produit==*nom){
			printf("ce produit existe deja,donner la quantite a ajouter\n");
			scanf("%d",&Q);
			produit->quantite_produit+=Q;
			test=true;
		}
	}
	nbp+=1;
	if(test==false){
	    *(produit+nbp)->nom_produit=*nom;
        printf("saisir la quantite du produit\n");
        scanf("%d",&(produit+nbp)->quantite_produit);
        printf("saisir le prix du produit\n");
        scanf("%f",&(produit+nbp)->prix_produit);
        printf("saisir le type du produit\n");
        scanf("%s",&(produit+nbp)->type_produit);
	}
	char a[4];
    printf("entrer l annee de l'ajout:\n");
    scanf("%s",&a);
    char m[100];
    printf("entrer le mois:\n");
    scanf("%s",&m);
    char j[100];
    printf("entrer le jour:");
    scanf("%s",&j);
    strcat(j,"/");
    strcat(j,m);
    strcat(j,"/");
    strcat(j,a);
    char ch1[200]="vous avez ajouter le produit: ";
    char ch3[20]=" a la date ";
    strcat(ch1,nom);
    strcat(ch1,ch3);
    strcat(ch1,j);
    FILE*fp;
    fp=fopen("historique.txt","a");
    if (fputs(ch1,fp)==EOF){
            printf("erreur!!\n");
            return 1;
        }

    fclose(fp);
	printf("Felicitation,votre ajout est fait avec succes");
}
void Afficher(PRODUIT* produit,int nbp){
    system("cls");
    printf("vous avez choisit l'option affichage\n");
	char nom[25];
	printf("donner le nom du produit a afficher\n");
	scanf("%s",&nom);
	bool test=false;
	for(int i=0;i<nbp;i++){
		if(*(produit+i)->nom_produit==*nom)
        {
			test=true;
			printf("la quantite de ce produit est %d",(produit+i)->quantite_produit);
			printf(",son prix est %f",(produit+i)->prix_produit);
			printf("et son type est %s",(produit+i)->type_produit);
			break;
		}
    }
	if (test==false){
		printf("le produit a afficher n'existe pas");
	}

}
void Recherche(PRODUIT* produit,int nbp){
    system("cls");
    printf("vous avez choisit l'option recherche\n");
	char nom[25];
	bool test=false;
	printf("donner le nom du produit a chercher:\n");
	scanf("%s",&nom);
	for(int i=0;i<nbp;i++){
		if(*(produit+i)->nom_produit==*nom){
			test=true;
			break;
		}
    }
	if (test==true){
		printf("ce produit existe dans ce stock.\n");
	}
	else{
			printf("ce produit n'existe pas dans le stock");
	}
}
void Supprimer(PRODUIT* produit,int nbp){
    system("cls");
    printf("vous avez choisit l'option suppression\n");
    char nom[25];
	bool test=false;
	printf("donner le nom du produit a supprimer:\n");
	scanf("%s",&nom);
	for(int i=0;i<nbp;i++){
		if(*(produit+i)->nom_produit==*nom){
        	char a[4];
            printf("entrer l annee de la suppression \n");
            scanf("%s",&a);
            char m[100];
            printf("entrer le mois:\n");
            scanf("%s",&m);
            char j[100];
            printf("entrer le jour:");
            scanf("%s",&j);
            strcat(j,"/");
            strcat(j,m);
            strcat(j,"/");
            strcat(j,a);
            char ch1[100]="vous avez supprimer le produit ";
            char ch2[20]=" a la date";
            strcat(ch1,nom);
            strcat(ch1,ch2);
            strcat(ch1,j);

            FILE*fp;
            fp=fopen("historique.txt","a");

            if (fputs(ch1,fp)==EOF){
                printf("erreur!!\n");
                return 1;
            }
            fclose(fp);
            free(produit+i);
			test=true;
			break;
		}
    }
	if (test==true){
		printf("la suppression ce faite avec succes.\n");
	}
	else{
			printf("ce produit n'existe pas dans le stock");
    }
}
void Modifier(PRODUIT* produit,int nbp)
{
    system("cls");
    printf("vous avez choisit l'option modification\n");
	char nom[25];
	float prix;
	int Q;
    bool test=false;
	printf("donner le nom du produit a modifier:\n");
	scanf("%s",&nom);
	for(int i=0;i<nbp;i++)
        {
            if(*(produit+i)->nom_produit==*nom)
            {
                test=true;
                printf("donner le nouveau prix:\n");
                scanf("%f",&prix);
                (produit+i)->prix_produit=prix;
                printf("donner la nouvelle quantite:\n");
                scanf("%d",&Q);
                (produit+i)->quantite_produit=Q;
                char a[4];
                printf("entrer l annee de la modification\n");
                scanf("%s",&a);
                char m[100];
                printf("entrer le mois:\n");
                scanf("%s",&m);
                char j[100];
                printf("entrer le nombre de jour:");
                scanf("%s",&j);

                strcat(j,"/");
                strcat(j,m);
                strcat(j,"/");
                strcat(j,a);
                char ch1[100]="vous avez modifier les caracteristiques de  ";
                char ch2[20]=" a la date";
                strcat(ch1,nom);
                strcat(ch1,ch2);
                strcat(ch1,j);

                FILE*fp;
                fp=fopen("historique.txt","a");

                if (fputs(ch1,fp)==EOF){
                    printf("erreur!!\n");
                    return 1;
                }
                fclose(fp);

            }
        }
	if (test==false){
		printf("ce produit n'existe pas");
	}
	else {
        printf("felicitations,votre modification est faite avec succes.\n");
	}
}
int menu()
{
    system("cls");
    printf("****************Stock-Manager****************\n\n\n");
    printf("*******MENU*******\n\n");
    printf("1-Ajouter un produit.\n");
    printf("2-Supprimer un produit.\n");
    printf("3-Modifier un produit.\n");
    printf("4-Afficher les caracteristques d'un produit.\n");
    printf("5-Recherche d'un produit.\n");
    printf("6-Quitter\n");
    printf("7-Historique.\n");
    printf("Faites votre choix:\n");
    int choix;
    scanf("%d",&choix);
    return choix;
}
void Historique(){
#define Max 1000
FILE*fp;
fp=fopen("historique.txt","r");
if(fp==NULL){
 printf("Erreur fopen \n");
  return 1;
}
char str[Max];
while (fgets(str,Max,fp)!=NULL)
  printf("%s",str);
fclose(fp);
}
