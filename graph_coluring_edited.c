#include<stdio.h>
#include<conio.h>
#define n 4
int m = 3;
int G[n][n] = {{0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0},
    };
int x[n]={0};
void nextvalue(int k){
	int j;
	while(1){
		x[k] = (x[k]+1)%(m) ;
		if(x[k] == 0)
		return;
		for(j=0;j<n;j++)
		{
			if(G[k][j]!=0 && x[k]==x[j])
			break;
		}
		if(j == n)
		return;
	}
}

void mcolouring(int k){
	int l;
	while(1){
		nextvalue(k);
		if(x[k] == 0)
		return;
		if(k==n-1){
			printf("\n");	
			for(l=0;l<n;l++)
			printf("%d ",x[l]);
		}
		else
		mcolouring(k+1);
	}
}

main(){
	mcolouring(1);
	printf("\nThe end");
	getch();
}
