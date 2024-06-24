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

cel* ajout_fin(cel* pile , cel* temp)
{
    if(pile==NULL)
    {
        temp->suiv=pile;
        pile=temp;
    }
    else
    {
        cel* parc = pile;
        while(parc->suiv!=NULL)
            parc=parc->suiv;
        parc->suiv=temp;
    }
    return pile;
}

void ekleb(cel* pile)
{
    cel* temp;
    int i=0;
    while(i<2)
    {
        temp=pile;
        pile=pile->suiv;
        temp->suiv=NULL;
        pile=ajout_fin(pile,temp);
        i++;
    }
    afficher(pile);

}

int main()
{
    pile=ajout_valeurs(pile);
    pile=ajout_valeurs(pile);
    pile=ajout_valeurs(pile);
    afficher(pile);
    printf("-----------\n");
    ekleb(pile);
    return 0;
}
