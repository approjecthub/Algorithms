#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct jobs {
	char jname;
	int deadline;
	int profit;
};

char * init_timeslot(char *t,int n){
	int i;
	t = (char*)malloc(n * sizeof(char));
	for(i=0;i<n;i++)
	t[i] = '#';
	return t;
}

void sort(struct jobs *list,int n){
	int c,d;
	struct jobs swap;
	for (c = 0 ; c < n - 1; c++)
  {
    for (d = 0 ; d < n - c - 1; d++)
    {
      if (list[d].profit < list[d+1].profit) /* For decreasing order use < */
      {
        swap = list[d];
        list[d] = list[d+1];
        list[d+1] = swap;
      }
    }
  }
}
/*void sort(struct jobs *list,int n){
	int i,c,root,j;
	struct jobs temp;
	for (i = 1; i < n; i++)
    {
        c = i;
        do
        {
            root = (c - 1) / 2;             
            if (list[root].profit > list[c].profit)   
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
        list[0] = list[j ];  
        list[j] = temp;
        root = 0;
        do 
        {
            c = 2 * root + 1;    
            if ((list[c].profit > list[c + 1].profit) && c < j-1)
                c++;
            if (list[root].profit>list[c].profit && c<j)   
            {
                temp = list[root];
                list[root] = list[c];
                list[c] = temp;
            }
            root = c;
        } while (c < j);
    }
}*/

int job_sequencing(struct jobs job[],char *t,int dmax, int n){
	int i,e=dmax,k,maxprofit=0;
	sort(job,n);
//	for(i=0;i<n;i++)
//	printf("%c %d %d\n",job[i].jname, job[i].deadline,job[i].profit);
	for(i=0;i<n;i++){
		if(e==0)
		break;
		if(dmax<job[i].deadline)
		k = dmax;
		else
		k = job[i].deadline;
		while(k>=1){
			if(t[k-1]=='#'){
				t[k-1] = job[i].jname;
				e--;
				maxprofit = maxprofit + job[i].profit;
				break ;
			}
			k--;
		}
	}
	return maxprofit;
}

main(){
	/*struct jobs job[5] = {
		{'a', 2,  60},
		{'b', 1, 100},
		{'c', 3,  20},
		{'d', 2,  40},
		{'e', 1,  20},
	};*/
	struct jobs job[5] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, 
                   {'d', 1, 25}, {'e', 3, 15}};
	int dmax=0,i,n=5,maxprofit=0;
	char *t;
	for(i=0;i<n;i++){
		if(dmax<job[i].deadline)
		dmax = job[i].deadline;
	}
	t = init_timeslot(t,dmax);
	for(i=0;i<dmax;i++)
	printf("%c ",t[i]);
	maxprofit = job_sequencing(job,t,dmax,n);
	for(i=0;i<dmax;i++)
	printf("%c ",t[i]);
	printf("\nMaximum profit = %d",maxprofit);
	getch();
}
