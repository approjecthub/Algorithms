#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

int * computeLPS(char pat[],int m){
	int *pi = (int *)malloc(m * sizeof(int)),len=0,i=1;
	pi[0] = 0; 
    while (i < m) { 
        if (pat[i] == pat[len]) { 
            len++; 
            pi[i] = len; 
            i++; 
        } 
        else 
        { 
            if (len != 0) { 
                len = pi[len - 1];
            } 
            else
            { 
                pi[i] = 0; 
                i++; 
            } 
        } 
    }
	return pi;
}

int kmp_search(int *pi,char pat[],char txt[],int m,int n){
	int i=0,j=0,c=0;
	while(i<n){ 
		if(j==m){
		c++;
		j = pi[j-1];	
		}
		if(txt[i]==pat[j]){
			i++;
			j++;
		} 
		if(j==m){
		c++;
		j = pi[j-1];	
		}
        if (i < n && pat[j] != txt[i]) { 
            if (j != 0) 
                j = pi[j - 1]; 
            else
                i++; 
        }
		
	}
	return c;
}

main(){
	char txt[] = "ABABDABACDABABCABAB";
    char pat[] = "ABABCABAB";
    //char txt[]="ABABA";
    //char pat[] = "ABA";
    int c=0;
	//char pat[] = "AABCADAABC";
	int *pi = computeLPS( pat, strlen(pat)),i;
	for(i=0;i<strlen(pat);i++)
	printf("%d ",pi[i]);
	c = kmp_search(pi,pat,txt,strlen(pat),strlen(txt));
	printf("\nNo. of occurance of the substring = %d\n",c);
	getch();
}
