#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <conio.h>
#include <graphics.h>

int n,x,y,s,M[64];
clock_t begin;

void Tline(float x, float y, float xl, float yl);
void jump(int d);

int main(){

    printf("entre com o tamanho do tabuleiro: ");
	scanf("%d",&n);

    int xl,yl,gd,ge,G[8][8];

    /* initializa graphics window com 700 x 700 */
     initwindow(700, 700);

    //imprime tabela do grafo
    setcolor(1);
    for(s=0;s<n+1;s++){
        Tline(s-0.5,-0.5,s-0.5,n-0.5);
        Tline(-0.5,s-0.5,n-0.5,s-0.5);
    }

    //inicializa
	for(x=0;x<n;x++)
		for(y=0;y<n;y++)
			G[x][y] = -1;

	//posição inicial
	x=0;
	y=0;
	xl=x;
	yl=y;

	//direçao do movimento padrão
	for(s=0;s<n*n;s++){
        M[s]=0;
    }
    begin = clock();
    //knight's tour
    for(s=0;s<n*n;s++){
        if(x>=0 && x<n && y>=0 && y<n && G[x][y]==-1){
            G[x][y]=s;

        }else{
            //backtracking
            s=s-1;
            jump(-1);
            while(M[s]==7){
                G[x][y]=-1;
                M[s]=0;
                s=s-1;
                jump(-1);
            }
            M[s]=M[s]+1;
        }
        jump(1);
	}

    //imprime tabuleiro
	if(s==n*n)
		printf("\nsolucao achada\n");
	else
		printf("\nNao encontrou a solução.\n");

	for(x=0;x<n;x++){
		for(y=0;y<n;y++){
			printf("%d\t",G[x][y]);
		}
		printf("\n");
	}
    //
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Tempo: %f seg\n", time_spent);

	//traçar caminho
	delay(3000);
	x=xl;
	y=yl;
	setcolor(14);
	for(s=0;s<(n*n)-1;s++){
        jump(1);
        Tline(y,x,yl,xl);
        xl=x;
        yl=y;
        Sleep(500);
	}

	getch();
    closegraph();

    return 0;

}

void Tline(float x, float y, float xl, float yl){
    line(100+70*x,100+70*y,100+70*xl,100+70*yl);
}

void jump(int d){
	if(M[s]==0){
		x = x - 1*d;
		y = y + 2*d;
	}
	else if(M[s]==1){
		x = x - 2*d;
		y = y + 1*d;
	}
	else if(M[s]==2){
		x = x - 2*d;
		y = y - 1*d;
	}
	else if(M[s]==3){
		x = x - 1*d;
		y = y - 2*d;
	}
	else if(M[s]==4){
		x = x + 1*d;
		y = y - 2*d;
	}
	else if(M[s]==5){
		x = x + 2*d;
		y = y - 1*d;
	}
	else if(M[s]==6){
		x = x + 2*d;
		y = y + 1*d;
	}
	else if(M[s]==7){
		x = x + 1*d;
		y = y + 2*d;
	}
}
