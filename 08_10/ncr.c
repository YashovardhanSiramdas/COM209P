/*
Author:- Yashovardhan Siramdas
Roll No:- CED16I028
COM209P
Lab session 3(10/08/17)
nCr using Dynamic Programming
*/
#include <stdio.h>

int main()
{
	long long int a[101][101];
	int i,j;
	for(i=1;i<101;i++)
	{
		for(j=0;j<101;j++)
		{
			if(j>i)
				break;
			if(j==0 || j==i)
				a[i][j]=1;
			else
				a[i][j]=a[i-1][j-1]+a[i-1][j];

		}
	}
	while(1)
	{
		int t;
		printf("1.Enter Input\n2.Exit\n");
		scanf("%d",&t);
		if(t==2)
			return 0;
		int n,c;
		printf("Enter n\n");
		scanf("%d",&n);
		printf("Enter c\n");
		scanf("%d",&c);
		printf("nCr : %lli\n",a[n][c]);
	}	
	return 0;
}