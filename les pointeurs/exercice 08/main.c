#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char ch1[100];
char ch2[100];

char *p;
void exercice()
{
    p = strstr(ch1,ch2);
    if(p)
    {
        memmove(p,p+strlen(ch2),strlen(p + strlen(ch2))+1);
    }
    printf("la resultat est %s",ch1);

}

int main()
{
    printf("donner une chaine ch1\n");
    scanf("%s",ch1);
    printf("ch2:\n");
    scanf("%s",ch2);
    exercice();

    return 0;
}
