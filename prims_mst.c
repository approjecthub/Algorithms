#include<stdio.h>
#include<conio.h>
#define infinity 9999
#define n 6
int cost[n][n]={0};
int t[n-1][2]={0};
int near[n]={0};
int G[n][n] = {{0,3,1,6,0,0},
                {3,0,5,0,3,0},
                {1,5,0,5,6,4},
                {6,0,5,0,0,2},
				{0,3,6,0,0,6},
				{0,0,4,2,6,0}}; 
void prim(){
	int min=infinity,i,j,k,l,mincost=0,k1;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
		if(G[i][j]==0 && i==j)
		cost[i][j]=0;
		else if(G[i][j]==0)
		cost[i][j] = infinity;
		else
		cost[i][j]=G[i][j];	
		}
	}
	for(i=0;i<n;i++)
	for(j=0;j<n;j++){
		if(min>cost[i][j] && cost[i][j]!=0){
			min = G[i][j];
			k = i;
			l = j;
		}
	}
//	printf("\nk=%d and l=%d\n",k,l);
	mincost = cost[k][l];
	t[0][1] = k;
	t[0][1]= l;
	for(i=0;i<n;i++){
		if(cost[i][l]<cost[i][k]){
		near[i]=l;
		}
		else{
		near[i]=k;
		}
	}
	near[k]=-1;
	near[l]=-1;
/*	printf("near");
	for(i=0;i<n;i++)
	printf("%d ",near[i]);
	printf("\nnear");*/
	for(i=1;i<n-1;i++){
	min = infinity;
		for(k1=0;k1<n;k1++){
			
		if(near[k1]!=-1 )
		if(min>cost[k1][near[k1]]){
			t[i][0]=k1;
			t[i][1]=near[k1];
			min = cost[k1][near[k1]];
			j= k1;
		} }
		mincost = mincost+cost[j][near[j]];
		near[j] = -1;
		for(k=0;k<n;k++){
			if(near[k]!=-1)
				if(cost[k][near[k]]>cost[k][j]){
			//printf("kj");
			near[k] = j;
			}
			
			
	}
}
	printf("\nmincost = %d\n",mincost);
}
main(){
	int i,j;
	prim();
	for(i=0;i<n;i++){  			//Display cost matrix
		for(j=0;j<n;j++){
		printf("%d ",cost[i][j]);
		}
		printf("\n");
	}
	
}
