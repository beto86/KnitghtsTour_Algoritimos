#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <conio.h>
#include <graphics.h>

int n,x,y,s,M[1000000],G[1000][1000];
clock_t begin;

void Tline(float x, float y, float xl, float yl);
void jump(int d);
int count();

int main(){

    int xl,yl,gd,ge,d,min,c,dist,min_dist;

    printf("entre com o tamanho do tabuleiro: ");
	scanf("%d",&n);

    //inicializa
	for(x=0;x<n;x++)
		for(y=0;y<n;y++)
			G[x][y] = -1;

    //inicia posição
	printf("Entre com a posicao inicial (0-%d)\n",n-1);
	printf("lin: ");
	scanf("%d",&x);
	printf("col : ");
	scanf("%d",&y);
	xl=x;
	yl=y;

    /* initializa graphics window com 700 x 700 */
    initwindow(700, 700);

    //imprime tabela do grafo
    setcolor(1);
    for(s=0;s<n+1;s++){
        Tline(s-0.5,-0.5,s-0.5,n-0.5);
        Tline(-0.5,s-0.5,n-0.5,s-0.5);
    }


    setcolor(14);
    delay(2000);

    begin = clock();

    //knight's tour
    for(s=0;;s++){
        G[x][y] = s;
        min=8;
        d=0;

        for(M[s]=0;M[s]<8;M[s]++){
            jump(1);
            if(x>=0 && x<n && y>=0 && G[x][y]==-1){
                c=count();
                dist=(x-n/2)*(x-n/2)+(y-n/2)*(y-n/2);//formula para espelhamento
                if(c<min || (c==min && dist>min_dist)){
                    min=c;
                    d=M[s];
                    min_dist=dist;
                }
            }
            jump(-1);
        }

        if(min==8)
            break;

        M[s]=d;
        jump(1);
        Tline(y,x,yl,xl);
        xl=x;
        yl=y;
        Sleep(800/n);


    }

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Tempo: %f seg\n", time_spent);
    printf("\n%f porcento completo", 100.0*s/(n*n-1));

	getch();
    closegraph();

    return 0;
}

void Tline(float x, float y, float xl, float yl){
    line(100+(580.0/n)*x,100+(580.0/n)*y,100+(580.0/n)*xl,100+(580.0/n)*yl);
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

int count(){
	int count=0;
	if((x-1)>=0 && (y+2)<n && G[x-1][y+2]==-1)
		count++;
	if((x-2)>=0 && (y+1)<n && G[x-2][y+1]==-1)
		count++;
	if((x-2)>=0 && (y-1)>=0 && G[x-2][y-1]==-1)
		count++;
	if((x-1)>=0 && (y-2)>=0 && G[x-1][y-2]==-1)
		count++;
	if((x+1)<n && (y-2)>=0 && G[x+1][y-2]==-1)
		count++;
	if((x+2)<n && (y-1)>=0 && G[x+2][y-1]==-1)
		count++;
	if((x+2)<n && (y+1)<n && G[x+2][y+1]==-1)
		count++;
	if((x+1)<n && (y+2)<n && G[x+1][y+2]==-1)
		count++;
	return count;
}
