#include <stdio.h>
#include <stdlib.h>

typedef struct element
{
    int data;
    struct element *next ;
}Element;
Element *tete ;

Element* Ajout_debut()
{
        Element *nv;
        nv=malloc(sizeof(Element));
        printf("donner l'element\n");
        scanf("%d",&(nv->data));
        printf("%d\n",nv->data);
        nv->next=tete;
        return nv;
}

void affiche()
{
    Element *parc;
    parc=tete;
    while(parc!=NULL)
    {
        printf("%d",parc->data);
                printf("*******");


        parc=parc->next;
    }
}

int main()
{
    tete=Ajout_debut();
    tete=Ajout_debut();
    tete=Ajout_debut();
    affiche();
    return 0;
}
