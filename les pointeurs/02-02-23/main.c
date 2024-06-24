#include <stdio.h>
#include <stdlib.h>

int a[12];
int b[7];
int n=5 , m=5;
int *pa , *pb;
void saisi()
{
    for(pa=a;pa<a+n;pa++)
    {
        printf("a[%d]=\t",pa-a);
        scanf("%d",pa);
    }
    for(pb=b;pb<b+m;pb++)
    {
        printf("b[%d]=\t",pb-b);
        scanf("%d",pb);
    }

}

void concat()
{
    pa=a+n;
    for(pb=b;pb<b+m;pb++)
    {
       *pa=*pb;
        pa++;
    }
}
void affiche()
{
    for(pa=a;pa<a+n+m;pa++)
    {
        printf("%d\n",*pa);
    }
}


int main()
{

    saisi();
    printf("*******************\n");
    concat();
    affiche();
    return 0;
}
