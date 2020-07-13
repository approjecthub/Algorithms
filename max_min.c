#include<stdio.h>
#include<conio.h>
int max,min;
int a[10];

void maxmin(int i,int j){
	int mid,max1,min1;
	if(i==j)
	max = min = a[i];
	else if(i==j-1){
		if(a[i]<a[j]){
			max = a[j];
			min = a[i];
		}
		else{
			max = a[i];
			min = a[j];
		}
	}
	else{
		mid = (i+j)/2 ;
		maxmin(i,mid);
		max1 = max;
		min1 = min;
		maxmin(mid+1,j);
		if(max<max1)
		max = max1;
		if(min>min1)
		min = min1;
	}
}

main(){
	int i,n;
	printf("Enter the no. of elements\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
	maxmin(1,n);
	printf("maximum = %d\nminimum = %d\n",max,min);
	getch();
}
