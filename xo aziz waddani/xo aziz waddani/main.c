#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <mmsystem.h>
#include <time.h>
#include <unistd.h>
#include<conio.h>


COORD coord = {0, 0} ;

void gotoxy (int x, int y)

{

coord.X = x ; coord.Y = y ; // X et Y sont les coordonn es

SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),
coord);

}

int a,b;
void place_milieu()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int console_width, console_height;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    console_width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    console_height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    a = console_width / 2;
    b = console_height / 2;
}





typedef struct joue
{
    char *nom;
    char *prenom;
    char pos;
    struct joue* next;
}joueur;


char mat[3][3];
joueur *j1, *j2;


void player()
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    j1=malloc(sizeof(joueur));
    j1->nom=malloc(sizeof(char));
    j1->prenom=malloc(sizeof(char));
    SetConsoleTextAttribute(console, FOREGROUND_RED | BACKGROUND_GREEN  | BACKGROUND_RED);
    gotoxy(a-20,0);
    printf("donner le nom et le prenom du joueur num 1 :\n");
    gotoxy(a-5,2);
    printf("nom:\n");
    SetConsoleTextAttribute(console, FOREGROUND_GREEN | BACKGROUND_GREEN  | BACKGROUND_RED);
    gotoxy(a-2,4);
    scanf("%s",j1->nom);
    SetConsoleTextAttribute(console, FOREGROUND_RED | BACKGROUND_GREEN  | BACKGROUND_RED);
    gotoxy(a-5,6);
    printf("prenom:\n");
    SetConsoleTextAttribute(console, FOREGROUND_GREEN | BACKGROUND_GREEN  | BACKGROUND_RED);
    gotoxy(a-2,8);
    scanf("%s",j1->prenom);
    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | BACKGROUND_GREEN  | BACKGROUND_RED);
    gotoxy(a-25,10);
    printf("********************************************************\n");
    j2=malloc(sizeof(joueur));
    j2->nom=malloc(sizeof(char));
    j2->prenom=malloc(sizeof(char));
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | BACKGROUND_GREEN  | BACKGROUND_RED);
    gotoxy(a-20,12);
    printf("donner le nom et le prenom du joueur num 2 :\n");
    gotoxy(a-5,14);
    printf("nom:\n");
    SetConsoleTextAttribute(console, FOREGROUND_GREEN | BACKGROUND_GREEN  | BACKGROUND_RED);
    gotoxy(a-2,16);
    scanf("%s",j2->nom);
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | BACKGROUND_GREEN  | BACKGROUND_RED);
    gotoxy(a-5,18);
    printf("prenom:\n");
    SetConsoleTextAttribute(console, FOREGROUND_GREEN | BACKGROUND_GREEN  | BACKGROUND_RED);
    gotoxy(a-2,20);
    scanf("%s",j2->prenom);
    j1->next=j2;
    j2->next=NULL;
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | BACKGROUND_GREEN  | BACKGROUND_RED);
    gotoxy(a-25,22);
    printf("***********************************************\n");
    system("cls");
    for(int i=0;i<2;i++)
    {
            SetConsoleTextAttribute(console, FOREGROUND_RED | BACKGROUND_GREEN  | BACKGROUND_RED);
            gotoxy(a-12,b-6);
            printf("Bienvenu le joueur  %s %s \n",j1->nom,j1->prenom);
            Sleep(700);
            system("cls");
            gotoxy(a-12,b-6);
            SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_GREEN  | BACKGROUND_RED);
            printf("Bienvenu le joueur  %s %s \n",j2->nom,j2->prenom);
            Sleep(700);
            system("cls");
            SetConsoleTextAttribute(console, FOREGROUND_BLUE|  BACKGROUND_GREEN  | BACKGROUND_RED);
            gotoxy(a-10,b-6);
            printf("j'espere vous aimez le jeu\n");
            Sleep(700);
            system("cls");
            SetConsoleTextAttribute(console, FOREGROUND_GREEN |   BACKGROUND_GREEN  | BACKGROUND_RED);
            gotoxy(a-5,b-4);
            printf("Waddani Aziz\n");
            Sleep(700);
            system("cls");
    }
    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_GREEN  | BACKGROUND_RED);
    printf("Press any key to start.................\n");
    getch();

}

void player1()
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    j1=malloc(sizeof(joueur));
    j1->nom=malloc(sizeof(char));
    j1->prenom=malloc(sizeof(char));
    SetConsoleTextAttribute(console, FOREGROUND_RED | BACKGROUND_GREEN  | BACKGROUND_RED);
    gotoxy(a-20,2);
    printf("donner le nom et le prenom du joueur  :\n");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | BACKGROUND_GREEN  | BACKGROUND_RED);
    gotoxy(a-5,4);
    printf("nom:\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE| BACKGROUND_GREEN  | BACKGROUND_RED);
    gotoxy(a-2,6);
    scanf("%s",j1->nom);
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | BACKGROUND_GREEN  | BACKGROUND_RED);
    gotoxy(a-5,8);
    printf("prenom:\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE| BACKGROUND_GREEN  | BACKGROUND_RED);
    gotoxy(a-2,10);
    scanf("%s",j1->prenom);
    j1->next=NULL;
    SetConsoleTextAttribute(console, FOREGROUND_BLUE| BACKGROUND_GREEN  | BACKGROUND_RED);
    gotoxy(a-25,12);
    printf("***********************************************\n");
    sleep(1);
    system("cls");
    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_GREEN  | BACKGROUND_RED);
    for(int i=0;i<3;i++)
    {
            SetConsoleTextAttribute(console, FOREGROUND_RED | BACKGROUND_GREEN  | BACKGROUND_RED);
            gotoxy(a-12,b-6);
            printf("Bienvenu le joueur  %s %s \n",j1->nom,j1->prenom);
            Sleep(700);
            system("cls");
            SetConsoleTextAttribute(console, FOREGROUND_BLUE|  BACKGROUND_GREEN  | BACKGROUND_RED);
            gotoxy(a-10,b-6);
            printf("j'espere vous aimez le jeu\n");
            Sleep(700);
            system("cls");
            SetConsoleTextAttribute(console, FOREGROUND_GREEN |   BACKGROUND_GREEN  | BACKGROUND_RED);
            gotoxy(a-5,b-4);
            printf("Waddani Aziz\n");
            Sleep(700);
            system("cls");
    }
    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_GREEN  | BACKGROUND_RED);
    printf("Press any key to start.................\n");
    getch();
}
void matrice()
{
    int i , j;
    char c='1';
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
           mat[i][j]=c;
           c++;
        }

    }
}

void affiche_mat()
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    int i , j;
    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY| BACKGROUND_GREEN  | BACKGROUND_RED);
    printf("le tableau xo :\n");
    for(i=0;i<3;i++)
    {
        SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY| BACKGROUND_GREEN  | BACKGROUND_RED);
        printf("\t\t\t\t");
        printf("\n\t\t\t\t-------------------------------------------------\n\t\t\t\t");
        printf("|\t");
        for(j=0;j<3;j++)
        {
            SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY| BACKGROUND_GREEN  | BACKGROUND_RED);
            if(mat[i][j]!='X' && mat[i][j]!='O')
            {
                    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY| BACKGROUND_GREEN  | BACKGROUND_RED);
                    printf(".\t|\t");
            }
            else
            {
                if(mat[i][j]=='X')
                {
                    SetConsoleTextAttribute(console, FOREGROUND_RED | BACKGROUND_GREEN  | BACKGROUND_RED);
                    printf("%c\t",mat[i][j]);
                    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY| BACKGROUND_GREEN  | BACKGROUND_RED);
                    printf("|\t");

                }
                else
                {
                    if(mat[i][j]=='O')
                    {
                        SetConsoleTextAttribute(console, FOREGROUND_BLUE | BACKGROUND_GREEN  | BACKGROUND_RED);
                        printf("%c\t",mat[i][j]);
                        SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY| BACKGROUND_GREEN  | BACKGROUND_RED);
                        printf("|\t");
                    }

                }
            }

        }
        printf("\n");

    }
    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY| BACKGROUND_GREEN  | BACKGROUND_RED);
    printf("\n\t\t\t\t-------------------------------------------------\n");


}

void affiche_design()
{
    gotoxy(a-40,0);
    printf("-----------------------------------------------------------------------\n \n");
    gotoxy(a-40,2);
    printf("\t \t\t\t Le jeu Tic Tac Toe \n \n");
    gotoxy(a-40,4);
    printf("-----------------------------------------------------------------------\n \n");

}
int test(joueur *p)
{
    int x=0;
    int ok=0;
    int i , j;
    if(p->pos>'9' || p->pos<'1')
        x=1;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(mat[i][j]==p->pos)
            {
                ok=1;
            }
        }
    }
    if(ok==0)
    {
        x=1;
    }
    return x ;
}

int gagner()
{
    int x=0;
    if(mat[0][0]==mat[0][1] && mat[0][1]==mat[0][2])
        x=1;
    if(mat[1][0]==mat[1][1] && mat[1][1]==mat[1][2])
        x=1;
    if(mat[2][0]==mat[2][1] && mat[2][1]==mat[2][2])
        x=1;
    if(mat[0][0]==mat[1][0] && mat[1][0]==mat[2][0])
        x=1;
    if(mat[0][1]==mat[1][1]&& mat[1][1]==mat[2][1])
        x=1;
    if(mat[0][2]==mat[1][2]&& mat[1][2]==mat[2][2])
        x=1;
    if(mat[0][0]==mat[1][1] && mat[1][1]==mat[2][2])
        x=1;
    if(mat[0][2]==mat[1][1] && mat[1][1]==mat[2][0])
        x=1;
    return x;

}
void remp_case1(joueur *p)
{
    int i=0 , j,ok=0;
    while(ok==0)
    {
        for(j=0;j<3;j++)
        {
            if(p->pos==mat[i][j])
            {
                mat[i][j]='X';
                ok=1;
                break;
            }
        }
        i++;
    }
}
void remp_case2(joueur *p)
{
    int i=0 , j,ok=0;
    while(ok==0)
    {
        for(j=0;j<3;j++)
        {
            if(p->pos==mat[i][j])
            {
                mat[i][j]='O';
                ok=1;
                break;
            }
        }
        i++;
    }
}
void start_jeu()
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY| BACKGROUND_GREEN  | BACKGROUND_RED);
    affiche_mat();
    int i=1;
    int verif=0;
    while(i<=4)
    {
        SetConsoleTextAttribute(console, FOREGROUND_RED | BACKGROUND_GREEN  | BACKGROUND_RED);

        printf("\ndonc c'est le tour du joueur num 1: %s %s\n",j1->prenom,j1->nom);
        printf("position : \t");
        do
        {
            j1->pos=getchar();
        }while(test(j1)==1);
        remp_case1(j1);
        system("cls");
        affiche_mat();
        verif=gagner();
        if(verif==1)
        {

            SetConsoleTextAttribute(console, FOREGROUND_RED | BACKGROUND_GREEN  | BACKGROUND_RED);
            gotoxy(a-40,b);
            printf("-----------------------------------------------------------------------\n ");
            gotoxy(a-25,b+2);
            printf("felicitation pour le joueur %s %s\n",j1->nom,j1->prenom);
            gotoxy(a-40,b+4);
            printf("-----------------------------------------------------------------------\n ");
            sleep(8);
            break;
        }
        SetConsoleTextAttribute(console, FOREGROUND_BLUE | BACKGROUND_GREEN  | BACKGROUND_RED);
        printf("\ndonc c'est le tour du joueur num 2: %s %s\n",j2->prenom,j2->nom);
        printf("position : \t");
        do
        {
            j2->pos=getchar();
        }while(test(j2)==1);
        remp_case2(j2);
        system("cls");
        affiche_mat();
        verif=gagner();
        if(verif==1)
        {

            SetConsoleTextAttribute(console, FOREGROUND_BLUE | BACKGROUND_GREEN  | BACKGROUND_RED);
            gotoxy(a-40,b);
            printf("-----------------------------------------------------------------------\n ");
            gotoxy(a-25,b+2);
            printf("felicitation pour le joueur %s %s\n",j2->nom,j2->prenom);
            gotoxy(a-40,b+4);
            printf("-----------------------------------------------------------------------\n ");
            sleep(8);
            break;
        }
        i++;
    }
    if(verif==0)
    {
        SetConsoleTextAttribute(console, FOREGROUND_RED | BACKGROUND_GREEN  | BACKGROUND_RED);
        printf("\ndonc c'est le tour du joueur num 1: %s %s\n",j1->prenom,j1->nom);
        printf("position : \t");
        do
        {
            j1->pos=getchar();
        }while(test(j1)==1);
        remp_case1(j1);
        system("cls");
        affiche_mat();
        verif=gagner();

        if(verif==0)
        {

            SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_GREEN  | BACKGROUND_RED);

            gotoxy(a-40,b);
            printf("-----------------------------------------------------------------------\n ");
            gotoxy(a-15,b+2);
            printf("le match est nul");
            gotoxy(a-40,b+4);
            printf("-----------------------------------------------------------------------\n ");
        }
        else
        {

           SetConsoleTextAttribute(console, FOREGROUND_RED | BACKGROUND_GREEN  | BACKGROUND_RED);
            gotoxy(a-40,b);
            printf("-----------------------------------------------------------------------\n ");
            gotoxy(a-25,b+2);
            printf("felicitation pour le joueur %s %s\n",j1->nom,j1->prenom);
            gotoxy(a-40,b+4);
            printf("-----------------------------------------------------------------------\n ");
            sleep(8);
        }

    }




}

void machine_choix()
{
    int ok=0;
    while(ok==0)
    {



        if(mat[0][0]==mat[0][1] && mat[0][2]=='3')
        {
            mat[0][2]='O';
            ok=1;
            break;
        }
        else if(mat[0][2]==mat[0][1] && mat[0][0]=='1')
        {
            mat[0][0]='O';
            ok=1;
            break;
        }
        else if(mat[1][0]==mat[1][1] && mat[1][2]=='6')
        {
            mat[1][2]='O';
            ok=1;
            break;
        }
        else if(mat[1][2]==mat[1][1] && mat[1][0]=='4')
        {
            mat[1][0]='O';
            ok=1;
            break;
        }
        else if(mat[2][0]==mat[2][1] && mat[2][2]=='9')
        {
            mat[2][2]='O';
            ok=1;
            break;
        }
        else if(mat[2][2]==mat[2][1] && mat[2][0]=='7')
        {
            mat[2][0]='O';
            ok=1;
            break;
        }
        else if(mat[0][0]==mat[1][0] && mat[2][0]=='7')
        {
            mat[2][0]='O';
            ok=1;
            break;
        }
        else if(mat[1][0]==mat[2][0] && mat[0][0]=='1')
        {
            mat[0][0]='O';
            ok=1;
            break;
        }
        else if(mat[1][1]==mat[0][1] && mat[2][1]=='8')
        {
            mat[2][1]='O';
            ok=1;
            break;
        }
       else  if(mat[1][1]==mat[2][1] && mat[0][1]=='2')
        {
            mat[0][1]='O';
            ok=1;
            break;
        }
        else if(mat[0][2]==mat[1][2] && mat[2][2]=='9')
        {
            mat[2][2]='O';
            ok=1;
            break;
        }
        else if(mat[2][2]==mat[1][2] && mat[0][2]=='3')
        {
            mat[0][2]='O';
            ok=1;
            break;
        }
        else if(mat[2][2]==mat[1][1] && mat[0][0]=='1')
        {
            mat[0][0]='O';
            ok=1;
            break;
        }
        else if(mat[0][0]==mat[1][1] && mat[2][2]=='9')
        {
            mat[2][2]='O';
            ok=1;
            break;
        }
        else if(mat[2][0]==mat[1][1] && mat[0][2]=='3')
        {
            mat[0][2]='O';
            ok=1;
            break;
        }
        else if(mat[0][2]==mat[1][1] && mat[2][0]=='7')
        {
            mat[2][0]='O';
            ok=1;
            break;
        }
        else if(mat[0][0]==mat[0][2] && mat[0][1]=='2')
        {
            mat[0][1]='O';
            ok=1;
            break;
        }
       else if(mat[1][0]==mat[1][2] && mat[1][1]=='5')
        {
            mat[1][1]='O';
            ok=1;
            break;
        }
        else if(mat[2][0]==mat[2][2] && mat[2][1]=='8')
        {
            mat[2][1]='O';
            ok=1;
            break;
        }
        else if(mat[0][0]==mat[2][0] && mat[1][0]=='4')
        {
            mat[1][0]='O';
            ok=1;
            break;
        }
        else if(mat[0][1]==mat[2][1] && mat[1][1]=='5')
        {
            mat[1][1]='O';
            ok=1;
            break;
        }
        else if(mat[0][2]==mat[2][2] && mat[1][2]=='6')
        {
            mat[1][2]='O';
            ok=1;
            break;
        }
        else if(mat[0][0]==mat[2][2] && mat[1][1]=='5')
        {
            mat[1][1]='O';
            ok=1;
            break;
        }
        else if(mat[2][0]==mat[0][2] && mat[1][1]=='5')
        {
            mat[1][1]='O';
            ok=1;
            break;
        }
        else if(mat[0][0]==mat[2][2] && mat[1][0]=='4')
        {
            mat[1][0]='O';
            ok=1;
            break;
        }
        else if(mat[0][2]==mat[2][0] && mat[1][2]=='6')
        {
            mat[1][2]='O';
            ok=1;
            break;
        }
        else if(mat[1][1]=='5')
        {
            mat[1][1]='O';
            ok=1;
            break;
        }
         else if(mat[0][0]=='1')
        {
            mat[0][0]='O';
            ok=1;
            break;
        }
         else if(mat[0][2]=='3')
        {
            mat[0][2]='O';
            ok=1;
            break;
        }
         else if(mat[2][0]=='7')
        {
            mat[2][0]='O';
            ok=1;
            break;
        }
         else if(mat[2][2]=='9')
        {
            mat[2][2]='O';
            ok=1;
            break;
        }
        else
        {
            int i=0 , j,verif=0;
            while(verif==0)
            {
                for(j=0;j<3 ;j++)
                {
                    if(mat[i][j]!='X' && mat[i][j]!='O' )
                    {
                        mat[i][j]='O';
                        verif=1;
                        break;
                    }
                }
                i++;
            }
        }

    }
}



void jeu_ord()
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

    int i =1;
    affiche_mat();
    int verif=0;
    while(i<=4)
    {
        SetConsoleTextAttribute(console, FOREGROUND_RED | BACKGROUND_GREEN  | BACKGROUND_RED);
        printf("\ndonc c'est le tour du joueur : %s %s\n",j1->prenom,j1->nom);
        printf("position : \t");
        do
        {

            j1->pos=getchar();
        }while(test(j1)==1);
        remp_case1(j1);
        system("cls");
        SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY| BACKGROUND_GREEN  | BACKGROUND_RED);
        affiche_mat();
        verif=gagner();
        if(verif==1)
        {

            SetConsoleTextAttribute(console, FOREGROUND_RED | BACKGROUND_GREEN  | BACKGROUND_RED);
            gotoxy(a-40,b);
            printf("-----------------------------------------------------------------------\n ");
            gotoxy(a-25,b+2);
            printf("felicitation pour le joueur %s %s\n",j1->nom,j1->prenom);
            gotoxy(a-40,b+4);
            printf("-----------------------------------------------------------------------\n ");
            sleep(8);
            break;
        }
        SetConsoleTextAttribute(console, FOREGROUND_BLUE | BACKGROUND_GREEN  | BACKGROUND_RED);
        printf("c'est le tour de la machine \n");
        sleep(1);
        machine_choix();
        system("cls");
        affiche_mat();
        verif=gagner();
        if(verif==1)
        {

            SetConsoleTextAttribute(console, FOREGROUND_BLUE | BACKGROUND_GREEN  | BACKGROUND_RED);
            gotoxy(a-40,b);
            printf("-----------------------------------------------------------------------\n ");
            gotoxy(a-25,b+2);
            printf("felicitation pour la machine\n");
            gotoxy(a-40,b+4);
            printf("-----------------------------------------------------------------------\n ");
            sleep(8);
            break;
        }
        i++;

    }

    if(verif==0)
    {
        SetConsoleTextAttribute(console, FOREGROUND_RED | BACKGROUND_GREEN  | BACKGROUND_RED);
        printf("\ndonc c'est le tour du joueur : %s %s\n",j1->prenom,j1->nom);
        printf("position : \t");
        do
        {
            j1->pos=getchar();
        }while(test(j1)==1);
        remp_case1(j1);
        system("cls");
        SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY| BACKGROUND_GREEN  | BACKGROUND_RED);
        affiche_mat();
        verif=gagner();
        if(verif==1)
        {

            SetConsoleTextAttribute(console, FOREGROUND_RED | BACKGROUND_GREEN  | BACKGROUND_RED);
            gotoxy(a-40,b);
            printf("-----------------------------------------------------------------------\n ");
            gotoxy(a-25,b+2);
            printf("felicitation pour le joueur %s %s\n",j1->nom,j1->prenom);
            gotoxy(a-40,b+4);
            printf("-----------------------------------------------------------------------\n ");
            sleep(8);
        }
        else
        {

            SetConsoleTextAttribute(console, FOREGROUND_RED |FOREGROUND_BLUE| BACKGROUND_GREEN  | BACKGROUND_RED);
            gotoxy(a-40,b);
            printf("-----------------------------------------------------------------------\n ");
            gotoxy(a-15,b+2);
            printf("Le match est nul");
            gotoxy(a-40,b+4);
            printf("-----------------------------------------------------------------------\n ");
        }
    }


}

int choix;
int menu()
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, FOREGROUND_RED | BACKGROUND_GREEN  | BACKGROUND_RED);
    gotoxy(a-30,6);
    printf("tapez [1] si vous voulez jouez contre l'ordinateur\n");
    SetConsoleTextAttribute(console, FOREGROUND_BLUE | BACKGROUND_GREEN  | BACKGROUND_RED);
    gotoxy(a-30,8);
    printf("tapez [2] si vous voulez jouer avec ton bestfriend\n");
    SetConsoleTextAttribute(console, FOREGROUND_GREEN | BACKGROUND_GREEN  | BACKGROUND_RED);
    gotoxy(a-30,10);
    printf("tapez [3] si vous voulez comprendre le jeu\n");
    SetConsoleTextAttribute(console, FOREGROUND_GREEN |FOREGROUND_BLUE|FOREGROUND_INTENSITY| BACKGROUND_GREEN  | BACKGROUND_RED);
    gotoxy(a-30,12);
    printf("tapez [4] si vous voulez quitter le jeu\n");
    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | BACKGROUND_GREEN  | BACKGROUND_RED);
    do
    {
        printf("votre choix:\t");
        scanf("%d",&choix);
    }while(choix!=1 && choix!=2 && choix!=3 && choix!=4);
    return choix;
}
void guide()
{
    printf("\n-------------------------------------------------------------\n");
    printf("vous devez avoir 3 X aligne ou 3 O aligne\n");
    printf("je vais avant tout vous donner la disposition du tableau xo\n");
    int i , j;
    char c='1';
    printf("le tableau xo :\n");
    for(i=0;i<3;i++)
    {
        printf("\t");
        printf("|\t");
        for(j=0;j<3;j++)
        {
            printf("%c\t|\t",c);
            c++;
        }
        printf("\n");
    }
     printf("\n-------------------------------------------------------------\n");

}







int main()
{


    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTitle("Jeu Tic Tac Toe");
    place_milieu();
    system("color 60");
    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY| BACKGROUND_GREEN  | BACKGROUND_RED);
    affiche_design();
    debut:
    choix=menu();
    if(choix==2)
    {

        system("cls");
        for(int i=0;i<3;i++)
        {
            SetConsoleTextAttribute(console, FOREGROUND_RED | BACKGROUND_GREEN  | BACKGROUND_RED);
            gotoxy(a-5,b-8);
            printf("Tic\n");
            gotoxy(a-5,b-6);
            printf("Tac\n");
            gotoxy(a-5,b-4);
            printf("Toe\n");
            Sleep(500);
            system("cls");
            SetConsoleTextAttribute(console, FOREGROUND_BLUE|  BACKGROUND_GREEN  | BACKGROUND_RED);
            gotoxy(a-5,b-4);
            printf("waddani Aziz\n");

            Sleep(500);
            system("cls");
        }
        player();
        system("cls");
        matrice();
        SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY| BACKGROUND_GREEN  | BACKGROUND_RED);;
        start_jeu();
        SetConsoleTextAttribute(console, FOREGROUND_RED | BACKGROUND_GREEN  | BACKGROUND_RED);
        printf("Press any key to continue.....\n");
        getch();
        for(int i=0;i<3;i++)
        {
            SetConsoleTextAttribute(console, FOREGROUND_RED | BACKGROUND_GREEN  | BACKGROUND_RED);
            gotoxy(a-5,b-8);
            printf("Tic\n");
            gotoxy(a-5,b-6);
            printf("Tac\n");
            gotoxy(a-5,b-4);
            printf("Toe\n");
            Sleep(500);
            system("cls");
            SetConsoleTextAttribute(console, FOREGROUND_BLUE|  BACKGROUND_GREEN  | BACKGROUND_RED);
            gotoxy(a-5,b-4);
            printf("Waddani Aziz\n");
            Sleep(500);
            system("cls");
        }
        system("cls");
        SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY| BACKGROUND_GREEN  | BACKGROUND_RED);
        affiche_design();
        goto debut;
    }
    else
        if(choix==1)
        {
            for(int i=0;i<3;i++)
            {
                SetConsoleTextAttribute(console, FOREGROUND_RED | BACKGROUND_GREEN  | BACKGROUND_RED);
                gotoxy(a-5,b-8);
                printf("Tic\n");
                gotoxy(a-5,b-6);
                printf("Tac\n");
                gotoxy(a-5,b-4);
                printf("Toe\n");
                Sleep(500);
                system("cls");
                SetConsoleTextAttribute(console, FOREGROUND_BLUE|  BACKGROUND_GREEN  | BACKGROUND_RED);
                gotoxy(a-5,b-4);
                printf("Waddani Aziz\n");
                Sleep(500);
                system("cls");
            }
            SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY| BACKGROUND_GREEN  | BACKGROUND_RED);
            player1();
            system("cls");
            matrice();
            SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY| BACKGROUND_GREEN  | BACKGROUND_RED);
            jeu_ord();
            SetConsoleTextAttribute(console, FOREGROUND_RED | BACKGROUND_GREEN  | BACKGROUND_RED);
            printf("Press any key to continue.....\n");
            getch();
            system("cls");

            SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY| BACKGROUND_GREEN  | BACKGROUND_RED);
            affiche_design();
            goto debut;
        }
        else
            if(choix==3)
            {
                for(int i=0;i<3;i++)
                {
                    SetConsoleTextAttribute(console, FOREGROUND_RED | BACKGROUND_GREEN  | BACKGROUND_RED);
                    gotoxy(a-5,b-8);
                    printf("Tic\n");
                    gotoxy(a-5,b-6);
                    printf("Tac\n");
                    gotoxy(a-5,b-4);
                    printf("Toe\n");
                    Sleep(500);
                    system("cls");
                    SetConsoleTextAttribute(console, FOREGROUND_BLUE|  BACKGROUND_GREEN  | BACKGROUND_RED);
                    gotoxy(a-5,b-4);
                    printf("Waddani Aziz\n");

                    Sleep(500);
                    system("cls");
                }
                SetConsoleTextAttribute(console, FOREGROUND_RED | BACKGROUND_GREEN  | BACKGROUND_RED);
                guide();
                printf("Press any key to continue.....\n");
                getch();
                system("cls");
                SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY| BACKGROUND_GREEN  | BACKGROUND_RED);
                affiche_design();
                goto debut;
            }


    return 0;
}
