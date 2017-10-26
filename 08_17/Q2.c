/*
Author:- Yashovardhan Siramdas
Roll No:- CED16I028
COM209P
Question 2,Lab session 4 (17/08/17)

Queue simulation in Airport.Three different queues for:-
(i) Business Class
(ii) Ladies,Children,Physically Challenged class
(iii) Economy class

Dequeue will happen according to priority
*/
#include <stdio.h>

int size=10;

struct queue
{
	int a[10];
	int front;
	int rear;

};

struct queue q1,q2,q3;

struct queue enqueue(struct queue q,int n)
{
	if(q.rear==size-1)
	printf("Queue is full and hence %d cannot be enqueued in this class\n",n);
	else
	{
		if(q.front==-1)
		q.front=0;
		q.rear=q.rear+1;
		q.a[q.rear]=n;
	}
	return q;
}

struct queue dequeue(struct queue q1,struct queue q2,struct queue q3)
{
	int x;
	if(q1.front>=0)
	{
		x=q1.a[q1.front];
		if(q1.front==q1.rear)
		{
			q1.front=-1;
			q1.rear=-1;
		} 
		else
			q1.front=q1.front+1;
		printf("%d is dequeued from Business Class\n",x);
		return q1;
	}
	else if(q2.front>=0)
	{
		x=q2.a[q2.front];
		if(q2.front==q2.rear)
		{
			q2.front=-1;
			q2.rear=-1;
		} 
		else
			q2.front=q2.front+1;
		printf("%d is dequeued from Ladies,Children,Physically Challenged class\n",x);
		return q2;	
	}
	else if(q3.front>=0)
	{
		x=q3.a[q3.front];
		if(q3.front==q3.rear)
		{
			q3.front=-1;
			q3.rear=-1;
		} 
		else
			q3.front=q3.front+1;
		printf("%d is dequeued from Economy Class\n",x);
		return q3;
	}
	else
		printf("All queues are empty\n");
	return q1;
}

void display(struct queue q1,struct queue q2,struct queue q3)
{
	int i;
	if(q1.front>=0)
	{
		printf("Integers present in Business Class are:-\n");
		for(i=q1.front;i<=q1.rear;i++)
			printf("%d\n",q1.a[i]);
	}
	else
		printf("No integers are present in Business Class\n");
	if(q2.front>=0)
	{
		printf("Integers present in Ladies,Children,Physically Challenged class are:-\n");
		for(i=q2.front;i<=q2.rear;i++)
			printf("%d\n",q2.a[i]);
	}
	else
		printf("No integers are present in Ladies,Children,Physically Challenged Class\n");
	if(q3.front>=0)
	{
		printf("Integers present in Economy Class are:-\n");
		for(i=q3.front;i<=q3.rear;i++)
			printf("%d\n",q3.a[i]);
	}
	else
		printf("No integers are present in Economy Class\n");
	
	
}

int main()
{
	int t,n;
	q1.front=q1.rear=-1;
	q2.front=q2.rear=-1;
	q3.front=q3.rear=-1;
	do
	{
		printf("1.Enqueue in Business Class\n2.Enqueue in Ladies,Children,Physically Challenged class\n3.Enqueue in Economy class\n4.Dequeue\n5.Display all present queues\n6.End Process\n");
		scanf("%d",&t);
		if(t==1)
		{
			printf("Enter integer to be enqueued in Business Class\n");
			scanf("%d",&n);
			q1=enqueue(q1,n);
			printf("%d is enqueued in Business Class\n",q1.a[q1.rear]);
		}
		if(t==2)
		{
			printf("Enter integer to be enqueued in Ladies,Children,Physically Challenged class\n");
			scanf("%d",&n);
			q2=enqueue(q2,n);
			printf("%d is enqueued in Ladies,Children,Physically Challenged class\n",q2.a[q2.rear]);
		}
		if(t==3)
		{
			printf("Enter integer to be enqueued in Economy Class\n");
			scanf("%d",&n);
			q3=enqueue(q3,n);
			printf("%d is enqueued in Economy Class\n",q3.a[q3.rear]);
		}
		if(t==4)
		{
			if(q1.front>=0)
				q1=dequeue(q1,q2,q3);
			else if(q2.front>=0)
				q2=dequeue(q1,q2,q3);
			else if(q3.front>=0)
				q3=dequeue(q1,q2,q3);
			else
				q1=dequeue(q1,q2,q3);
		}
		if(t==5)
		display(q1,q2,q3);
	}
	while(t!=6);
	return(0);
}
