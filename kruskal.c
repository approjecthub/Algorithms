#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int t[5][2];
int z=0;
int *p;
struct edge {
	int v1,v2;
	int weight;
};

/*void weightedunion(int i,int j){
	int temp = p[i]+p[j];
	if(p[i]>p[j]){
		p[i]=j;
		p[j] = temp;
	}
	else{
		p[j] = i;
		p[i] = temp;
	}
	for(i=0;i<z;i++)
	printf("p[i]= %d ",p[i]);
	printf("\n");
}*/

void weightedunion(int i,int j){
	p[i] = j;
}

/*int collapsingfind(int i){
	int r,s;
	r=i;
	printf("\npr= %d\n",p[r]);
	
	while(p[r]>=0){
		r = p[r];
	}
	
	while(r!=i){
		s=p[i];
		p[i]=r;
		i=s;
	}
	return s;
}*/

int collapsingfind(int i){
	while(p[i]>=0){
		i = p[i];
	}
	return i;
}

void sort(struct edge *list,int n){
	int i,c,root,j;
	struct edge temp;
	printf("n = %d\n",n);
	for(i=0;i<z;i++)
	printf("%d %d %d\n",list[i].v1,list[i].v2,list[i].weight);
	for (i = 1; i < z; i++)
    {
        c = i;
        do
        {
            root = (c - 1) / 2;             
            if (list[root].weight < list[c].weight)   
            {
                temp = list[root];
                list[root] = list[c];
                list[c] = temp;
            }
            c = root;
        } while (c != 0);
    }
    for (j = z - 1; j >= 0; j--)
    {
        temp = list[0];
        list[0] = list[j ];  
        list[j] = temp;
        root = 0;
        do 
        {
            c = 2 * root + 1;    
            if ((list[c].weight < list[c + 1].weight) && c < j-1)
                c++;
            if (list[root].weight<list[c].weight && c<j)   
            {
                temp = list[root];
                list[root] = list[c];
                list[c] = temp;
            }
            root = c;
        } while (c < j);
        
    }
}

void initialize(int n){
	int i,r=n-1;
	for(i=0;i<z;i++){
		p[i]=-1;
	}
   /* t = (int **)malloc(r * sizeof(int *)); 
    for (i=0; i<r; i++)
	t[i] = (int *)malloc(2 * sizeof(int));*/
}

struct edge* generate_edgelist(int n){
	int i,j,l=0;
	int G[6][6] = {{0,3,1,6,0,0},
                {3,0,5,0,3,0},
                {1,5,0,5,6,4},
                {6,0,5,0,0,2},
				{0,3,6,0,0,6},
				{0,0,4,2,6,0}}; 
	for(i=0;i<n;i++)
	for(j=0;j<=i;j++)
	if(G[i][j]!=0)
	z++;
	p = (int*)malloc(z * sizeof(int));
	struct edge *list = (struct edge *)malloc(z*sizeof(struct edge));
	/*	for(i=0;i<5;i++){
		for(j=0;j<2;j++)
		printf("%d\n",t[i][j]);		
	}*/
	initialize(z);
	for(i=0;i<n;i++)
	for(j=0;j<=i;j++)
	if(G[i][j]!=0){
		list[l].v1 = i;
		list[l].v2 = j;
		list[l].weight = G[i][j];
		l++;
	}	
return list;
}

int kruskal(struct edge *list,int v){
	int i,l=0,mincost=0,j=0,k=0;
		
	sort(list,v);
	printf("sorted");
	for(i=0;i<v;i++){
		j = collapsingfind(list[i].v1);
		k = collapsingfind(list[i].v2);
		printf("j = %d\n",j);
		printf("k= %d\n",k);
		if(j!=k){
			t[l][0] = list[i].v1;
			t[l][1] = list[i].v2;
			l++;
			mincost = mincost+list[i].weight;
			weightedunion(j,k);
			
		}}
			for(i=0;i<z;i++)
	printf("%d %d %d\n",list[i].v1,list[i].v2,list[i].weight);	
		if(l!=v-1){
			printf("No spanning tree possible");
			return 0;
		}
		else
		return mincost;
	

}

main(){
	int i,j;
	struct edge *list;
	int mincost=0,v=6;
	list = generate_edgelist(v);
	mincost = kruskal(list,v);
	printf("\n\nmincost = %d\n\n",mincost);
		for(i=0;i<v-1;i++){
		for(j=0;j<2;j++)
		printf("%d ",t[i][j]);
		printf("\n");		
	}
//	for(i=0;i<z;i++)
//	printf("%d",p[i]);
	getch();
}
