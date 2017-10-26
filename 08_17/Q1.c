/*
Author:- Yashovardhan Siramdas
Roll No:- CED16I028
COM209P
Question 1,Lab session 4 (17/08/17)
Queue using array,including the functions enqueue and dequeue
*/
#include <stdio.h>

int size=5;

struct queue
{
	int a[size];
	int front;
	int rear;

};

struct queue enqueue(struct queue q,int n)
{
	if(q.rear==size-1)
	printf("Queue is full and hence %d cannot be enqueued\n",n);
	else
	{
		if(q.front==-1)
		q.front=0;
		q.rear=q.rear+1;
		q.a[q.rear]=n;
		printf("%d is enqueued\n",q.a[q.rear]);
	}

	return(q);
}

struct queue dequeue(struct queue q)
{
	int x;
	if(q.front==-1)
	printf("Queue is empty\n");
	else
	{
		x=q.a[q.front];
		if(q.front==q.rear)
		{
			q.front=-1;
			q.rear=-1;
		} 
		else
			q.front=q.front+1;
		printf("%d is dequeued\n",x);
	}
	return(q);

}

void display(struct queue q)
{
	int i;
	printf("Integers present in queue are:-\n");
	for(i=q.front;i<=q.rear;i++)
		printf("%d\n",q.a[i]);
	
}

int main()
{
	struct queue q;
	int t;
	q.front=q.rear=-1;
	do
	{
		printf("1.Enqueue\n2.Dequeue\n3.Display present queue\n4.End Process\n");
		scanf("%d",&t);
		if(t==1)
		{
			printf("Enter the integer you want to enqueue\n");
			int n;
			scanf("%d",&n);
			q=enqueue(q,n);

		}
		if(t==2)
		q=dequeue(q);
		if(t==3)
		display(q);
	}
	while(t!=4);
	return(0);
}
