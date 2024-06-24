#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct produit
{
    int id;
    char* libel;
    char* marque;
    float prix;
    int quant;
    struct produit* suiv;
}prdt;

prdt* tete;


int verif(prdt* tete,int x)
{
    int ok=0;
    if(tete!=NULL)
    {
        prdt* parc;
        parc=tete;
        while(parc!=NULL)
        {
            if(x==parc->id)
            {
                ok=1;
                break;
            }
            parc=parc->suiv;
        }
    }
    return ok;
}

prdt* ajout_produit(prdt* tete)
{
    prdt* nv;
    nv=malloc(sizeof(prdt));
    nv->suiv=NULL;
    do
    {
        printf("donner l'identifiant du produit\n");
        scanf("%d",&(nv->id));
    }while(verif(tete,nv->id)==1);
    nv->libel=malloc(sizeof(char));
    nv->marque=malloc(sizeof(char));
    printf("donner le libelle du produit\n");
    scanf("%s",nv->libel);
    printf("donner la marque du produit\n");
    scanf("%s",nv->marque);
    do
    {
        printf("donner la quantite du produit\n");
        scanf("%d",&(nv->quant));
    }while(nv->quant<0);
    do
    {
        printf("donner le prix du produit\n");
        scanf("%f",&(nv->prix));
    }while(nv->prix<0);
    if(tete==NULL)
    {
        nv->suiv=tete;
        tete=nv;

    }
    else
    {
        prdt* parc;
        parc=tete;
        while(parc->suiv!=NULL)
        {
            parc=parc->suiv;
        }
        parc->suiv=nv;
    }
    return tete;


}



void rechercher(prdt* tete)
{
    int id_rech;
    int ok=0;
    printf("donner le produit a rechercher\n");
    scanf("%d",&id_rech);
    if(tete==NULL)
    {
        printf("pas de produits\n");
    }
    else
    {
        prdt* parc;
        parc=tete;

        while(parc!=NULL && ok==0)
        {
            if(parc->id==id_rech)
            {
                printf("produit trouve\n");
                printf("id : %d\n",parc->id);
                printf("marque: %s\n",parc->marque);
                printf("libelle: %s\n",parc->libel);
                printf("prix: %.2f\n",parc->prix);
                printf("quantite: %d\n",parc->quant);
                ok=1;
            }
            parc=parc->suiv;
        }
    }
    if(ok==0)
        printf("produit introuvable\n");
}

prdt* modifier_prix(prdt* tete)
{
    int ok=0;
    int id_rech;
    printf("donner le produit a modifier\n");
    scanf("%d",&id_rech);
    if(tete==NULL)
    {
        printf("pas de produits\n");
    }
    else
    {
        prdt* parc;
        parc=tete;
        while(parc!=NULL && ok==0)
        {
            if(parc->id==id_rech)
            {
                float nv_prx;
                printf("donner le nouveau prix\n");
                scanf("%f",&nv_prx);
                parc->prix=nv_prx;
                printf("produit modifie\n");
                printf("id : %d\n",parc->id);
                printf("marque: %s\n",parc->marque);
                printf("libelle: %s\n",parc->libel);
                printf("prix: %.2f\n",parc->prix);
                printf("quantite: %d\n",parc->quant);
                ok=1;
            }
            parc=parc->suiv;
        }
    }
    if(ok==0)
        printf("produit introuvable\n");
    return tete;


}

void afficher(prdt* tete)
{
    if(tete==NULL)
        printf("pas de produit\n");
    else
    {
        prdt* parc=tete;
        while(parc!=NULL)
        {
            printf("produit:\n");
            printf("id : %d\n",parc->id);
            printf("marque: %s\n",parc->marque);
            printf("libelle: %s\n",parc->libel);
            printf("prix: %.2f\n",parc->prix);
            printf("quantite: %d\n",parc->quant);
            parc=parc->suiv;
        }
    }
}

int verif_2(prdt* tete, char* ch1, char* ch2)
{
    int trouv=0;

    if(tete!=NULL)
    {
        prdt* parc=tete;
        while(parc!=NULL && trouv==0)
        {
            if(strcmp(parc->marque,ch2)==0 && strcmp(parc->libel,ch1)==0)
            {
                trouv=1;
            }
            parc=parc->suiv;
        }
    }
    return trouv;
}


prdt* ajout(prdt* tete)
{
    char* nv_lib;
    char* nv_marq;
    nv_lib=malloc(sizeof(char));
    nv_marq=malloc(sizeof(char));
    printf("donner la marque \n");
    scanf("%s",nv_marq);
    printf("donner le libelle \n");
    scanf("%s",nv_lib);
    int nv_quant;
    do
    {
        printf("donner la quantite du produit\n");
        scanf("%d",&(nv_quant));
    }while(nv_quant<0);
    int ok=verif_2(tete,nv_lib,nv_marq);
    if(ok==0)
    {
        prdt* nv;
        nv=malloc(sizeof(prdt));
        nv->suiv=NULL;
        do
        {
            printf("donner l'identifiant du produit\n");
            scanf("%d",&(nv->id));
        }while(verif(tete,nv->id)==1);
        nv->libel=malloc(sizeof(char));
        nv->marque=malloc(sizeof(char));
        strcpy(nv->marque,nv_marq);
        strcpy(nv->libel,nv_lib);
        nv->quant=nv_quant;
        do
        {
            printf("donner le prix du produit\n");
            scanf("%f",&(nv->prix));
        }while(nv->prix<0);
        if(tete==NULL)
        {
            nv->suiv=tete;
            tete=nv;

        }
        else
        {
            prdt* parc;
            parc=tete;
            while(parc->suiv!=NULL)
            {
                parc=parc->suiv;
            }
            parc->suiv=nv;
        }

    }
    else
    {
        prdt* parc2;
        parc2=tete;
        while(parc2!=NULL)
        {
            if(strcmp(parc2->marque,nv_marq)==0 && strcmp(parc2->libel,nv_lib)==0)
            {
                parc2->quant=parc2->quant+nv_quant;
                break;
            }
            parc2=parc2->suiv;
        }
    }
    return tete;

}


void afficher_par_marque(prdt* tete)
{

    char marque[10][20];
    int i = 0, j = 0;
    int ok = 0;
    prdt* parc = tete;

    while(parc != NULL)
    {

        while(j < i && ok == 0)
        {
            if(strcmp(marque[j], parc->marque) == 0)
                ok = 1;
            j++;
        }

        if(ok == 0)
        {
            strcpy(marque[i], parc->marque);
            i++;
        }

        ok = 0;
        j = 0;
        parc = parc->suiv;
    }

    for(j = 0; j < i; j++)
    {
        printf("Produits de la marque %s :\n", marque[j]);
        parc = tete;
        while(parc != NULL)
        {
            if(strcmp(marque[j], parc->marque) == 0)
            {
                printf("  id : %d\n", parc->id);
                printf("  libelle : %s\n", parc->libel);
                printf("  prix : %.2f\n", parc->prix);
                printf("  quantité : %d\n", parc->quant);
            }
            parc = parc->suiv;
        }
    }

}






int main()
{
    tete=ajout_produit(tete);
    tete=ajout_produit(tete);
    tete=ajout_produit(tete);
    printf("\n---------------------------------------------\n");
    rechercher(tete);
    rechercher(tete);
    rechercher(tete);
    printf("\n---------------------------------------------\n");
    tete=modifier_prix(tete);
    printf("\n---------------------------------------------\n");
    afficher(tete);
    printf("\n---------------------------------------------\n");
    tete=ajout(tete);
    printf("\n---------------------------------------------\n");
    tete=ajout(tete);
    printf("\n---------------------------------------------\n");
    tete=ajout(tete);
    printf("\n---------------------------------------------\n");
    afficher(tete);
    printf("\n---------------------------------------------\n");
    afficher_par_marque(tete);
    return 0;
}
