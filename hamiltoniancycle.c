#include<stdio.h>
#include<conio.h>
#define n 4
int G[n][n] = {{0, 1, 0, 1},
                {1, 0, 1, 0},
                {0, 1, 0, 1},
                {1, 0, 1, 0}};                
/*int G[n][n] = {{0, 1, 0, 1, 0},
                {1, 0, 1, 1, 1},
                {0, 1, 0, 0, 1},
                {1, 1, 0, 0, 1},
                {0, 1, 1, 1, 0}};*/
int x[n]={0};

void nextvalue(int k){
	int j;
	while(1){
		x[k] = (x[k]+1)%n;
		if(x[k]==0)
		return;
		if(G[x[k-1]][x[k]]!=0){
			for(j=0;j<=k-1;j++)
			if(x[j]==x[k])
			break;
			if(j==k ){
			if(k<n-1 || (k==n-1 && G[x[n-1]][x[0]]!=0)) {  			
			return;
			}
		}
	}
}
}
void hamiltonian(int k){
	int l;
	while(1){
		nextvalue(k);
		if(x[k]==0)
		return;
		if(k==n-1){
			printf("\n");
			for(l=0;l<n;l++)
			printf("%d ",x[l]);
		}
		else
		hamiltonian(k+1);
	}
} 

main(){
	hamiltonian(1);
	getch();
}
