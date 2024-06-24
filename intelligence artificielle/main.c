#include <stdio.h>
#include <string.h>

int main() {
    char CH1[100];
    char CH2[100];
    char *p1, *p2;
    int TROUVE = 0;

    printf("Entrez la premiere chaine de caracteres : ");
    scanf("%s", CH1);
    printf("Entrez la deuxieme chaine de caracteres : ");
    scanf("%s", CH2);

    p1 = CH1;
    p2 = strstr(CH1, CH2);

    if (p2 != NULL) {
        TROUVE = 1;
        p1 = p2 + strlen(CH2);
        strcpy(p2, p1);
    }

    if (TROUVE) {
        printf("La premiere occurrence de CH2 dans CH1 a ete supprimee.\n");
        printf("Nouvelle chaine CH1 : %s\n", CH1);
    } else {
        printf("La chaine CH2 n'a pas ete trouvee dans CH1.\n");
    }

    return 0;
}
