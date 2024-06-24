#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct pil
{
    char c;
    struct pil* prec;
}pile;

char ch[100];
pile* p;

pile* empiler(pile* p, char ca)
{
    pile* nv;
    nv=malloc(sizeof(pile));
    nv->prec=p;
    p=nv;
    nv->c=ca;
    return p;
}

int analyse(char ch[])
{
    int ok=0;
    int i;
    pile* temp;
    for(i=0;i<strlen(ch);i++)
    {
        if(ch[i]=='(')
        {
            p=empiler(p,ch[i]);
        }
        else
        {
            if(ch[i]==')')
            {
                if(p==NULL)
                    ok=1;
                else
                {
                    temp=p;
                    p=p->prec;
                    free(temp);
                }
            }
        }
    }
    if(p!=NULL)
    {
        ok=1;
    }
   return ok;
}



int main()
{
    printf("phrase : \n");
    gets(ch);
    int verifier=analyse(ch);
    if(verifier==0)
    {
        printf("bien\n");
    }
    else
        printf("terkez\n");


    return 0;
}
