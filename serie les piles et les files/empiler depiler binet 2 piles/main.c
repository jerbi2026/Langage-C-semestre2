#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct cellule
{
    int data ;
    struct cellule* prec;
}cel;

cel* pile;
cel* pile2;

cel* empiler_pile_vide(cel* pile)
{
    cel* nv;
    nv=malloc(sizeof(cel));
    printf("donner la valeur\n");
    scanf("%d",&(nv->data));
    nv->prec=pile;
    pile=nv;
    return pile;

}


cel* empiler(cel* pile, cel* temp)
{
    temp->prec = pile;
    pile = temp;
    return pile;
}

void afficher(cel* pile)
{

    cel* temp = NULL;
    while (pile != NULL)
    {
        int var = pile->data;
        printf("la valeur est : %d\n", var);
        temp = pile;
        pile = pile->prec;
        temp->prec = NULL;
        pile2 = empiler(pile2, temp);
    }
    while(pile2!=NULL)
    {
        temp = pile2;
        pile2 = pile2->prec;
        temp->prec = NULL;
        pile = empiler(pile, temp);
    }


}

void rechercher_valeur(cel* pile)
{
    int var_rech;
    printf("donner la valeur a rechercher\n");
    scanf("%d",&var_rech);
    cel* temp = NULL;
    int ok=0;
    while (pile != NULL)
    {
        int var = pile->data;
        if(var==var_rech)
        {
            ok=1;
        }
        temp = pile;
        pile = pile->prec;
        temp->prec = NULL;
        pile2 = empiler(pile2, temp);
    }
    while(pile2!=NULL)
    {
        temp = pile2;
        pile2 = pile2->prec;
        temp->prec = NULL;
        pile = empiler(pile, temp);
    }
    if(ok==1)
        printf("on a trouve la valeur \n");
    else
        printf("valeur introuvable\n");
}


int main()
{
    pile=empiler_pile_vide(pile);
    pile=empiler_pile_vide(pile);
    pile=empiler_pile_vide(pile);
    pile=empiler_pile_vide(pile);
    pile=empiler_pile_vide(pile);
    afficher(pile);

    rechercher_valeur(pile);
    afficher(pile);


    return 0;
}
