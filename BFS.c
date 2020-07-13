#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define n 8
int arr[10],visited[10];
int front=0, rear=0, e=0, size=11;

int g[n][n]={{0,1,1,0,0,0,0,0},
		   {1,0,0,1,1,0,0,0},
		   {1,0,0,0,0,1,1,0},
		   {0,1,0,0,0,0,0,1},
		   {0,1,0,0,0,0,0,1},
		   {0,0,1,0,0,0,0,1},
		   {0,0,1,0,0,0,0,1},
		   {0,0,0,1,1,1,1,0}};

int isFull()
{
	if(e >= size)
	{
		printf("\nqueue is Full\n");
		return 1;
	}
	else 
	{
		return 0;
	}
}

int isEmpty()
{
	if(e <= 0)
	{
		printf("\nqueue is empty\n");
		return 1;
	}
	else
	{
		return 0;
	}
}

void enque(int d1)
{
	if(isFull() == 0)
	{
		arr[rear] = d1;
		rear++;
		e++;
	}
	else
	{
		printf("%d can not be enqueued", d1);
	}
}

int deque()
{
	int d2, i;
	if(isEmpty() == 0)
	{
		d2 = arr[front];
		arr[front] = 0;
		for(i=0; i<e; i++)
		{
			arr[i] = arr[i+1];
		}
		e--;
		rear--;
	}
	return d2;
}

void dispQue()
{
	int i;
	printf("\nEntry... ");
	for(i=e-1; i>=0; i--){
		printf(" %d ", arr[i]);
	}
	printf(" ...Exit\n");
}

void BFS(int v){
	int u=v,i;
	visited[u] = 1;
	printf("Started from %d\n",u+1);
	while(1){
		for(i=0;i<n;i++){
			if(g[u][i]==1){
				if(visited[i]==0){
					enque(i+1);
					visited[i]=1;
					printf(" %d ",i+1);
				}
			}
		}
		if(isEmpty()==1){
			visited[10] = 0;
			return;
		}
		u = deque()-1;
	}
}

main()
{
	int v=8;
	BFS(v-1);
	printf("\n..........Traversal completed");
	getch();
}


