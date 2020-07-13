#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int t[5][2];
struct edge {
	int v1,v2;
	int weight;
};

void weightedunion(int *p,int i,int j){
	int temp = p[i]+p[j];
	if(p[i]>p[j]){
		p[i]=j;
		p[j] = temp;
	}
	else{
		p[j] = i;
		p[i] = temp;
	}
}

int collapsingfind(int *p,int i){
	int r,s;
	r=i;
	while(p[r]>0){
		r = p[r];
	}
	while(r!=i){
		s=p[i];
		p[i]=r;
		i=s;
	}
	return s;
}

void sort(struct edge *list,int n){
	int i,c,root,j;
	struct edge temp;
	for (i = 1; i < n; i++)
    {
        c = i;
        do
        {
            root = (c - 1) / 2;             
            if (list[root].weight < list[c].weight)   /* to create MAX heap array */
            {
                temp = list[root];
                list[root] = list[c];
                list[c] = temp;
            }
            c = root;
        } while (c != 0);
    }
    for (j = n - 1; j >= 0; j--)
    {
        temp = list[0];
        list[0] = list[j ];  /* swap max element with rightmost leaf element */
        list[j] = temp;
        root = 0;
        do 
        {
            c = 2 * root + 1;    /* left node of root element */
            if ((list[c].weight < list[c + 1].weight) && c < j-1)
                c++;
            if (list[root].weight<list[c].weight && c<j)    /* again rearrange to max heap array */
            {
                temp = list[root];
                list[root] = list[c];
                list[c] = temp;
            }
            root = c;
        } while (c < j);
    }
}

void initialize(int *p,int n,int **t){
	int i,r=n-1;
	for(i=0;i<n;i++){
		p[i]=-1;
	}
    /*t = (int **)malloc(r * sizeof(int *)); 
    for (i=0; i<r; i++)
	t[i] = (int *)malloc(2 * sizeof(int));*/
}

struct edge* generate_edgelist(int *p,int **t,int n){
	int i,j,z=0,l=0;
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
	printf("t = %d",t[0][0]);
	initialize(p,z,t);
	for(i=0;i<n;i++)
	for(j=0;j<=i;j++)
	if(G[i][j]!=0){
		list[l].v1 = i;
		list[l].v2 = j;
		list[l].weight = G[i][j];
		l++;
	}	

}

int kruskal(int *p,struct edge *list,int **t,int v){
	int i,l=0,mincost=0,j,k;
	sort(list,v);
	for(i=0;i<v;i++){
		j = collapsingfind(p,list[i].v1);
		k = collapsingfind(p,list[i].v2);
		if(j!=k){
			t[l][0] = list[i].v1;
			t[l][1] = list[i].v2;
			l++;
			mincost = mincost+list[i].weight;
			weightedunion(p,j,k);
		}
		if(l!=v-1){
			printf("No spanning tree possible");
			return 0;
		}
		else
		return mincost;
	}	
}

main(){
	int *p;
	struct edge *list;
	int **t;
	int mincost,v=6;
	list = generate_edgelist(p,t,v);
	//mincost = kruskal(p,list,t,v);
	
	getch();
}
