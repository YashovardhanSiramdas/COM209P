/*
Author:- Yashovardhan Siramdas
Roll No:- CED16I028
COM209P
Lab session 3(10/08/17)
Stack using struct
*/
#include <stdio.h>

struct stack
{
	int a[10];
	int top;

};

struct stack push(struct stack s,int n)
{
	if(s.top==9)
	printf("Stack is full\n");
	else
	{
		s.top=s.top+1;
		s.a[s.top]=n;
		printf("%d is inserted\n", s.a[s.top]);
	}
	return(s);
}

struct stack pop(struct stack s)
{
	if(s.top==-1)
	printf("Stack is empty\n");
	else
	{
		printf("%d is deleted\n", s.a[s.top]); 
		s.top=s.top-1;
	}
  
return(s);
}

int size=10;

int main()
{
	int i,t,b;
	struct stack s;
	s.top=-1;

	do
	{
		printf("Which process is to be executed?\n\n1.Push\n2.Pop\n3.End Process\n\n");
		scanf("%d",&t);
		if(t==1)
		{
			printf("Enter the number to be inserted\n");
			scanf("%d",&b);
			s=push(s,b);
			printf("Numbers present in stack are:-\n");
			for(i=0;i<=s.top;i++)
				printf("%d\n",s.a[i]);

		}
		if(t==2)
		{
			s=pop(s);
			if(s.top==-1)
				printf("Stack is empty\n");
			else
			{
				printf("Numbers present in stack are:-\n");
				for(i=0;i<=s.top;i++)
					printf("%d\n",s.a[i]);
			}
		}	

		if(t==3)
		{
			return 0;
		}
	}
	while(t==1 || t==2);
	return(0);
}
