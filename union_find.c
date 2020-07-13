#include<stdio.h>
#include<conio.h>
#define n 7
int p[n] = {-1};
void weightedunion(int i,int j){
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

int collapsingfind(int i){
	int r,s;
	r=i;
//	printf("\npr= %d\n",p[r]);
	
	while(p[r]>=0){
		r = p[r];
		printf("\nr = %d",r);
	}
	
	while(r!=i){
		s=p[i];
		p[i]=r;
		i=s;
	}
	return s;
}

void initialize(){
 	int i; 
	for(i=0;i<n;i++)
	p[i]=-1;
 }
 
main(){
	int i; 
	initialize();
	weightedunion(0,1);
	weightedunion(1,2);
	weightedunion(2,3);
	weightedunion(3,4);
	//weightedunion(5,6);
	//weightedunion(0,5);
	for(i=0;i<n;i++)
	printf("%d ",p[i]);
	printf("\nFind4 = %d ",collapsingfind(4));
	//printf("\nFind6 = %d ",collapsingfind(6));
	printf("\n");
	for(i=0;i<n;i++)
	printf("%d ",p[i]);
	getch();
}
