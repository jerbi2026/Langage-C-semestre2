#include <stdio.h>
#include <stdlib.h>



typedef struct cellule
{
    int data;
    struct cellule* suiv;
    struct cellule* prec;
}cel;
cel* tete;

cel* remp_liste(tete)
{
    cel* nv;
    nv=malloc(sizeof(cel));
    printf("data = \n");
    scanf("%d",&(nv->data));
    if(tete==NULL)
    {
        nv->suiv=tete;
        nv->prec=NULL;
        tete=nv;
    }
    else
    {
        cel* parc;
        parc=tete;
        while(parc->suiv!=NULL)
            parc=parc->suiv;
        nv->suiv=NULL;
        nv->prec=parc;
        parc->suiv=nv;
    }
    return tete;
}

void afficher(cel* tete)
{
    cel* parc =tete;
    while(parc!=NULL)
    {
        printf("la valeur : %d\n",parc->data);
        parc=parc->suiv;
    }
}

cel* ajout_milieu(cel* tete)
{
    cel* nv;
    cel* parc;
    nv = malloc(sizeof(cel));
    printf("data = \n");
    scanf("%d", &(nv->data));
    int ok = 0;
    if (tete == NULL)
    {
        tete = nv;
        nv->suiv = NULL;
        nv->prec = NULL;
        ok = 1;
    }
    else if (tete->data == nv->data)
    {
        nv->suiv = tete;
        nv->prec = NULL;
        tete->prec = nv;
        tete = nv;
        ok = 1;
    }
    else
    {
        parc = tete->suiv;
        while (parc != NULL && ok == 0)
        {
            if (parc->data == nv->data)
            {
                nv->suiv = parc;
                nv->prec = parc->prec;
                parc->prec->suiv = nv;
                parc->prec = nv;
                ok = 1;
            }
            parc = parc->suiv;
        }
    }
    if (ok == 1)
    {
        printf("cellule bien ajoutee\n");
    }
    else
    {
        printf("on n'a pas trouve la valeur qui semble a la nouvelle cellule\n");
    }
    return tete;
}
cel* supprimer(cel*tete)
{
    printf("donner l'entier a supprimer \n");
    int supp;
    int ok=0;
    scanf("%d",&supp);
    cel* parc = tete;
    if(supp==tete->data)
    {
        tete=parc->suiv;
        if (tete != NULL)
        {
            tete->prec = NULL;
        }
        free(parc);
        ok=1;

    }
    else
    {
        parc=parc->suiv;
        while(parc!=NULL &&  ok==0)
        {
            if(parc->data==supp)
            {
                if (parc->suiv != NULL)
                {
                    (parc->prec)->suiv = parc->suiv;
                    (parc->suiv)->prec = parc->prec;
                }
                else
                {
                    (parc->prec)->suiv = NULL;
                }
                free(parc);
                ok = 1;
            }
            parc=parc->suiv;
        }
    }
    if(ok==1)
        printf("cellule bien supprime\n");
    else
        printf("on n 'a pas trouve la valeur qui semble a la  cellule  a supprimer\n");
    return tete;
}

void afficher_inverse(cel* tete)
{
    cel*parc;
    parc=tete;
    while(parc->suiv!=NULL)
    {
        parc=parc->suiv;
    }
    while(parc!=NULL)
    {
        printf("la valeur : %d\n",parc->data);
        parc=parc->prec;
    }

}

int main()
{
    tete=remp_liste(tete);
    tete=remp_liste(tete);
    tete=remp_liste(tete);
    tete=remp_liste(tete);
    tete=remp_liste(tete);
    afficher(tete);
    tete=ajout_milieu(tete);
    tete=ajout_milieu(tete);
    afficher(tete);
    tete=supprimer(tete);
    tete=supprimer(tete);
    tete=supprimer(tete);
    afficher(tete);
    printf("----------------------------------\n");
    afficher_inverse(tete);


    return 0;
}
