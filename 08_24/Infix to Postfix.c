/*
Author:- Yashovardhan Siramdas
Roll No:- CED16I028
COM209P
Question 2,Lab session 5 (24/08/17)
Infix to Postfix conversion

Input Format:- Infix expression.A character array consisting of a-z and operators

precedence function sets preference to the operations +,-,*,/

*/
#include <stdio.h>

#define asize 10

struct stack
{
	char a[asize];
	int top;

};

struct stack push(struct stack s,char n)
{
	if(s.top==asize-1)
	printf("Stack is full\n");
	else
	{
		s.top=s.top+1;
		s.a[s.top]=n;
	}
	return(s);
}

struct stack pop(struct stack s)
{
	if(s.top==-1)
	printf("Stack is empty\n");
	else
	{
		s.top=s.top-1;
	}
  
return(s);
}

int precedence(char x)
{
	if(x==42 || x==47)
		return 2;
	else if(x==43 || x==45)
		return 1;
	else
		return 0;
}
void infixtopostfix(struct stack s,int n,char a[n])
{
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]>=97 && a[i]<=122)
			printf("%c ",a[i]);
		else if(a[i]==40)
			s=push(s,a[i]);
		else if(a[i]==41)
		{
			while(s.a[s.top]!=40)
			{
				printf("%c ",s.a[s.top]);
				s=pop(s);
			}
			s=pop(s);
		}
		else if(a[i]==42 || a[i]==43 || a[i]==45 || a[i]==47)
		{
			while(precedence(s.a[s.top])>=precedence(a[i]))
			{
				printf("%c ",s.a[s.top]);
				s=pop(s);
			}

			s=push(s,a[i]);	
		}
	}
	while(s.top!=-1)
	{
		printf("%c ",s.a[s.top]);
		s=pop(s);
	}
	printf("\n");
}

int main()
{
	struct stack s;
	s.top=-1;
	printf("Enter number of characters\n");
	int n,i;
	scanf("%d",&n);
	char a[n];
	printf("Enter %d characters\n",n);
	for(i=0;i<n;i++)
		scanf(" %c",&a[i]);
	infixtopostfix(s,n,a);

}