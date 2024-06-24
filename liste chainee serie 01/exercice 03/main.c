#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct pol
{
    float coeff;
    int exp;
    struct pol* suiv;
}polynome;
polynome *tete;

void saisi()
{
   int e;
   printf("donner l'exposant:\n");
   scanf("%d",&e);
   if(e>0)
   {
       do
       {
            polynome* p1, *temp;
            p1=malloc(sizeof(polynome));
            p1->suiv=NULL;
            printf("donner le coefficient \n");
            scanf("%f",&(p1->coeff));
            p1->exp=e;
            if(tete==NULL)
                tete=p1;
            else
            {
                temp=tete;
                while(temp->suiv!=NULL)
                    temp=temp->suiv;
                temp->suiv=p1;
            }
            printf("donner l'exposant:\n");
            scanf("%d",&e);
       }while(e>0);
   }
}
int puissance(int a, int b)
{
    int i,p=1;
    for(i=0;i<b;i++)
    {
        p=p*a;
    }
    return p;
}
void calcul()
{
    polynome* parc;
    parc=tete;
    int x;
    printf("donner la valeur de la variable x:\n");
    scanf("%d",&x);
    float somme=0;
    while(parc!=NULL)
    {
        somme=somme+((parc->coeff)*puissance(x,parc->exp));
        parc=parc->suiv;
    }
    printf("la valeur de polynome lorsque x egale a %d est %.2f\n",x,somme);
}
polynome* multiplication(polynome* tete)
{
    typedef struct mon
    {
        int n;
        float a;
    }monome;
    monome m1;
    printf("donner l'exposant de monome\n");
    scanf("%d",&m1.n);
    printf("donner le coeff de monome\n");
    scanf("%f",&m1.a);
    polynome *parc;
    parc=tete;
    while(parc!=NULL)
    {
        parc->exp=(parc->exp)+(m1.n);
        parc->coeff=(parc->coeff)*(m1.a);
        parc=parc->suiv;
    }
    return tete;
}
void affiche_liste()
{
    polynome* parc;
    parc=tete;
    while(parc!=NULL)
    {
        printf("le coefficient est %.2f\n",parc->coeff);
        printf("l'exposant est %d\n",parc->exp);
        parc=parc->suiv;
    }
}
void affiche_eq()
{
    polynome* parc;
    parc=tete;
    printf("la fonction polynome est :\n");
    while(parc!=NULL)
    {
        if(parc->exp!=0)
            printf("%.2f*x^%d",parc->coeff,parc->exp);
        else
            printf("%.2f",parc->coeff);
        if(parc->suiv!=NULL)
            printf("+");
        parc=parc->suiv;

    }
    printf("\n");

}


int main()
{

    saisi();
    debut:
    affiche_eq();
    printf("------------------------------\n");
    calcul();
    printf("------------------------------\n");
    tete=multiplication(tete);
    affiche_liste();
    printf("------------------------------\n");
    affiche_eq();
    printf("------------------------------\n");
    goto debut;

    return 0;
}
