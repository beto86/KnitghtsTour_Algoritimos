#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <conio.h>
#include <graphics.h>

//declarations
int G[6][8], M[64], size, moves=0, padsize, s;
clock_t begin;

void endtour();
void knight(int x, int y);
void printout();


int main() {

    size=5; //fixa o tamanho do tabuleiro

    padsize=floor(log10(abs(size*size))) + 2;

    //inicializa
    for (int i=0; i<size; i++) {
        for (int n=0; n<size; n++) {
            G[i][n]=0;
        }
    }

    begin = clock();
    knight(0, 0);


    printf("SOLUCAO ENCONTRADA\n");
    return 0;
}

void knight(int x, int y) {
    if (x<size && y<size && y>=0 && x>=0) {
        if (G[x][y]==0) {
            G[x][y]=moves;
        }
        else return;
    }
    else return;

    //verifica se o tour foi terminado
    if (moves==(size*size)) endtour();

    knight(x+1, y-2);
    knight(x+1, y+2);
    knight(x-1, y-2);
    knight(x-1, y+2);
    knight(x+2, y-1);
    knight(x+2, y+1);
    knight(x-2, y-1);
    knight(x-2, y+1);

    //se todos os pontos verificados falharem, redefini o ponto e retorna
    G[x][y]=0;
    moves--;
    return;
}

void printout() {
    for (int i=0; i<size; i++) { //linhas
        for (int n=0; n<size; n++) { //colunas
            printf("%*d", padsize, G[i][n]);
        }
        printf("\n");
    }
    printf("\n");

}

void endtour() {
    printout(); //imprime a solução

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Tempo: %f seg\n", time_spent);



    exit(0); //   and exit
}

