#include <stdio.h>
#include <stdlib.h>

typedef struct cellule
{
    int data ;
    struct cellule* suiv;
}cel;

cel* tete;

cel* ajout_debut(cel* tete)
{
  cel* nv;
  nv=malloc(sizeof(cel));
  printf("donner n\n");
  scanf("%d",&(nv->data));
  nv->suiv=tete;
  tete=nv;
  return tete;
}

void affichage(cel* tete)
{
    cel* parc;
    parc=tete;
    int i=1;
    while(parc!=NULL)
    {
        printf("le nombre num %d : %d\n",i,parc->data);
        parc=parc->suiv;
        i++;
    }
}

cel* ajout_milieu(cel* tete)
{
    cel* nv ;
    nv=malloc(sizeof(cel));
    cel*parc;
    int ok=0;
    printf("donner le data de la cellule \n");
    scanf("%d",&(nv->data));
    int pos;
    printf("donner la position\n");
    scanf("%d",&pos);
    if(pos==1)
    {
        nv->suiv=tete;
        tete=nv;
        ok=1;
    }
    else
    {
        parc=tete;
        int i =2;
        while(parc!=NULL && ok==0)
        {
            if(i==pos)
            {
                nv->suiv=parc->suiv;
                parc->suiv=nv;
                ok=1;
            }
            parc=parc->suiv;
            i++;
        }

    }
    if(ok==0)
    {
        printf("position introuvable\n");
    }
    return tete;

}

cel* ajout_fin(cel* tete)
{
    cel* nv;
    nv=malloc(sizeof(cel));
    printf("donner le data \n");
    scanf("%d",&(nv->data));
    nv->suiv=NULL;
    cel* parc;
    parc=tete;
    while(parc->suiv!=NULL)
    {
        parc=parc->suiv;
    }
    parc->suiv=nv;
    return tete;

}

void recherche(cel* tete)
{
    int val;
    printf("donner la valeur a rechercher \n");
    printf("donner la valeur a rechercher \n");
    scanf("%d",&val);
    int ok=0;
    cel* parc;
    parc=tete;
    while(parc!=NULL && ok==0)
    {
        if(val==parc->data)
        {
            printf("on a trouve la valeur\n");
            ok=1;
        }
        parc=parc->suiv;
    }
    if(ok==0)
    {
        printf("pas trouve\n");
    }
}

cel* supprimer(cel* tete)
{
    int supp;
    printf("donner la valeur a supprimer\n ");
    scanf("%d",&supp);
    cel* parc = tete;
    cel*parc2=tete;
    int ok=0;
    if(parc->data==supp)
    {
        tete=parc->suiv;
        free(parc);
        ok=1;
    }
    else
    {

        parc=parc->suiv;
        while(parc!=NULL && ok==0)
        {
            if(parc->data==supp)
            {
                parc2->suiv=parc->suiv;
                free(parc);
                ok=1;
            }
            parc=parc->suiv;
            parc2=parc2->suiv;
        }
    }
    if(ok==0)
       printf("rien a supprimer\n");
    else
        printf("on a supprime %d\n",supp);
    return tete;
}



int main()
{
    tete=ajout_debut(tete);
    tete=ajout_debut(tete);
    tete=ajout_debut(tete);
    tete=ajout_debut(tete);
    tete=ajout_debut(tete);
    printf("\n\n");
    affichage(tete);
    printf("\n\n");
    tete=ajout_milieu(tete);
    affichage(tete);
    printf("\n\n");
    tete=ajout_fin(tete);
    affichage(tete);
    printf("\n\n");
    recherche(tete);
    recherche(tete);
    recherche(tete);
    printf("\n\n");
    tete=supprimer(tete);
    tete=supprimer(tete);
    tete=supprimer(tete);
    affichage(tete);


    return 0;
}
