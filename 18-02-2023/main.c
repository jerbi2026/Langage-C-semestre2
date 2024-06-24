#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *txt[5];
int main()
{
    int i;
    for(i=0;i<5;i++)
    {
        txt[i]=malloc(sizeof(char));
        gets(txt[i]);
    }
    printf("-------------------------------\n");
    for(i=0;i<5;i++)
    {
        printf("%s\n",txt[i]);
    }
    printf("--------------------\n");
    int j=4;
    free(txt[j]);
    while(j!=0)
    {
        for(i=0;i<j;i++)
        {
            printf("%s\n",txt[i]);
        }
        printf("la case efface est %d\n",txt[j]);
        printf("press any key to continue\n");
        getchar();
        j--;
        printf("-------------------------\n");
    }
    return 0;
}


