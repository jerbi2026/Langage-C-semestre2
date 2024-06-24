#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char ch1[100];
char ch2[100];
char res[100];
char *p1;
void saisi()
{
    printf("donner ch1\n");
    scanf("%s",ch1);
    printf("donner ch2\n");
    scanf("%s",ch2);
}

void exercice()
{

    for(p1=ch1;*p1;p1++)
    {

        if(strrchr(ch2,*p1)!=0)
           supprimer(p1,ch1);

    }
    printf("\nresultat = %s",ch1);
}
void supprimer(char *c , char ch[])
{
    int i,j ;
    for(i=j=0;ch[i] != '\0' ; i++)
    {
        if(ch[i]!= *c)
            ch[j++]=ch[i];
    }
    ch[j]='\0';

}
int main()
{
    saisi();
    exercice();
    return 0;
}
