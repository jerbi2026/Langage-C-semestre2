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


typedef struct FILA
{
    prdt* tete;
    prdt* queue;
}file;

file f;

file enfiler(file f, prdt* x)
{
    x->suiv=NULL;
    if(f.tete==NULL)
    {
        f.tete=x;
        f.queue=x;
    }
    else
    {
        f.queue->suiv=x;
        f.queue=x;
    }
    return f;
}

prdt* defiler(file* f)
{
    prdt* temp;
    if(f->tete!=NULL)
    {
        temp=f->tete;
        f->tete=f->tete->suiv;
        if(f->tete==NULL)
            f->queue=NULL;
    }
    return temp;
}

int verif(file f,int x)
{
    int ok=0;
    prdt* p;
    prdt* temp;
    if(f.tete!=NULL)
    {
        if(f.tete->id==x)
            ok=1;
        else
        {
            p=f.tete;
            temp=defiler(&f);
            f=enfiler(f,temp);
            while(f.tete!=p)
            {
                if(f.tete->id==x)
                    ok=1;
                temp=defiler(&f);
                f=enfiler(f,temp);
            }

        }
    }
    return ok;
}


file ajout_produit(file f)
{
    prdt* nv;
    nv=malloc(sizeof(prdt));
    do
    {
        printf("ID : \n");
        scanf("%d",&(nv->id));
    }while(verif(f,nv->id));
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
    f=enfiler(f,nv);
    return f;
}


void rechercher(file f)
{
    int id_rech;
    prdt* temp;
    prdt* p;
    int ok=0;
    if(f.tete==NULL)
    {
        printf("la file est vide \n");
    }
    else
    {
        printf("donner l'id a rechercher \n");
        scanf("%d",&id_rech);
        if(f.tete->id==id_rech)
        {
            printf("produit trouve\n");
            printf("id : %d\n",f.tete->id);
            printf("marque: %s\n",f.tete->marque);
            printf("libelle: %s\n",f.tete->libel);
            printf("prix: %.2f\n",f.tete->prix);
            printf("quantite: %d\n",f.tete->quant);
            ok=1;
        }
        else
        {
            p=f.tete;
            temp=defiler(&f);
            f=enfiler(f,temp);
            while(f.tete!=p)
            {
                if(f.tete->id==id_rech)
                {
                    printf("produit trouve\n");
                    printf("id : %d\n",f.tete->id);
                    printf("marque: %s\n",f.tete->marque);
                    printf("libelle: %s\n",f.tete->libel);
                    printf("prix: %.2f\n",f.tete->prix);
                    printf("quantite: %d\n",f.tete->quant);
                    ok=1;
                }
                temp=defiler(&f);
                f=enfiler(f,temp);
            }
        }
        if(ok==0)
        {
            printf("produit introuvable \n");
        }
    }
}

file modifier_prix(file f)
{
    int id_rech;
    prdt* temp;
    prdt* p;
    float nv_prix;
    int ok=0;
    if(f.tete==NULL)
    {
        printf("la file est vide \n");
    }
    else
    {
        printf("donner l'id a modifier \n");
        scanf("%d",&id_rech);
        if(f.tete->id==id_rech)
        {
            printf("produit trouve\n");
            printf("donner le nouveau prix\n");
            scanf("%f",&nv_prix);
            f.tete->prix=nv_prix;
            printf("les donnees du produit apres modification \n");
            printf("id : %d\n",f.tete->id);
            printf("marque: %s\n",f.tete->marque);
            printf("libelle: %s\n",f.tete->libel);
            printf("prix: %.2f\n",f.tete->prix);
            printf("quantite: %d\n",f.tete->quant);
            ok=1;
        }
        else
        {
            p=f.tete;
            temp=defiler(&f);
            f=enfiler(f,temp);
            while(f.tete!=p)
            {
                if(f.tete->id==id_rech)
                {
                    printf("produit trouve\n");
                    printf("donner le nouveau prix\n");
                    scanf("%f",&nv_prix);
                    f.tete->prix=nv_prix;
                    printf("les donnees du produit apres modification \n");
                    printf("id : %d\n",f.tete->id);
                    printf("marque: %s\n",f.tete->marque);
                    printf("libelle: %s\n",f.tete->libel);
                    printf("prix: %.2f\n",f.tete->prix);
                    printf("quantite: %d\n",f.tete->quant);
                    ok=1;
                }
                temp=defiler(&f);
                f=enfiler(f,temp);
            }
        }
        if(ok==0)
        {
            printf("produit introuvable \n");
        }
    }
    return f;
}

void afficher(file f)
{
    prdt* temp;
    prdt* p;
    if(f.tete==NULL)
    {
        printf("la file est vide \n");
    }
    else
    {
        printf("produit trouve\n");
        printf("id : %d\n",f.tete->id);
        printf("marque: %s\n",f.tete->marque);
        printf("libelle: %s\n",f.tete->libel);
        printf("prix: %.2f\n",f.tete->prix);
        printf("quantite: %d\n",f.tete->quant);
        printf("******************\n");
        p=f.tete;
        temp=defiler(&f);
        f=enfiler(f,temp);
        while(f.tete!=p)
        {
            printf("produit \n");
            printf("id : %d\n",f.tete->id);
            printf("marque: %s\n",f.tete->marque);
            printf("libelle: %s\n",f.tete->libel);
            printf("prix: %.2f\n",f.tete->prix);
            printf("quantite: %d\n",f.tete->quant);
            printf("******************\n");
            temp=defiler(&f);
            f=enfiler(f,temp);
        }
    }
}
int verif2(file f, char* ch1, char* ch2)
{
    prdt* p;
    prdt* temp;
    int ok=0;
    if(f.tete==NULL)
    {
        printf("file vide \n");
        return ok;
    }
    else
    {
        if(strcmp(f.tete->marque,ch1)==0&& strcmp(f.tete->libel,ch2)==0 )
        {
            ok=1;
        }
        else
        {
            p=f.tete;
            temp=defiler(&f);
            f=enfiler(f,temp);
            while(f.tete!=p)
            {
                if(strcmp(f.tete->marque,ch1)==0 && strcmp(f.tete->libel,ch2)==0 )
                {
                    ok=1;

                }
                temp=defiler(&f);
                f=enfiler(f,temp);
            }
        }
        return ok;
    }
}

file ajout(file f)
{
    char* nv_lib;
    char* nv_marq;
    prdt* p;
    prdt* temp;
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
    prdt* nv;
    int ok=verif2(f,nv_marq,nv_lib);
    if(ok==0)
    {

        nv=malloc(sizeof(prdt));
        do
        {
            printf("donner l'identifiant du produit\n");
            scanf("%d",&(nv->id));
        }while(verif(f,nv->id)==1);
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
        f=enfiler(f,nv);
    }
    else
    {
       if(strcmp(f.tete->marque,nv_marq)==0&& strcmp(f.tete->libel,nv_lib)==0 )
        {
            f.tete->quant=f.tete->quant+nv_quant;
        }
        else
        {
            p=f.tete;
            temp=defiler(&f);
            f=enfiler(f,temp);
            while(f.tete!=p)
            {
                if(strcmp(f.tete->marque,nv_marq)==0 && strcmp(f.tete->libel,nv_lib)==0 )
                {
                    f.tete->quant=f.tete->quant+nv_quant;

                }
                temp=defiler(&f);
                f=enfiler(f,temp);
            }
        }
    }
    return f;

}




file defiler_prior(file f)
{
    int id_rech;
    printf("donner le produit a supprimer\n");
    scanf("%d",&id_rech);
    prdt* temp;
    prdt* p;
    p=f.tete;
    if(f.tete->id==id_rech)
    {
        temp=defiler(&f);
        free(temp);
    }
    else
    {
        temp=defiler(&f);
        f=enfiler(f,temp);
        while(f.tete!=p)
        {
            if(id_rech==f.tete->id)
            {
                temp=defiler(&f);
                free(temp);
            }
            temp=defiler(&f);
            f=enfiler(f,temp);
        }
    }
    return f;
}

int main()
{
    f=ajout_produit(f);
    f=ajout_produit(f);
   // f=ajout_produit(f);
    //rechercher(f);
    //rechercher(f);
    //rechercher(f);
    //f=modifier_prix(f);
    printf("--------------------------------------\n");
    afficher(f);
    printf("--------------------------------------\n");
    printf("--------------------------------------\n");
    f=ajout(f);
    //f=ajout(f);
    //f=ajout(f);
    printf("--------------------------------------\n");
    afficher(f);
    f=defiler_prior(f);
    printf("--------------------------------------\n");
    afficher(f);
    f=defiler_prior(f);
    printf("--------------------------------------\n");
    afficher(f);

    return 0;
}
