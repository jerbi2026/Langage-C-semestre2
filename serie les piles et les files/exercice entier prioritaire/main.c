#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cel
{
    int pr;
    char nom[20];
    struct cel* suiv;
}cellule;
cellule* tete;

cellule* ajouter_fin()
{
    cellule* x;
    x=malloc(sizeof(cellule));
    printf("donner la priorite \n");
    scanf("%d",&(x->pr));
    printf("donner le nom\n");
    scanf("%s",x->nom);
    x->suiv=NULL;
    if(tete==NULL)
    {
        tete=x;


    }
    else
    {
        cellule *parc=tete;
        while(parc->suiv!=NULL)
        {
            parc=parc->suiv;
        }
        parc->suiv=x;
    }
    return tete;

}
int nb_elemt;
void saisi()
{
    printf("donner le nombre des elements\n");
    scanf("%d",&nb_elemt);
    for(int i=0;i<nb_elemt;i++)
        tete=ajouter_fin();
}
void afficher()
{
    cellule*parc=tete;
    while(parc!=NULL)
    {
        printf("%d----%s\n",parc->pr,parc->nom);

        parc=parc->suiv;
    }
}

void retirer()
{
    cellule* parc=tete;
    int max = tete->pr;
    while(parc!=NULL)
    {
        if((parc->pr)>=max)
        {
            max=parc->pr;
        }
        parc=parc->suiv;
    }

    int verif=0;
    parc=tete;
    if(max==tete->pr)
    {
            tete=parc->suiv;
            free(parc);
            verif=1;

    }
    else
    {
        parc=parc->suiv;
        cellule*parc2=tete;
        while(parc!=NULL && verif==0)
        {

            if(parc->pr== max)
            {
                parc2->suiv=parc->suiv;
                free(parc);
                verif=1;

            }
            parc=parc->suiv;
            parc2=parc2->suiv;
        }

    }

    printf("la chaine apres le retrait\n");
    afficher();

}



int main()
{
    saisi();
    printf("la liste avant de retirer aucun element\n");
    afficher();
    retirer();

    return 0;
}
