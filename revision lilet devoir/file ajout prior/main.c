#include <stdio.h>
#include <stdlib.h>

typedef struct cellule
{
    int a;
    struct cellule* suiv;
}cel;

typedef struct fil
{
    cel* tete;
    cel* queue;
}file;

file f;


file enfiler(file f, cel* temp)
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

file file_meebya(file f)
{
    for(int i=0;i<2;i++)
    {
        cel* nv;
        nv=malloc(sizeof(cel));
        printf("a = \n");
        scanf("%d",&(nv->a));
        printf("------------------\n");
        f=enfiler(f,nv);
    }
    return f;
}

cel* defiler(file* f)
{
    if(f->tete==NULL)
    {
      printf("file vide \n");
      return NULL;
    }

    else
    {
        cel* temp=f->tete;
        f->tete=f->tete->suiv;
        if(f->tete==NULL)
            f->queue=NULL;
        return temp;

    }
}


file ajout_prior(file f)
{
    cel*nv;
    cel* temp;
    nv=malloc(sizeof(cel));
    printf("a = \n");
    scanf("%d",&(nv->a));
    if(f.tete==NULL)
    {
        f=enfiler(f,nv);
    }
    else
    {
        if(f.tete->a>nv->a)
        {
            nv->suiv=f.tete;
            f.tete=nv;
        }
        else
        {
            cel* p =f.tete;
            temp=defiler(&f);
            f=enfiler(f,temp);
            int ok=0;
            while(ok==0 && p!=f.tete)
            {
                if(f.tete->a>nv->a)
                {
                    nv->suiv=f.tete;
                    f.tete=nv;
                    ok=1;
                }
                temp=defiler(&f);
                f=enfiler(f,temp);
            }
            if(ok==0)
            {
                f=enfiler(f,nv);
            }
            while(p!=f.tete)
            {
                temp=defiler(&f);
                f=enfiler(f,temp);
            }
        }
    }
    return f;
}

void affiche(file f)
{
    cel* parc;
    parc=f.tete;
    while(parc!=NULL)
    {
        printf("valeur :  %d\n",parc->a);
        parc=parc->suiv;
    }
}

int main()
{
    f=file_meebya(f);
    f=ajout_prior(f);
    f=ajout_prior(f);
    f=ajout_prior(f);
    affiche(f);
    return 0;
}
