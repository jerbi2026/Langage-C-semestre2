#include <stdio.h>
#include <stdlib.h>
typedef struct elmt
{
    int var;
    struct elmt *suiv;
}element;
element *tete;
element* ajout_debut()
{
    element* nv;
    nv=malloc(sizeof(element));
    printf("donner la valeur\n");
    scanf("%d",&(nv->var));
    nv->suiv=tete;
    return nv;
}
void affiche_liste()
{
    element *parc;
    parc=tete;
    while(parc!=NULL)
    {
        printf("variable : %d\n",parc->var);
        parc=parc->suiv;
    }
}
void sup_element(int x)
{
    element *parc , *parc2;
    parc=tete;
    while(parc!=NULL)
    {
        if(parc->var==x)
        {
            break;
        }
        parc=parc->suiv;
    }
    parc2=tete;
    if(parc==NULL)
    {
        printf("element non trouve\n");

    }
    else
    {
        printf("element trouve\n");
        if(parc==tete)
        {
            printf("*******\n");
            tete=parc->suiv;
            free(parc);
        }
        else
        {
            while(parc2->suiv!=parc)
            {
                parc2=parc->suiv;
            }
            printf("l'element de parc2 %d\n",parc2->var);
            if(parc->suiv!=NULL)
            {
                printf("*******\n");
                parc2->suiv=parc->suiv;
                free(parc);
            }
            else
            {
                parc2->suiv=NULL;
                free(parc);
            }
        }
    }




}
int main()
{
    int i,sup;
    for(i=0;i<3;i++)
        tete=ajout_debut();
    printf("-------------------------------------\n");
    affiche_liste();
    printf("-------------------------------------\n");
    debut:
    printf("donner la variable a supprimer de la liste\n");
    scanf("%d",&sup);
    sup_element(sup);
    affiche_liste();
    goto debut;
    return 0;
}
