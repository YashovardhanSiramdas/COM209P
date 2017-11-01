/*

Author:- Yashovardhan Siramdas
Roll No:- CED16I028
COM209P
Lab session 13 (02/11/17)

Priority Queue(Max Heap)

heapInsert(key):- Inserts key as per essential Binary Tree properties and performs perculation from Inserted key to root if required(Bottom-Up)
delMin():- Deletes root from Heap and performs perculation from root to last level if required(Top-Down)

*/
#include <stdio.h>

#define asize 100

struct heap
{
	int a[asize];
	int hsize ;
}H;

void swap(int *a,int *b)
{
	int temp=*b;
	*b=*a;
	*a=temp;
}

int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}

void QueueInsert(int key)
{
	H.hsize++;
	H.a[H.hsize]=key;
	int i=H.hsize;
	while(i>1 && H.a[i]>H.a[i/2])
	{
		swap(&H.a[i],&H.a[i/2]);
		i=i/2;
	}
	printf("%d is successfully inserted in Queue\n",key);
}

void displayQueue()
{
	int i;
	printf("Priorities in the Queue:-\n");
	for(i=1;i<=H.hsize;i++)
		printf("%d ",H.a[i]);
	printf("\n");
}

void delMax()
{
	if(H.hsize==0)
	{
		printf("Queue is empty,delMax can't be performed\n");
		return ;
	}

	int x=H.a[1];
	H.a[1]=H.a[H.hsize];
	H.hsize--;
	int i=1;
	while((2*i)<=H.hsize)
	{
		if((2*i)+1<=H.hsize && H.a[i]<max(H.a[2*i],H.a[(2*i)+1]))
		{
			if(H.a[(2*i)+1]>H.a[2*i])
			{
				swap(&H.a[i],&H.a[(2*i)+1]);
				i=(2*i)+1;
			}
			else
			{
				swap(&H.a[i],&H.a[(2*i)]);
				i=(2*i);	
			}

		}
		else if((2*i)+1>H.hsize && H.a[i]<H.a[2*i])
		{
			swap(&H.a[i],&H.a[(2*i)]);
			break;
		}
		else
			break;
	}
	printf("%d is dequeued\n",x);

}

int main()
{
	int t;
	H.hsize=0;
	while(1)
	{
		printf("1.Insert Priority\n2.Delete Max Priority\n3.Display Queue\n4.Exit\n");
		scanf("%d",&t);
		switch(t)
		{
			case 1 :
			{
				int key;
				printf("Enter Priority to be inserted\n");
				scanf("%d",&key);
				QueueInsert(key);
			}
			break;

			case 2 :
			{
				delMax();	
			}
			break;

			case 3 :
			{
				displayQueue();	
			}
			break;

			case 4 :
			{
				return 0;
			}
		}
	}
}