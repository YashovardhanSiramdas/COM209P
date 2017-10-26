/*
Author:- Yashovardhan Siramdas
Roll No:- CED16I028
COM209P
Lab session 1(27/07/17)
Average number of comparisions for Linear and Binary search.Generates arrays with random values and will search for a random generated key
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int LS(int a[],int n,int key)   //Linear Search
{
	int c=0,i;
	for(i=0;i<n;i++)
	{
		c++;
		if(a[i]==key)
			break;
	}
	
	return c;
}

int BS(int a[],int n,int key)  //Binary Search
{
	int c=0,i;
	int b=0,e=n-1,m;
	while(b<=e)
	{
		m=(b+e)/2;
		c++;
		if(key==a[m])
		{
			break;		
		}	
		else if(key<a[m])
		{
			e=m-1;
		}
		else
		{
			b=m+1;
		}
	}
	
	return c;
}
int main()
{

	int n;
	int i,lsc=0,bsc=0,c,c1,j=0,k;
	int z[4];
	z[0]=10;
	z[1]=100;
	z[2]=1000;
	z[3]=10000;
	srand(time(NULL));
	for(k=0;k<4;k++)
	{
	n=z[k];	
	int a[n];
	for(j=0;j<1000;j++)  // Iterating 1000 times
	{
		int prev=0;
		for(i=0;i<n;i++)
		{
			a[i]=prev+(rand()%101);  //Storing random sorted values in arrays
			prev=a[i];
		}
		int key=a[rand()%n]; //Generating Key
		c=LS(a,n,key);    //Invoking search functions
		c1=BS(a,n,key);
		lsc=lsc+c;
		bsc=bsc+c1;
		

	}

	printf("Array Size:-%d\n",n);
	printf("Average number of comparisions for Linear Search:-%d\n",lsc/1000); //Printing avg comparisions
	printf("Average number of comparisions for Binary Search:-%d\n",bsc/1000);
	}
}
