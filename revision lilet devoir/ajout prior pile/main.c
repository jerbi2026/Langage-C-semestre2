#include <stdio.h>
#include <stdlib.h>


typedef struct cellule
{
    int a;
    struct cellule* suiv;
}cel;

cel* pile;
cel* pile2;
cel* empiler(cel* pile , cel* nv)
{
    nv->suiv=pile;
    pile=nv;
    return pile;
}



cel* ajout_valeurs(cel* pile)
{
    cel* nv;
    nv=malloc(sizeof(cel));
    printf("a = \n");
    scanf("%d",&(nv->a));
    pile=empiler(pile,nv);
    return pile;
}

cel* ajout_prior(cel* pile)
{
    cel* nv;
    cel* temp;
    nv=malloc(sizeof(cel));
    printf("a = \n");
    scanf("%d",&(nv->a));
    if(pile==NULL)
    {
        pile=empiler(pile,nv);
    }
    else
    {
        if(pile->a<nv->a)
        {
            pile=empiler(pile,nv);
        }
        else
        {

            temp=pile;
            pile=pile->suiv;
            temp->suiv=NULL;
            pile2=empiler(pile2,temp);
            int ok=0;
            while(ok==0 && pile!=NULL)
            {
                if(pile->a<nv->a)
                {
                    pile=empiler(pile,nv);
                    ok=1;
                }
                temp=pile;
                pile=pile->suiv;
                temp->suiv=NULL;
                pile2=empiler(pile2,temp);

            }
            if(ok==0)
            {
                pile=empiler(pile,nv);
            }

            while(pile2!=NULL)
            {
                temp=pile2;
                pile2=pile2->suiv;
                temp->suiv=NULL;
                pile=empiler(pile,temp);
            }

        }
    }
    return pile;
}

void afficher(cel* pile)
{

    cel* temp = NULL;
    while (pile != NULL)
    {
        int var = pile->a;
        printf("la valeur est : %d\n", var);
        temp = pile;
        pile = pile->suiv;
        temp->suiv = NULL;
        pile2 = empiler(pile, temp);
    }
    while(pile2!=NULL)
    {
        temp = pile2;
        pile2 = pile2->suiv;
        temp->suiv = NULL;
        pile = empiler(pile, temp);
    }


}

void ekleb(cel* pile)
{
    cel* temp;
    while(pile!=NULL)
    {
        temp = pile;
        pile = pile->suiv;
        temp->suiv = NULL;
        pile2=empiler(pile2,temp);
    }
    pile=pile2;
    cel* parc = pile;

    while(parc!=NULL)
    {
        printf("valeur :%d \n",parc->a);
        parc=parc->suiv;
    }
}


int main()
{

    pile=ajout_valeurs(pile);
    pile=ajout_valeurs(pile);
    pile=ajout_valeurs(pile);
    afficher(pile);
    pile=ajout_prior(pile);
    pile=ajout_prior(pile);
    pile=ajout_prior(pile);
    afficher(pile);
    ekleb(pile);
    return 0;
}
