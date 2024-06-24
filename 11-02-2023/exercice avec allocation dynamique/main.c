#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *ch;

int main()
{
    ch=malloc(sizeof(char));
    printf("donner ch : \n");
    gets(ch);
    return 0;
}
