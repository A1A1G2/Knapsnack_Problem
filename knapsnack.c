#include <stdio.h>
#include <stdlib.h>

#define numEl = 5;

void printMx(int **mx);

int main(){
	int i,j,k,tmp;
	int items[5][2] = {{0,0},{1,2},{2,5},{1,4},{3,1}};// weight value
	int **knMx = (int**) malloc (5*sizeof(int*));
	for(i = 0;i<5;i++){
		knMx[i] = (int*) malloc(sizeof(int)*5);
	}
	for(i = 0;i<5;i++){
		for(j = 0;j<5;j++){
			if(i-1<0){
				knMx[i][j] = 0;
			}else
			if(j-items[i][0]<0){
				knMx[i][j] = knMx[i-1][j];
			}else
			if(knMx[i-1][j-items[i][0]] + items[i][1] < knMx[i-1][j]){
				knMx[i][j] = knMx[i-1][j];
			}else{
				knMx[i][j] = knMx[i-1][j-items[i][0]]+items[i][1];
			}
		}
	}
	printMx(knMx);
	i=4;j=4;
	while(i && j){
		if(knMx[i][j]!=knMx[i-1][j]){
			printf("\n%d kullanildi",i);
			j -= items[i][0]; 
		}
		i--;
	}
}

void printMx(int **mx){
	int i,j;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			printf("%d ",mx[i][j]);
		}
		printf("\n");
	}
}

