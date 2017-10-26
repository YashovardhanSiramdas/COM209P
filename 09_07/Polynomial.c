/*
Author:- Yashovardhan Siramdas
Roll No:- CED16I028
COM209P
Addition and Multiplication of polynomials using SLL,Lab session 7 (07/09/17)

read() - Function to input degrees of polynomials and calling scan()
scan() - Function to take co efficients as input
addn() - Pre processing to add both polynomials
store_add() - Creating linked list and stores arguments passed by addn()
empty_mul() - Creates empty linked list to store the resultant multiplication and initialises all co efficients with 0
init_mul() - Calls empty_mul() n1+n2+1 times,where n1,n2 are degrees of both polynomials
mult() - Pre processing for multiplication.Passes an argument to store_mult() in each iteration
store_mul()- Stores argument passed by mult() in Linked List

head1,head2,add,mul are head pointers for polynomial 1,polynomial 2,Addition of polynomials & Multiplication of polynomials respectively
*/
#include <stdio.h>
#include <stdlib.h>

struct poly
{
	int coeff;
	struct poly *link;
};

struct poly *head1=NULL,*head2=NULL,*add=NULL,*mul=NULL;
int n1,n2;

void scan1(int i)
{
	struct poly *temp=(struct poly *)malloc(sizeof(struct poly));
	struct poly *t=head1;
	printf("Enter Co efficient of x^%d\n",i);
	scanf("%d",&(temp->coeff));
		if(i==0)
		{
			temp->link=NULL;
			head1=temp;
		}
		else
		{
			while(t->link!=NULL)
			{
				t=t->link;
			}
			t->link=temp;
			temp->link=NULL;
		}


}

void scan2(int i)
{
	struct poly *temp=(struct poly *)malloc(sizeof(struct poly));
	struct poly *t=head2;
	printf("Enter Co efficient of x^%d\n",i);
	scanf("%d",&(temp->coeff));
		if(i==0)
		{
			temp->link=NULL;
			head2=temp;
		}
		else
		{
			while(t->link!=NULL)
			{
				t=t->link;
			}
			t->link=temp;
			temp->link=NULL;
		}


}

void read()
{
	int i;
	printf("Enter degree of Polynomial 1\n");
	scanf("%d",&n1);
	for(i=0;i<=n1;i++)
	{
		scan1(i);	
	}
	printf("Successfully read Polynomial 1\n");

	printf("Enter degree of Polynomial 2\n");
	scanf("%d",&n2);
	for(i=0;i<=n2;i++)
	{
		scan2(i);	
	}
	printf("Successfully read Polynomial 2\n");

}

void store_add(int x)
{
	struct poly *t=add;
	struct poly *temp=(struct poly *)malloc(sizeof(struct poly));
	temp->coeff=x;
	if(add==NULL)
	{
		add=temp;
		temp->link=NULL;
	}
	else
	{
		while(t->link!=NULL)
		{
			t=t->link;
		}
		t->link=temp;
		temp->link=NULL;
	}
}


void addn()
{
	struct poly *t1=head1;
	struct poly *t2=head2;
	int x;
	if(head1==NULL || head2==NULL)
		printf("Atleast one of the polynomials is not read.Cannot add\n");
	else
	{
		if(n1==n2)
		{
			while(t1->link!=NULL)
			{
				x=t1->coeff+t2->coeff;
				store_add(x);
				t1=t1->link;
				t2=t2->link;
			}
			x=t1->coeff+t2->coeff;
			store_add(x);
			printf("Polynomial 1 & Polynomial 2 are successfully added\n");
		}
		else if(n1>n2)
		{
			while(t2->link!=NULL)
			{
				x=t1->coeff+t2->coeff;
				store_add(x);
				t1=t1->link;
				t2=t2->link;
			}
			x=t1->coeff+t2->coeff;
			store_add(x);
			t1=t1->link;
			while(t1->link!=NULL)
			{
				store_add(t1->coeff);
				t1=t1->link;
			}
			store_add(t1->coeff);
			printf("Polynomial 1 & Polynomial 2 are successfully added\n");
		}
		else
		{
			while(t1->link!=NULL)
			{
				x=t2->coeff+t1->coeff;
				store_add(x);
				t1=t1->link;
				t2=t2->link;
			}
			x=t1->coeff+t2->coeff;
			store_add(x);
			t2=t2->link;
			while(t2->link!=NULL)
			{
				store_add(t2->coeff);
				t2=t2->link;
			}
			store_add(t2->coeff);
			printf("Polynomial 1 & Polynomial 2 are successfully added\n");
		}
	}

}

void empty_mul(int i)
{
	struct poly *t=mul;
	struct poly *temp=(struct poly *)malloc(sizeof(struct poly));
	temp->coeff=0;
	if(i==1)
	{
		mul=temp;
		temp->link=NULL;
	}
	else
	{
		while(t->link!=NULL)
		{
			t=t->link;
		}
		t->link=temp;
		temp->link=NULL;
	}
}

void init_mult()
{
	int i;
	for(i=1;i<=(n1+n2)+1;i++)
	{
		empty_mul(i);
	}
}

void store_mul(int x,int p1,int p2)
{
	struct poly *t=mul;
	struct poly *temp=(struct poly *)malloc(sizeof(struct poly));
	int i=1;
	if(p1+p2==0)
	{
		t->coeff=t->coeff+x;
	}
	else
	{
		while(i<p1+p2)
		{
			t=t->link;
			i++;
		}
		(t->link)->coeff=(t->link)->coeff+x;
	}


}

void mult()
{
	struct poly *t1=head1;
	struct poly *t2=head2;
	int x,i=-1,j=-1;
	if(head1==NULL || head2==NULL)
		printf("Atleast one of the polynomials is not read.Cannot add\n");
	else
	{
		init_mult();
		while(t1!=NULL)
		{
			i++;
			while(t2!=NULL)
			{
				j++;
				x=t1->coeff*t2->coeff;
				store_mul(x,i%(n1+1),j%(n2+1));
				t2=t2->link;
			}
			t2=head2;
			t1=t1->link;
		}
		printf("Polynomial 1 & Polynomial 2 are successfully multiplied\n");

	}	
}
void print()
{
	int ch,i=0;
	struct poly *t;
	printf("1.Print 1st Polynomial\n2.Print 2nd Polynomial\n3.Print P1 + P2\n4.Print P1 * P2\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 : t=head1; 
			break;

			case 2 : t=head2;
			break;

			case 3 : t=add;
			break;

			case 4 : t=mul;
			break;

			default : {}
		}
	if(t==NULL)
	{
		printf("Required Polynomial is empty,nothing to display\n");
	}
	else
	{
		printf("Required Polynomial :-\n");
		while(t->link!=NULL)
		{
			printf("%dx^%d+",t->coeff,i);
			i++;
			t=t->link;
		}
		printf("%dx^%d\n",t->coeff,i);
	}

}
int main()
{
	int t;
	while(1)
	{
		printf("1.Read Polynomials\n2.Add two polynomials\n3.Multiply two polynomials\n4.Print\n5.Exit\n");
		scanf("%d",&t);
		switch(t)
		{
			case 1 : read();
			break;

			case 2 : addn();
			break;

			case 3 : mult();
			break;

			case 4 : print();
			break;

			case 5 : return 0;
			break;

			default : {}
		}
	}
	return 0;
}