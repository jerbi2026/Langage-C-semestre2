#include <stdio.h>
#include <stdlib.h>

typedef struct cellule
{
    int data;
    struct cellule* suiv;
}cel;

typedef struct File
{
    cel* tete;
    cel* queue;
}file;

file f;

file ajout_file(file f, cel* temp)
{
    temp->suiv=NULL;
    if(f.tete==NULL)
    {
        f.tete=temp;
        f.queue=temp;

    }
    else
    {
        f.queue->suiv=temp;
        f.queue=temp;

    }
    return f;
}

file enfiler(file f)
{
    cel* nv;
    nv=malloc(sizeof(cel));
    printf("donner le data \n");
    scanf("%d",&(nv->data));
    f=ajout_file(f,nv);

    return f;
}

cel* defiler(file *f)
{
    cel* p;
    if(f->tete==NULL)
    {
        printf("rien a supprimer\n");
    }
    else
    {

        p=f->tete;
        f->tete=f->tete->suiv;
        if(f->tete==NULL)
            f->queue=NULL;
    }
    return p;
}

void afficher(file f)
{
    cel* temp;
    cel* p =f.tete;

    if(f.tete==NULL)
    {
        printf("la file est vide\n");
    }
    else
    {
        printf("data : %d\n",f.tete->data);
        temp=defiler(&f);
        f=ajout_file(f,temp);
        while(f.tete!=p)
        {
            printf("data : %d\n",f.tete->data);
            temp=defiler(&f);
            f=ajout_file(f,temp);

        }

    }
}

void afficher_avec_parcour(file f)
{
    cel* parc=f.tete;
    while(parc!=NULL)
    {
        printf("data : %d\n",parc->data);
        parc=parc->suiv;
    }

}
void rechercher_valeur(file f)
{
    cel*temp;
    cel* p = f.tete;
    int ok =0;
    int var_rech;
    printf("donner la valeur a rechercher\n");
    scanf("%d",&var_rech);
    if(var_rech==f.tete->data)
    {

        ok=1;

    }
    else
    {
       temp=defiler(&f);
       f=ajout_file(f,temp);
       while(f.tete!=p)
       {
           if(f.tete->data==var_rech)
           {
               ok=1;
           }
           temp=defiler(&f);
           f=ajout_file(f,temp);
       }

    }
    if(ok==1)
    {
        printf("valeur trouve\n");
    }
    else
        printf("valeur non trouve\n");
}



int main()
{

   f=enfiler(f);
   f=enfiler(f);
   f=enfiler(f);
   f=enfiler(f);
   afficher(f);
   printf("\n\n");
   afficher_avec_parcour(f);
   printf("\n\n");
   rechercher_valeur(f);
   rechercher_valeur(f);
   rechercher_valeur(f);





    return 0;
}
