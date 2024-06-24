#include <stdio.h>
#include <stdlib.h>
typedef struct element
{
    int x;
    struct element* suiv;
}elmt;
elmt* tete;
void saisi()
{
    int y;
    printf("pour arreter la saisie tapez un entier negatif\n");
    printf("donner un entier: \n");
    scanf("%d",&y);
    if(y>0)
    {
        do
        {
            elmt* e;
            e=malloc(sizeof(elmt));
            e->x=y;
            printf("donner un entier:\n");
            scanf("%d",&y);
            e->suiv=tete;
            tete=e;
        }while(y>0);
    }
}
elmt* inverse()
{
    elmt* par2 ;
    par2=tete;
    int n=0;
    while(par2!=NULL)
    {
        par2=par2->suiv;
        n++;
    }
    elmt* par[n];
    elmt* par1;
    par1=tete;
    par[0]=tete;
    int i=1;
    while(par1->suiv!=NULL)
    {
        par[i]=par1->suiv;
        i++;
        par1=par1->suiv;
    }
    while(par[i-1]!=NULL)
    {
        par[i]->suiv=par[i-1];
        i--;
    }
    tete=par[n-1];
    return tete;
}
void affiche_liste()
{
    elmt* par;
    par=tete;
    while(par!=NULL)
    {
        printf("element : %d\n",par->x);
        par=par->suiv;
    }
    printf("---------------------\n");
}
int main()
{
    saisi();
    tete=inverse();
    affiche_liste();
    return 0;
}
