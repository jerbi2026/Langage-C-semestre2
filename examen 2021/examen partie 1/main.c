#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct dte
{
    int jour,mois,annee;
}date;


typedef struct citoyen
{
    int cin;
    char * nom;
    date date_naiss;
    date date_covid;
    int tel;
    int covid;
    int malade;
    struct citoyen* suiv;
}cit;





typedef struct fila
{
    cit* tete;
    cit* queue;
}file;
file f;


typedef struct Rdv
{
    int cin_rdv;
    date date_rdv;
    int heure;
    char* adrs_rdv;
    struct Rdv* suivant;
}rdv;

typedef struct fil
{
    rdv* first;
    rdv* last;
}file_rdv;

file_rdv f_rdv;




file enfiler(file f,cit* pers)
{
    pers->suiv=NULL;
    if(f.tete==NULL)
    {
        f.tete=pers;
        f.queue=pers;
    }
    else
    {
        f.queue->suiv=pers;
        f.queue=pers;
    }
    return f;
}

cit* defiler(file *f)
{
    cit* p;
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



int verif(int x , file f)
{
    int ok;
    cit* temp;
    cit* p =f.tete;

    if(f.tete==NULL)
    {
        ok=0;
    }
    else
    {

        if(x==f.tete->cin)
        {
            ok=1;
        }
        else
        {
            temp=defiler(&f);
            f=enfiler(f,temp);
            while(f.tete!=p)
            {
                if(x==f.tete->cin)
                {
                    ok=1;
                }
                temp=defiler(&f);
                f=enfiler(f,temp);
            }
        }
    }
    return ok;
}


file ajout_citoyen(file f)
{
    cit* nv;
    nv=malloc(sizeof(cit));
    nv->nom=malloc(sizeof(char));

    do
    {
        printf("donner le numero de carte cin\n");
        scanf("%d",&(nv->cin));
    }while(verif(nv->cin,f)==1);
    printf("nom : \n");
    scanf("%s",nv->nom);
    do
    {
        printf("date de naissance : \n");
        printf("jour : \n");
        scanf("%d",&(nv->date_naiss.jour));
        printf("mois : \n");
        scanf("%d",&(nv->date_naiss.mois));
        printf("annee : \n");
        scanf("%d",&(nv->date_naiss.annee));
    }while((nv->date_naiss.jour>31 || nv->date_naiss.jour<=0 ) || (nv->date_naiss.mois>12 || nv->date_naiss.mois<=0) || (nv->date_naiss.annee<1919 || nv->date_naiss.annee>2023));
    do
    {
        printf("date de covid : \n");
        printf("jour : \n");
        scanf("%d",&(nv->date_covid.jour));
        printf("mois : \n");
        scanf("%d",&(nv->date_covid.mois));
        printf("annee : \n");
        scanf("%d",&(nv->date_covid.annee));
    }while((nv->date_covid.jour>31 || nv->date_covid.jour<=0 ) || (nv->date_covid.mois>12 || nv->date_covid.mois<=0) || (nv->date_covid.annee<1919 || nv->date_covid.annee>2023));
    printf("numero de telephone \n");
    scanf("%d",&(nv->tel));
    do
    {
        printf("covid : (1 oui 0 non)\n");
        scanf("%d",&(nv->covid));
    }while(nv->covid!=0 && nv->covid!=1);
    do
    {
        printf("autre maladie : (1 oui 0 non)\n");
        scanf("%d",&(nv->malade));
    }while(nv->malade!=0 && nv->malade!=1);

    f=enfiler(f,nv);
    return f;
}



void rechercer_citoyen_methode_enfiler_defiler(file f)
{
   int ok=0;
   cit* p= f.tete;
   if(f.tete==NULL)
   {
       printf("la liste est vide\n");
   }
   else
   {

      int cin_rech;
      cit* temp;
      printf("donner le numero de cin a rechercher\n");
      scanf("%d",&cin_rech);
      if(f.tete->cin==cin_rech)
      {
          ok=1;
          printf("personne bien trouve \n");
          printf("cin : %d\n",f.tete->cin);
          printf("nom : %s\n",f.tete->nom);
          printf("date de naissance : %d-%d-%d\n",f.tete->date_naiss.jour,f.tete->date_naiss.mois,f.tete->date_naiss.annee);
          printf("date de covid : %d-%d-%d\n",f.tete->date_covid.jour,f.tete->date_covid.mois,f.tete->date_covid.annee);
          printf("numero de telephone : 216+%d\n",f.tete->tel);
          printf("covid : %d\n",f.tete->covid);
          printf("autre maladie : %d \n",f.tete->malade);
      }
      else
      {

          temp=defiler(&f);
          f=enfiler(f,temp);
          while(f.tete!=p)
          {
              if(f.tete->cin==cin_rech)
              {
                  ok=1;
                  printf("personne bien trouve \n");
                  printf("cin : %d\n",f.tete->cin);
                  printf("nom : %s\n",f.tete->nom);
                  printf("date de naissance : %d-%d-%d\n",f.tete->date_naiss.jour,f.tete->date_naiss.mois,f.tete->date_naiss.annee);
                  printf("date de covid : %d-%d-%d\n",f.tete->date_covid.jour,f.tete->date_covid.mois,f.tete->date_covid.annee);
                  printf("numero de telephone : 216+%d\n",f.tete->tel);
                  printf("covid : %d\n",f.tete->covid);
                  printf("autre maladie : %d \n",f.tete->malade);
              }
              temp=defiler(&f);
              f=enfiler(f,temp);
          }
      }
   }
   if(ok==0)
   {
       printf("carte cin introuvable\n");
   }
}

void afficher_cit(file f)
{
    cit* parc;
    parc=f.tete;
    while(parc!=NULL)
    {
        printf("--------------------------------- \n");
        printf("cin : %d\n",parc->cin);
        printf("nom : %s\n",parc->nom);
        printf("date de naissance : %d-%d-%d\n",parc->date_naiss.jour,parc->date_naiss.mois,parc->date_naiss.annee);
        printf("date de covid : %d-%d-%d\n",parc->date_covid.jour,parc->date_covid.mois,parc->date_covid.annee);
        printf("numero de telephone : 216+%d\n",parc->tel);
        printf("covid : %d\n",parc->covid);
        printf("autre maladie : %d \n",parc->malade);
        parc=parc->suiv;
    }
}


void proportion_covid(file f)
{
    float nb_pers = 0;
    float nb_covid = 0;
    cit* parc;
    parc= f.tete;
    while (parc != NULL)
    {
        if (parc->covid == 1)
            nb_covid++;
        nb_pers++;
        parc = parc->suiv;
    }
    printf("la proportion des personnes qui ont le covid est %f\n", nb_covid/nb_pers);
}


void sort(int tab[], int size)
{
    int k, j, tmp;
    for(k = 1; k <= size-1; k++)
    {
        for(j = 0; j < size-k; j++)
        {
            if(tab[j] > tab[j+1])
            {
                tmp = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = tmp;
            }
        }
    }
}

file_rdv enfiler_rdv (file_rdv f_rdv, rdv* temp , int pr[], int i)
{


    rdv* parc;
    if(i==0)
    {
        temp->suivant=NULL;
        f_rdv.first=temp;
        f_rdv.last=temp;
    }
    else
    {
        if(pr[i]==1)
        {

            temp->suivant=f_rdv.first;
            f_rdv.first=temp;
        }
        else
        {
            if(pr[i]==2)
            {
                parc=f_rdv.first;
                sort(pr,i);

                int k=0;
                while(pr[k]!=2)
                {
                    k++;
                    parc=parc->suivant;
                }
                temp->suivant=parc->suivant;
                parc->suivant=temp;
                if(temp->suivant==NULL)
                {
                    f_rdv.last=temp;
                }
            }
            else
            {
                if(pr[i]==3)
                {
                    parc=f_rdv.first;
                    sort(pr,i);

                    int k=0;
                    while(pr[k]!=3)
                    {
                        k++;
                        parc=parc->suivant;
                    }
                    temp->suivant=parc->suivant;
                    parc->suivant=temp;
                    if(temp->suivant==NULL)
                    {
                        f_rdv.last=temp;

                    }
                }
                else
                {
                    if(pr[i]==4)
                    {
                        parc=f_rdv.first;
                        sort(pr,i);

                        int k=0;
                        while(pr[k]!=4)
                        {
                            parc=parc->suivant;
                            k++;
                        }
                        temp->suivant=parc->suivant;
                        parc->suivant=temp;
                        if(temp->suivant==NULL)
                        {
                            f_rdv.last=temp;
                        }
                    }
                    else
                    {
                        temp->suivant=NULL;
                        f_rdv.last->suivant=temp;
                        f_rdv.last=temp;
                    }
                }

            }
        }
    }
    return f_rdv;
}



file_rdv ajout_rdv(file_rdv f_rdv, file f)
{


    if(f.tete==NULL)
    {
        printf("on n'a pas de rendez vous aujourd'hui\n");
    }
    else
    {
        int pr[20];
        rdv* nv_rdv;
        int i=0;
        nv_rdv = malloc(sizeof(rdv));
        nv_rdv->date_rdv.jour=10;
        nv_rdv->date_rdv.mois=10;
        nv_rdv->date_rdv.annee=2020;
        nv_rdv->heure=10;
        nv_rdv->adrs_rdv=malloc(sizeof(char));
        printf("donner l'adresse de rendez-vous\n");
        scanf("%s",nv_rdv->adrs_rdv);
        nv_rdv->cin_rdv=f.tete->cin;
        if(f.tete->date_naiss.annee<1960)
        {
            pr[i]=1;
        }
        else
        {
            if(f.tete->date_naiss.annee<1970 && f.tete->malade==1)
            {
                pr[i]=2;

            }
            else
            {
                if(f.tete->date_naiss.annee<1970 && f.tete->malade==0 && f.tete->covid==0)
                {
                    pr[i]=3;
                }
                else
                {
                    if(f.tete->date_naiss.annee<1970 && f.tete->malade==0 && f.tete->covid==1 && f.tete->date_covid.mois>(nv_rdv->date_rdv.mois+6))
                    {
                        pr[i]=4;
                    }
                    else
                    {
                        pr[i]=5;
                    }
                }

            }

        }
        f_rdv=enfiler_rdv(f_rdv,nv_rdv,pr,i);
        cit* temp;

        i=1;
        cit*p=f.tete;
        temp=defiler(&f);
        f=enfiler(f,temp);
        while(f.tete!=p)
        {
            rdv* nv_rdv;
            nv_rdv = malloc(sizeof(rdv));
            nv_rdv->date_rdv.jour=10;
            nv_rdv->date_rdv.mois=10;
            nv_rdv->date_rdv.annee=2020;
            nv_rdv->heure=10;
            nv_rdv->adrs_rdv=malloc(sizeof(char));
            printf("donner l'adresse de rendez-vous\n");
            scanf("%s",nv_rdv->adrs_rdv);
            nv_rdv->cin_rdv=f.tete->cin;
            if(f.tete->date_naiss.annee<1960)
            {
                pr[i]=1;
                f_rdv=enfiler_rdv(f_rdv,nv_rdv,pr,i);
            }
            else
            {
                if(f.tete->date_naiss.annee<1970 && f.tete->malade==1)
                {
                    pr[i]=2;
                    f_rdv=enfiler_rdv(f_rdv,nv_rdv,pr,i);
                }
                else
                {
                    if(f.tete->date_naiss.annee<1970 && f.tete->malade==0 && f.tete->covid==0)
                    {
                        pr[i]=3;
                        f_rdv=enfiler_rdv(f_rdv,nv_rdv,pr,i);
                    }
                    else
                    {
                        if(f.tete->date_naiss.annee<1970 && f.tete->malade==0 && f.tete->covid==1 && f.tete->date_covid.mois>(nv_rdv->date_rdv.mois+6))
                        {
                            pr[i]=4;
                            f_rdv=enfiler_rdv(f_rdv,nv_rdv,pr,i);
                        }
                        else
                        {
                            pr[i]=5;
                            f_rdv=enfiler_rdv(f_rdv,nv_rdv,pr,i);
                        }
                    }

                }
            }
            i++;
            temp=defiler(&f);
            f=enfiler(f,temp);
        }
    }
    return f_rdv;

}


void afficher_rdv(file_rdv f_rdv)
{
    rdv* parc;
    parc=f_rdv.first;
    while(parc!=NULL)
    {
        printf("le rendez vous \n");
        printf("cin : %d\n",parc->cin_rdv);
        printf("date de rendez vous : %d-%d-%d\n",parc->date_rdv.jour,parc->date_rdv.mois,parc->date_rdv.annee);
        printf("l'heure %d\n",parc->heure);
        printf("adresse : %s\n",parc->adrs_rdv);
        parc=parc->suivant;
    }
}

int main()
{

    f=ajout_citoyen(f);
    printf("--------------------------------------------------------------\n");
    f=ajout_citoyen(f);
    printf("--------------------------------------------------------------\n");
    f=ajout_citoyen(f);
    printf("--------------------------------------------------------------\n");
    f=ajout_citoyen(f);
    printf("--------------------------------------------------------------\n");
    rechercer_citoyen_methode_enfiler_defiler(f);
    printf("--------------------------------------------------------------\n");
    rechercer_citoyen_methode_enfiler_defiler(f);
    printf("--------------------------------------------------------------\n");
    rechercer_citoyen_methode_enfiler_defiler(f);
    printf("--------------------------------------------------------------\n");
    afficher_cit(f);
    proportion_covid(f);
    printf("--------------------------------------------------\n");
    f_rdv=ajout_rdv(f_rdv,f);
    afficher_rdv(f_rdv);

    return 0;
}
