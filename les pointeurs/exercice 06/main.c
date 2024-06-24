#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ch[100];
char c='a';
char *p;
char nvch[100];

void sup_occ()
{
    int s=0;
    for(p=ch;p<ch+strlen(ch);p++)
    {
        if(*p==c)
            s++;
    }
    if(s>1)
    {
        int x=0;
        p=ch;
        while(p<ch+strlen(ch))
        {
            if(x<1)
            {
                if (*p==c)
                {
                    x++;
                    strcpy(nvch,*p);
                }
            }
            else
                {
                    if(*p==c)
                            p++;
                    strcpy(nvch,*p);
                }
            p++;
        }
    }
    printf("\nla nouvelle chaine est %s\n",nvch);
}

int main()
{
    printf("donner la chaine \n");
    scanf("%s",ch);
    sup_occ();


    return 0;
}
