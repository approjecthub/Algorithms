#include<stdio.h>
#include<conio.h>
#define n 3
struct job {
	float p;float w; float pw;
};
float knapsack(struct job list[],int cap){
	float npw=0;
	int i;
	sort(list);
	for(i=0;i<n;i++)
	if(cap>0 && list[i].w<=cap){
		cap = cap-list[i].w;
		npw = npw + list[i].p;
	}
	else
	break;
	if(cap>0)
	npw = npw+list[i].p * (cap/list[i].w);
	return npw;
}

void sort(struct job *list){
	int i,c,root,j;
	struct job temp;
	for (i = 1; i < n; i++)
    {
        c = i;
        do
        {
            root = (c - 1) / 2;             
            if (list[root].pw > list[c].pw)   /* to create MAX heap array */
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
            if ((list[c].pw > list[c + 1].pw) && c < j-1)
                c++;
            if (list[root].pw>list[c].pw && c<j)    /* again rearrange to max heap array */
            {
                temp = list[root];
                list[root] = list[c];
                list[c] = temp;
            }
            root = c;
        } while (c < j);
    }
}	

main(){
	int cap = 20;
	struct job list[n]={{25,18,25/18},{24,15,24/15},{15,10,15/10}};
	float r = knapsack(list,cap);
	printf("%f",r);
	getch();
}
