/*
Author:- Yashovardhan Siramdas
Roll No:- CED16I028
COM209P
Lab session 2(03/08/17)
Celebrity problem using time complexity in between O(N) & O(N^2).Input from is x y,where x knows y. Number of persons and number of relations must ge given as input
*/
#include <stdio.h>

void celebrity(int n,int p,int a[n][2],int c[p])
{
	int i,j;
	for(i=0;i<n;i++)
		c[a[i][0]-1]=0;

	int sub[p+1];
	for(i=0;i<=p;i++)
		sub[i]=0;

	for(i=0;i<n;i++)
	{
		sub[a[i][1]]++;
	}

	for(i=0;i<p;i++)
	{
		if(sub[i+1]!=p-1)
			c[i]=0;
	}	

}

int main()
{
	int n,p;
	printf("Enter No. of persons\n");
	scanf("%d",&p);
	printf("Enter No. of relations\n");
	scanf("%d",&n);
	int a[n][2],i,j,c[p];
	printf("Enter %d relations\n",n);
	for(i=0;i<n;i++)
		for(j=0;j<2;j++)
			scanf("%d",&a[i][j]);
	for(i=0;i<p;i++)
		c[i]=1;
	celebrity(n,p,a,c);
	for(i=0;i<p;i++)
		if(c[i]==1)
		{
			printf("Person %d is celebrity\n",i+1);
			return 0;
		}
	printf("No Celebrity exists\n");
	

	return(0);
}