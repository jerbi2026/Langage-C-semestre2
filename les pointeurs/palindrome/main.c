#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char ch[10];
char *pd , *pf;
void saisi()
{
   printf("donner le mot: \t");
   scanf("%s",ch);

}
void palindrome()
{
    int a , ok=0;
    a=strlen(ch)/2;
    if (a%2==0)
    {
        pd=ch;
        pf=ch+strlen(ch)-1;
        while(pd<ch+a && pf>ch+a)
        {
            if(*pd==*pf)
            {
                pd++;
                pf--;
                ok=0;
            }
            else
                {
                    ok=1;
                    break;
                }
        }
        if(ok==1)
            printf("non palindrome\n");
        else
            printf("palindrome");
    }
    else
    {
        pd=ch;
        pf=ch+strlen(ch)-1;
        while((pd<=(ch+strlen(ch)/2)-1) && (pf>=(ch+(strlen(ch)/2)-1)))
        {
            if(*pd==*pf)
            {
                pd++;
                pf--;
            }
            else
                break;
        }
        if(pd==pf)
            printf("palindrome\n");
        else
            printf("non palindrome");
    }
}

int main()
{
    saisi();
    palindrome();
    return 0;
}
