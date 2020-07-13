#include<stdio.h>
#include<conio.h>
#define size 8
void nqueens(int k, int n,int x[]);
int place(int k,int i, int x[]);
main(){
	int l,x[size+1];
	nqueens(1,size,x);
	getch();
}

void nqueens(int k, int n,int x[]){
	int i,l;
	for(i=1;i<=n;i++){
		if(place(k,i,x)==1){
			x[k] = i;
			if(k==n){
				printf("\n");
				for(l=1;l<=n;l++)
				printf("%d ",x[l]);
			}
			else
			nqueens(k+1,n,x);
		}
	}
}

int place(int k,int i,int x[]){
	int j;
	for(j=1;j<=k-1;j++){
		if((x[j]==i) || (abs(x[j]-i)==abs(j-k)))
		return 0;
		}
		return 1;
	}

