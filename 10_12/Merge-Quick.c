/*
Author:- Yashovardhan Siramdas
Roll No:- CED16I028
COM209P
Lab session 11 (12/10/17)
Average number of comparisions for Merge Sort and Quick Sort.
Generates 1000 random arrays with each of size 100 and computes average number of comparisons.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cnt_merge=0,cnt_quick=0;

void merge(int a[],int beg,int end)
{
	int mid=(beg+end)/2,i=beg,j=mid+1,k=0;
	int b[100];
	while(i<=mid && j<=end)
	{
		cnt_merge++;
		if(a[i]<a[j])
		{
			b[k]=a[i];
			i++;
			k++;
		}
		else
		{
			b[k]=a[j];
			j++;
			k++;
		}
	}

	while(i<=mid)
	{
		b[k]=a[i];
		k++;
		i++;
	}

	while(j<=end)
	{
		b[k]=a[j];
		k++;
		j++;
	}

	for(i=beg;i<=end;i++)
		a[i]=b[i-beg];
}

void mergeSort(int a[],int beg,int end)
{
	int mid=(beg+end)/2;
	cnt_merge++;
	if(beg<end)
	{
		mergeSort(a,beg,mid);
		mergeSort(a,mid+1,end);
		merge(a,beg,end);
	}
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int a[], int low, int high)
{
    int pivot = a[high];  
    int i = (low - 1); 
 	

    for (int j = low; j <= high- 1; j++)
    {
        cnt_quick++;
        if (a[j] <= pivot)
        {
            i++;  
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[high]);
    return (i + 1);
}
 
void quickSort(int a[], int low, int high)
{
    cnt_quick++;
    if (low < high)
    {
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}


int main()
{
	int i;
	int total_merge=0,total_quick=0;
	for(i=0;i<1000;i++)
	{
		int a[100],j;
		srand(time(NULL));
		for(j=0;j<100;j++)
			a[j]=rand()%1001;
		int c[100];
		for(j=0;j<100;j++)
			c[j]=a[j];
		cnt_merge=0;
		cnt_quick=0;
		mergeSort(a,0,99);
		quickSort(c,0,99);
		total_merge=cnt_merge+total_merge;
		total_quick=cnt_quick+total_quick;
	}
	printf("Average Number of comparisons made by Merge Sort=%d\n",total_merge/1000);
	printf("Average Number of comparisons made by Quick Sort=%d\n",total_quick/1000);
	

}