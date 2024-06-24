#include <stdio.h>
#include <stdlib.h>


typedef struct cellule
{
    int data;
    int pr;
    struct cellule* suiv;
}cel;

typedef struct fil
{
    cel* tete;
    cel* queue;
}file;

file f;


file enfiler(file f, cel* nv)
{
    nv->suiv=NULL;
    if(f.tete==NULL)
    {
        f.tete=nv;
        f.queue=nv;
    }
    else
    {
        f.queue->suiv=nv;
        f.queue=nv;
    }
    return f;
}


file ajout_element(file f,int x, int y)
{
    cel*nv;
    nv=malloc(sizeof(cel));
    nv->data=x;
    nv->pr=y;
    f=enfiler(f,nv);
    return f;

}

void afficher(file f)
{
    if(f.tete!=NULL)
    {
        cel*parc=f.tete;
        while(parc!=NULL)
        {
            printf("%d\t",parc->data);
            parc=parc->suiv;
        }
        printf("\n");
        parc=f.tete;
        while(parc!=NULL)
        {
            printf("%d\t",parc->pr);
            parc=parc->suiv;
        }
        printf("\n");
    }
    else
        printf("la file est vide\n");
}

cel* defiler(file* f)
{
    cel* x;
    if(f->tete==NULL)
    {
        printf("la chaine est vide\n");
    }
    else
    {
        x=f->tete;
        f->tete=f->tete->suiv;
        if(f->tete==NULL)
            f->queue=NULL;

    }
    return x;
}

file ajout_prior(file f)
{
    cel* nv;
    cel* p;
    cel* temp;
    nv = malloc(sizeof(cel));
    printf("Donner l'element a ajouter\n");
    scanf("%d", &(nv->data));
    printf("Donner la priorite de l'element a ajouter\n");
    scanf("%d", &(nv->pr));
    int ok = 0;
    nv->suiv = NULL;
    if (f.tete != NULL)
    {
        if (f.tete->pr >= nv->pr)
        {
            nv->suiv = f.tete;
            f.tete = nv;
            ok = 1;
        }
        else
        {
            p = f.tete;
            temp = defiler(&f);
            f = enfiler(f, temp);
            while (f.tete != p)
            {
                if (f.tete->pr >= nv->pr)
                {
                    f.queue->suiv=nv;
                    f.queue=nv;
                    ok = 1;
                    break;
                }
                temp = defiler(&f);
                f = enfiler(f, temp);
            }
            while(f.tete!=p)
            {
                temp = defiler(&f);
                f = enfiler(f, temp);
            }
        }
        if (ok == 0)
        {
            f = enfiler(f, nv);
        }
    }
    else
    {
        f = enfiler(f, nv);
    }
    return f;
}


int main()
{


    f=ajout_element(f,5,10);
    f=ajout_element(f,4,50);
    f=ajout_element(f,2,99);
    f=ajout_element(f,44,140);
    afficher(f);
    f=ajout_prior(f);
    f=ajout_prior(f);
    f=ajout_prior(f);
    afficher(f);
    return 0;
}
