#include <stdio.h>
#include <string.h>

#define SIZEx 6
#define SIZEy 6

int Sx[] = { 2, 1,-1,-2,-2,-1, 1, 2};
int Sy[] = {-1,-2,-2,-1, 1, 2, 2, 1};
int T[SIZEx][SIZEy];
int step = 1;
int sol = 1;    //soluções

void jump(int step, int x, int y) {
	if (!T[x][y]) {    //se for 0 ele anda
		T[x][y] = step++;
		if (step>SIZEx*SIZEy) {    //no ultimo passo ele finaliza?
			printf("\nSolution: %d\n", sol++);
			printT();    //imprime!
		} else {
			for(int k=0;k<8;k++)    //tenta 8 direções.
			if (x+Sx[k]>-1 && y+Sy[k]>-1 && x+Sx[k]<SIZEx && y+Sy[k]<SIZEy)
			    jump(step,x+Sx[k],y+Sy[k]);    //go!
		}
		step--;
		T[x][y] = 0;
	}
}

void printT(void) {
	for(int i=0;i<SIZEx;i++) {
		for(int j=0;j<SIZEy;j++)
			printf(" %2d",T[i][j]);
		printf("\n");
	}
}

void main(void) {
	for(int i=0;i<SIZEx;i++) {
		for(int j=0;j<SIZEy;j++) {
			jump(step,i,j);
		}
	}
}
