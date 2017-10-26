/*
Author:- Yashovardhan Siramdas
Roll No:- CED16I028
COM209P
Question 1,Lab session 5 (24/08/17)
Post Fix Evaluation using stack

Constraint:- Operands can range only from 0-9
k is the value that is popped out of stack

*/
#include <stdio.h>

#define asize 10

struct stack
{
	float a[asize];
	int top;

};
float k;

struct stack push(struct stack s,float n)
{
	if(s.top==asize-1)
	printf("Stack is full\n");
	else
	{
		s.top=s.top+1;
		s.a[s.top]=n;
		printf("%f is pushed into stack\n", s.a[s.top]);
	}
	return(s);
}

struct stack pop(struct stack s)
{
	if(s.top==-1)
	printf("Stack is empty\n");
	else
	{
		k=s.a[s.top];
		printf("%f is popped out of stack\n", s.a[s.top]); 
		s.top=s.top-1;
	}
  
return(s);
}

float postfix_eval(struct stack s,int n,char a[n])
{
	int i;
	float x,y,r;
	for(i=0;i<n;i++)
	{
		if((a[i]>=48) && (a[i]<=57))
		{
			s=push(s,a[i]-48);
		}
		else if(a[i]==42 || a[i]==43 || a[i]==45 || a[i]==47)
		{
			s=pop(s);
			x=k;
			s=pop(s);
			y=k;
			if(a[i]==42)
				r=y*x;
			else if(a[i]==43)
				r=y+x;
			else if(a[i]==45)
				r=y-x;
			else
				r=y/x;
			s=push(s,r);		
		}
		else
			printf("Unexpected character encountered\n");
	}
	s=pop(s);
	if(s.top==-1)
		return r;
	else
	{
		printf("Wrong Input of characters in array\n");
		return -111;
	}
}

int main()
{
	struct stack s;
	s.top=-1;
	printf("Enter Number of Characters in the array\n");
	int n,i;
	scanf("%d",&n);
	char a[n];
	printf("Enter %d characters\n",n);
	for(i=0;i<n;i++)
		scanf(" %c",&a[i]);
	printf("Post Fix Evaluation: %f\n",postfix_eval(s,n,a));
	return 0;


}