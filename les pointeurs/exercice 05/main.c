#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
char ch[100];
char *pch;
int abc[26];
int *pabc;
char x='A';
void saisi()
{+

    printf("donner la chaine \n");
    gets(ch);
}
void occurence()
{
    int s;
    for (pch=ch;pch<ch+strlen(ch);pch++)
    {
        s=toupper(*pch)-'A';
        //abc[s]=rep(*pch,ch);
        abc[s]=0;
        for(int i=0;i<strlen(ch);i++)
        {
            if(*pch==ch[i])
                abc[s]++;
        }
    }

}
/*int rep(char *c , char ch[])
{
    int y=0;
    for(int i=0;i<strlen(ch);i++)
    {
        if (*c==ch[i])
            y++;
    }
    return y;
}*/
void affiche()
{
    printf("la chaine %s contient :\n",ch);
    pabc=abc;
    while(pabc<abc+26)
    {
        if(*pabc!=0)
        {
            printf("%d   fois la lettre %c \n",*pabc,x);
        }
        x++;
        pabc++;
    }
}

int main()
{
    saisi();
    occurence();
    affiche();
    return 0;
}