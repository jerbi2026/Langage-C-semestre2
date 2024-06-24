#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pers
{
    char *nom;
    float taille;
    int mat;
    struct pers *suiv;
}personne;
personne *tete;
personne* ajout_fin(int x)
{

    personne *p1, *parc;
    p1=malloc(sizeof(personne));
    p1->nom=malloc(sizeof(char));
    p1->suiv=NULL;
    printf("donner le nom :\n");
    scanf("%s",p1->nom);
    printf("donner la taille\n");
    scanf("%f",&(p1->taille));
    p1->mat=x;
    if(tete==NULL)
    {
        tete=p1;
    }
    else
    {
        parc=tete;
        while(parc->suiv!=NULL)
        {
            parc=parc->suiv;
        }
        parc->suiv=p1;
    }

    return tete;
}

void affiche_liste()
{
    personne* parc;
    parc=tete;
    while(parc!=NULL)
    {
        printf("les donnees:\n");
        printf("nom:%s\n",parc->nom);
        printf("taille: %.2f\n",parc->taille);
        printf("matricule: %d\n",parc->mat);
        printf("-----------------------------\n");
        parc=parc->suiv;
    }
}

int nombre_pers(personne* tete)
{
    int nb=0;
    personne* parc;
    parc=tete;
    while(parc!=NULL)
    {
        nb++;
        parc=parc->suiv;
    }
    return nb;
}
int moy_taille(personne* tete, int nb)
{
    float moy=0;
    personne* parc ;
    parc=tete;
    while(parc!=NULL)
    {
        moy=moy+parc->taille;
        parc=parc->suiv;
    }
    moy=moy/nb;
    return moy;
}

int main()
{
    int i,nb;
    float moy;
    for(i=0;i<3;i++)
    {
        tete=ajout_fin(i+1);
    }
    printf("**************************\n");
    affiche_liste();
    printf("**************************\n");
    nb=nombre_pers(tete);
    printf("le nombre de personne est %d\n",nb);
    printf("**************************\n");
    moy=moy_taille(tete,nb);
    printf("la taille moyenne est %.2f",moy);
    return 0;
}
