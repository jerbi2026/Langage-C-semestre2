#include <stdio.h>
#include <stdlib.h>
typedef struct elmt
{
    int info;
    struct elmt *suiv;
}element;
element * tete;
element * ajout_debut(int x)
{
    element * p;
    p=malloc(sizeof(element));
    p->info=x;
    p->suiv=tete;
    return tete;
}
int main()
{
    int x,y,z ;
    printf("x=:\n");
    scanf("%d",&x);
    printf("z=:\n");
    scanf("%d",&z);
    printf("y=:\n");
    scanf("%d",&y);
    tete=ajout_debut(x);
    tete=ajout_debut(y);
    tete=ajout_debut(z);

    printf("%d\n",tete->info);
    printf("%d\n",tete->info);
    printf("%d\n",tete->info);


    return 0;
}
