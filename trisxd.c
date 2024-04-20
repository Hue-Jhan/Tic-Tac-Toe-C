


// tris con funzioni anti easy win
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <time.h>
#define dim 3

typedef struct {
    int righe;
    int colonne;
    char valori[dim][dim];
} tabella;
const char gamer = 'X';
const char compiuter = 'O';
int  turno = 0;
char risposta;
int  modalita;
char player;

void clrscr();
void turnomio(tabella *tabella1);
void turnomio2(tabella *tabella1);
void reset(tabella *tabella1);
void turnocompiuter(tabella *tabella1);
void vincitore(char winner);
char checkwinner(tabella tabella1);
int  checkspazi(tabella tabella1);
int  disegno(tabella tabella1);
int  valoriiniziali(tabella *tabella1);
int  checkwinnerX(tabella tabella1);
int  checkwinnerY(tabella tabella1);

int main(void) {
    tabella tabella1;
    char winner = ' ';
    do {
    turno = 0;
    valoriiniziali(&tabella1);
    printf(" \n \033[36m Welcum to tic tac toe, medium difficulty but u can manage the code and make it easier \n");
    disegno(tabella1);
    printf("\n \n \033[36mNow lets get started, type 0 if u against PC, 1 if u against a real player: ");
    scanf("%d", &modalita);
    //getchar();
    switch (modalita)   {
        case 0:
        modalita = 0; // contro pc
        break;
        case 1:
        modalita = 1; // contro big nigga
        break;
        default: 
        printf("\n \033[36mdude tf u typing?? type either 0 or 1 cuh");
        continue;   }
    printf("\n");

    while (winner == ' ' && checkspazi(tabella1) != 0) {
        turno++;
        disegno(tabella1);
        turnomio(&tabella1);
        winner = checkwinner(tabella1);
        if (winner != ' ' || checkspazi(tabella1) == 0) {
            break;          }

        if (modalita == 0) {
            turnocompiuter(&tabella1);
            winner = checkwinner(tabella1);
            if (winner != ' ' || checkspazi(tabella1) == 0) {
                break;          }       }
        else if (modalita == 1) {
            turnomio2(&tabella1);
            winner = checkwinner(tabella1);
            if (winner != ' ' || checkspazi(tabella1) == 0) {
                break;          }       }
    }
    disegno(tabella1);
    vincitore(winner);
    printf("\n \n \033[36mok match finished");
    reset(&tabella1);
    printf("\n \n \033[36m wanna play again? click (S/N) and enter, if u click sometjing else u ded: ");
    scanf("%c", &risposta);
    getchar();
    risposta = toupper(risposta);
    } while (risposta == 'S');
    printf("\n \n \033[36m k now frick off");
    system("pause");
    return 0;
    
}


void clrscr() {
    system("@cls||clear");  }

int disegno(tabella tabella1) {
    int i=0;
    int j=0;
    clrscr();
    printf("\n");
    printf("\n \033[31m                 TIC TAC TOE");
    printf("\n \033[33m              Turn %d - Player: %c \033[0m \n", turno, player);
    printf("                   |        |       \n");
    printf("       1       %c   |   %c    |  %c   \n", tabella1.valori[0][0], tabella1.valori[0][1], tabella1.valori[0][2]);
    printf("            _______|________|______ \n");
    printf("                   |        |       \n");
    printf("       2       %c   |   %c    |  %c   \n", tabella1.valori[1][0], tabella1.valori[1][1], tabella1.valori[1][2]);
    printf("            _______|________|______ \n");
    printf("                   |        |       \n");
    printf("       3       %c   |   %c    |  %c   \n", tabella1.valori[2][0], tabella1.valori[2][1], tabella1.valori[2][2]);
    printf("                   |        |       \n");
    printf("               1        2        3  \n");
    return 0;                 }

int valoriiniziali(tabella *tabella1) {   // uguale a reset si sn stupid
    int i=0;
    int j=0;
    while (i<3) {
        j=0;
        while (j<3) {
            tabella1->valori[i][j] = ' ';
            j++;
        }
        i++;    }
    return 0;                    }

void turnomio(tabella *tabella1) {
    int riga;
    int colonna;
    player = gamer;
    disegno(*tabella1);
   do {
    printf("\n \n \033[36mWhat row u wanna put the X in? choose 1-2-3 and press enter\n");
    scanf("%d", &riga);
    getchar();
    printf("\n \n \033[36mWhat column u wanna put the X in? choose 1-2-3 and press enter\n");
    scanf("%d", &colonna);
    getchar();
  //  printf("\n ai scelto la %d riga e la %d colonna, stupido coione", riga, colonna);
    riga--;
    colonna--;
    if (tabella1->valori[riga][colonna] != ' ') {
        printf("\n \n \033[36mdude that place is already occupied, or it dont even exist cuh");
    }
    else {
        tabella1->valori[riga][colonna] = gamer;
        break;
    }
   } while (1); // (tabella1->valori[riga][colonna] != ' ');
           }

void turnomio2(tabella *tabella1) {
    int riga;
    int colonna;
    player = compiuter;
    disegno(*tabella1);
   do {
    printf("\n \n \033[36mWhat row u wanna put the X in? choose 1-2-3 and press enter\n");
    scanf("%d", &riga);
    getchar();
    printf("\n \n \033[36mWhat column u wanna put the X in? choose 1-2-3 and press enter\n");
    scanf("%d", &colonna);
    getchar();
  //  printf("\n ai scelto la %d riga e la %d colonna, stupido coione", riga, colonna);
    riga--;
    colonna--;
    if (tabella1->valori[riga][colonna] != ' ') {
        printf("\n \n \033[36mdude that place is already occupied, or it dont even exist cuh");
    }
    else {
        tabella1->valori[riga][colonna] = compiuter;
        break;
    }
   } while (1); // (tabella1->valori[riga][colonna] != ' ');
           }


void turnocompiuter(tabella *tabella1) {
    srand(time(0));
    int ai1;
    int ai2;
    int righe;
    int colonne;
    if (checkspazi(*tabella1) > 0) {
        if (checkwinnerX(*tabella1) != 10 && checkwinnerY(*tabella1) != 10) {
            ai1 = checkwinnerX(*tabella1);
            ai2 = checkwinnerY(*tabella1);
            tabella1->valori[ai1][ai2] = compiuter;
            return;
        }
        do {
            righe = rand() % 3;
            colonne = rand() % 3;
        } while (tabella1->valori[righe][colonne] != ' ');
        tabella1->valori[righe][colonne] = compiuter;
    }
    else {
        vincitore(' ');    }        }

int checkwinnerX(tabella tabella1) {
    int i=0;
    int j=0;
    int x=10;
    int y=10;
    while (i<=2) { // controllo orizzontale destra
        if (tabella1.valori[i][0] == tabella1.valori[i][1] && tabella1.valori[i][2] == ' ') {
            x=i;
            y=2;
            return x; }
        i++;    }
    i=0;
    j=0;
    while (i<=2) { // controllo orizzontale sinistra
        if (tabella1.valori[i][2] == tabella1.valori[i][1]  && tabella1.valori[i][0] == ' ') {
            x=i;
            y=0;
            return x; }
        i++;    }
    i=0;
    j=0;
    while (j<3) { // controllo verticale destra
        if (tabella1.valori[0][j] == tabella1.valori[1][j] && tabella1.valori[2][j] == ' ') {
            x=2;
            y=j;
            return x; }
        j++;    }
    i=0;
    j=0;
    while (j<3) { // controllo verticale sinistra
        if (tabella1.valori[2][j] == tabella1.valori[1][j] && tabella1.valori[0][j] == ' ') {
            x=0;
            y=j;
            return x; }
        j++;    }
    i=0;
    j=0;
    if (tabella1.valori[0][0] == tabella1.valori[1][1] && tabella1.valori[2][2] == ' ') {
        x=2;
        y=2;
        return x;
    }
    if (tabella1.valori[0][2] == tabella1.valori[1][1] && tabella1.valori[2][0] == ' ') {
        x=2;
        y=0;
        return x;
    }
    if (tabella1.valori[0][0] == ' ' && tabella1.valori[1][1] == tabella1.valori[2][2]) {
        x=0;
        y=0;
        return x;
    }
    if (tabella1.valori[0][2] == ' ' && tabella1.valori[1][1] == tabella1.valori[2][0]) {
        x=0;
        y=2;
        return x;
    }
    if (tabella1.valori[0][0] == tabella1.valori[2][2] && tabella1.valori[1][1] == ' ') {
        x=1;
        y=1;
        return x;
    }
    if (tabella1.valori[0][2] == tabella1.valori[2][0] && tabella1.valori[1][1] == ' ') {
        x=1;
        y=1;
        return x;
    }
    return x;     }

int checkwinnerY(tabella tabella1) {
    int i=0;
    int j=0;
    int x=10;
    int y=10;
    while (i<=2) { // controllo orizzontale destra
        if (tabella1.valori[i][0] == tabella1.valori[i][1] && tabella1.valori[i][2] == ' ') {
            x=i;
            y=2;
            return y; }
        i++;    }
    i=0;
    j=0;
    while (i<=2) { // controllo orizzontale sinistra
        if (tabella1.valori[i][2] == tabella1.valori[i][1] && tabella1.valori[i][0] == ' ') {
            x=i;
            y=0;
            return y; }
        i++;    }
    i=0;
    j=0;
    while (j<3) { // controllo verticale destra
        if (tabella1.valori[0][j] == tabella1.valori[1][j] && tabella1.valori[2][j] == ' ') {
            x=2;
            y=j;
            return y; }
        j++;    }
    i=0;
    j=0;
    while (j<3) { // controllo verticale sinistra
        if (tabella1.valori[2][j] == tabella1.valori[1][j] && tabella1.valori[0][j] == ' ') {
            x=0;
            y=j;
            return y; }
        j++;    }
    i=0;
    j=0;
    if (tabella1.valori[0][0] == tabella1.valori[1][1] && tabella1.valori[2][2] == ' ') {
        x=2;
        y=2;
        return y;
    }
    if (tabella1.valori[0][2] == tabella1.valori[1][1] && tabella1.valori[2][0] == ' ') {
        x=2;
        y=0;
        return y;
    }
    if (tabella1.valori[0][0] == ' ' && tabella1.valori[1][1] == tabella1.valori[2][2]) {
        x=0;
        y=0;
        return y;
    }
    if (tabella1.valori[0][2] == ' ' && tabella1.valori[1][1] == tabella1.valori[2][0]) {
        x=0;
        y=2;
        return y;
    }
    if (tabella1.valori[0][0] == tabella1.valori[2][2] && tabella1.valori[1][1] == ' ') {
        x=1;
        y=1;
        return y;
    }
    if (tabella1.valori[0][2] == tabella1.valori[2][0] && tabella1.valori[1][1] == ' ') {
        x=1;
        y=1;
        return y;
    }
    return y;     }


void vincitore(char winner) {
    if (winner == gamer) {
        printf("\n \n \033[36mSWAG U WON");
    }
    else if (winner == compiuter) {
        printf("\n \n \033[36mAH NIGA U LOSE");
    }
    else {
        printf("\n \n \033[36mNobody won....");   }     }


int checkspazi(tabella tabella1) {
    int spazi = 9;
    int i = 0;
    int j = 0;
    for(int i = 0; i < 3; i++)  {
      for(int j = 0; j < 3; j++)  {
         if(tabella1.valori[i][j] != ' ')  {
            spazi--;
         }
       }
    }
    return spazi;               }


void reset(tabella *tabella1) {
    for (int i=0; i<=2; i++) {
        for (int j=0; j<=2; j++) {
            tabella1->valori[i][j] = ' ';
        }
    }                       }


char checkwinner(tabella tabella1) {
    int i=0;
    int j=0;
    while (i<=2) {
        if (tabella1.valori[i][0] == tabella1.valori[i][1] && tabella1.valori[i][0] == tabella1.valori[i][2] ) {
            return tabella1.valori[i][0];
        }
        i++;
    }
    i=0;
    j=0;
    while (j<3) {
        if (tabella1.valori[0][j] == tabella1.valori[1][j] && tabella1.valori[0][j] == tabella1.valori[2][j] ) {
            return tabella1.valori[0][j];
        }
        j++;
    }
    if (tabella1.valori[0][0] == tabella1.valori[1][1] && tabella1.valori[0][0] == tabella1.valori[2][2]) {
        return tabella1.valori[0][0];
    }
    if (tabella1.valori[0][2] == tabella1.valori[1][1] && tabella1.valori[0][2] == tabella1.valori[2][0]) {
        return tabella1.valori[0][2];
    }
    return ' ';     }
