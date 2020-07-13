#include<stdio.h>
#include<conio.h>
#define v 4
#define INF 99999

int A[v][v] = {{0,   5,  INF, 10}, 
                {INF, 0,   3, INF}, 
                {INF, INF, 0,   1}, 
                {INF, INF, INF, 0}};

int minimum(int a,int b){
	if(a>b)
	return b;
	else
	return a;
}

void display(){
	int i,j;
	for (i = 0; i < v; i++) 
    { 
        for (j = 0; j < v; j++) 
        { 
            if (A[i][j] == INF) 
                printf("%7s", "INF"); 
            else
                printf ("%7d", A[i][j]); 
        } 
        printf("\n"); 
    }
}

void pairwise_shortestpath(){
	int k,i,j;
	for(k=0;k<=v;k++){
		for(i=0;i<v;i++){
			for(j=0;j<v;j++){
				A[i][j] = minimum(A[i][j],A[i][k]+A[k][j]);
			}
		}
	}
	display();
}

main(){
	pairwise_shortestpath();
	getch();
}
