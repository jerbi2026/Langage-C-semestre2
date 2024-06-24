#include <stdio.h>
#include <stdlib.h>
typedef struct elmt
{
    int info;
    struct elmt *suiv;
}element;
element *tete;
element * ajout_fin(int x)
{
    element *p , *parc;
    p=malloc(sizeof(element));
    p->info=x;
    p->suiv=NULL;
    if(tete==NULL)
        tete=p;
    else
    {
         parc=tete;
         while(parc->suiv != NULL)
         {
             parc=parc->suiv;
         }
         parc->suiv=p;


    }
    return tete;



}
element* ajout_milieu(int pos)
{
    element *p;
    p= malloc(sizeof(element));
    p->info=555555;
    int l=0;
    element *parc;
    parc=tete;
    while(parc!=NULL)
    {
        l++;
        parc=parc->suiv;
        if(l==pos)
            break;
    }
    if(parc==NULL)
        printf("la position n'existe pas \n");
    else
    {
        p->suiv=parc->suiv;
        parc->suiv=p;

    }
    return tete;


}

void affiche_liste()
{
    element *parc;
    parc=tete;
    while(parc!=NULL)
    {
        printf("%d\n",parc->info);
        parc=parc->suiv;
    }
}
int main()
{
    tete=ajout_fin(5);
    tete=ajout_fin(4);
    tete=ajout_fin(3);
    tete=ajout_fin(2);
    tete=ajout_fin(1);
    tete=ajout_fin(0);
    tete=ajout_fin(-1);
    affiche_liste();
    printf("****************************\n");
    tete=ajout_milieu(3);
    affiche_liste();
    return 0;
}
