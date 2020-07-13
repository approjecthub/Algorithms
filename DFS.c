#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define n 8
int visited[10];
int g[n][n]={{0,1,1,0,0,0,0,0},
		   {1,0,0,1,1,0,0,0},
		   {1,0,0,0,0,1,1,0},
		   {0,1,0,0,0,0,0,1},
		   {0,1,0,0,0,0,0,1},
		   {0,0,1,0,0,0,0,1},
		   {0,0,1,0,0,0,0,1},
		   {0,0,0,1,1,1,1,0}};
void DFS(int v){
	int i;
	visited[v]=1;
	printf("%d ",v+1);
	for(i=0;i<n;i++){
		if(g[v][i]==1)
		if(visited[i] == 0)
		DFS(i);
	}
}
main()
{
	int v=8;
	DFS(v-1);
	printf("\n..........Traversal completed");
	getch();
}


