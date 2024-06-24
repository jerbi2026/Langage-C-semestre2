#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char ch[100];
char *pd , *p ;
int main()
{
    printf("donner une chaine \t");
    scanf("%s",ch);
    pd=ch;
    p=pd;
    while(pd<ch+strlen(ch))
    {
        pd++;
    }
    printf("la longueur de la chaine est %d",pd-p);
    return 0;
}
