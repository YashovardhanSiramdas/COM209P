/*
Author:- Yashovardhan Siramdas
Roll No:- CED16I028
COM209P
Lab session 2(03/08/17)
Celebrity problem using one nested for loop.Input is a 2d array.Time Complexity is O(N^2)
*/
#include <stdio.h>

void celebrity(int n,int a[n][n],int c[n])
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			if(a[i][j]==1 && i!=j)
				c[i]=0;
			if(a[i][j]==0)
				c[j]=0;
			
		}

}

int main()
{
	printf("Enter No. of persons\n");
	int n;
	scanf("%d",&n);
	int a[n][n],i,j,c[n];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	for(i=0;i<n;i++)
		c[i]=1;
	celebrity(n,a,c);
	for(i=0;i<n;i++)
		if(c[i]==1)
		{
			printf("Person %d is celebrity\n",i+1);
			return 0;
		}
	printf("No Celebrity exists\n");
	

	return(0);
}
