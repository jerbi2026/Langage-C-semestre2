#include <stdio.h>
#include <stdlib.h>


typedef struct cellule
{
    int a;
    int b;
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
    for(int i=0;i<3;i++)
    {
        cel* nv;
        nv=malloc(sizeof(cel));
        printf("a = \n");
        scanf("%d",&(nv->a));
        printf("b= \n");
        scanf("%d",&(nv->b));
        printf("------------------\n");
        f=enfiler(f,nv);
    }
    return f;
}

int somme_1(cel* t)
{
    if(t==NULL)
        return 0;
    else
        return(t->a+somme_1(t->suiv));
}

int somme_2(cel* t)
{
    if(t==NULL)
        return 0;
    else
    {
        return(t->b+somme_2(t->suiv));
    }

}




void calcul_total(file f)
{
    int s1=0,s2=0;
    cel* t;
    t=f.tete;
    s1=s1+somme_1(t);

    s2=s2+somme_2(t);
    printf("somme a : %d\n",s1);
    printf("somme b : %d\n",s2);
}


int main()
{
    f=file_meebya(f);
    calcul_total(f);
    return 0;
}
