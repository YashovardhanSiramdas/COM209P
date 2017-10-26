/*BUG IN THE CODE.DOESN'T WORK FOR ALL INPUTS*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *link;
};

struct node *hptr=NULL;

int counter=0;

void insert()
{
	int n;
	printf("Enter the integer to be inserted\n");
	scanf("%d",&n);
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	struct node *t=hptr;
	temp->data=n;
	if(hptr==NULL)
	{
		hptr=temp;
		temp->link=hptr;
		counter++;
	}
	else
	{
		while(t->link!=hptr)
		{
			t=t->link;
		}
		t->link=temp;
		temp->link=hptr;
		counter++;
	}
	printf("%d is successfully inserted at the end of the list\n",n);
	printf("counter %d\n",counter);

}

void insert_pos()
{
	int n,p;
	printf("Enter the integer to be inserted\n");
	scanf("%d",&n);
	printf("Enter the position\n");
	scanf("%d",&p);
	if(p<1 || p>counter+1)
	{
		printf("Entered position is not in range,Insertion is not possible\n");
	}
	else
	{
		struct node *temp=(struct node *)malloc(sizeof(struct node));
		struct node *t=hptr;
		struct node *x;
		int i=1;
		temp->data=n;
		if(p==1)
		{
			if(hptr==NULL)
			{
				hptr=temp;
				temp->link=hptr;
				counter++;
			}
			else
			{
				temp->link=hptr;
				while(t->link!=hptr)
				{
					t=t->link;
				}
				t->link=temp;
				hptr=temp;
				counter++;
			}
		}
		else if(p>1 && p<counter+1)
		{
			while(i<p-1)
			{
				t=t->link;
				i++;
			}
			x=t->link;
			t->link=temp;
			temp->link=x;
			counter++;
		}
		else
		{
			printf("hello\n");
			while(i<p)
			{
				t=t->link;
				i++;
			}
			t->link=temp;
			temp->link=hptr;
			counter++;
		}
		printf("%d is successfully inserted at position %d\n",n,p);
		printf("counter %d\n",counter);
	}

}

void delete()
{
	int x;
	struct node *t=hptr;
	if(hptr==NULL)
	{
		printf("List is empty,element cannot be deleted\n");
	}
	else if(t->link==hptr)
	{
		x=t->data;
		hptr=NULL;
		counter--;
		printf("%d is successfully deleted from the end of the list\n",x);	
	}
	else
	{
		while((t->link)->link!=hptr)
		{
			t=t->link;
		}
		x=(t->link)->data;
		t->link=hptr;
		counter--;
		printf("%d is successfully deleted from the end of the list\n",x);
	}
	
	

}

void display()
{
	struct node *t=hptr;
	
	if(hptr==NULL)
	{
		printf("List is empty,no elements to display\n");
	}
	else if(t->link==hptr)
	{
		printf("%d\n",t->data);
	}
	else
	{
		while(t->link!=hptr)
		{
			printf("%d\n",t->data);
			t=t->link;
		}
		printf("%d\n",t->data);
	}
}
int main()
{
	int t;
	while(1)
	{
		printf("1.Insert\n2.Insert at position\n3.Delete\n4.Search\n5.Display\n6.Exit\n");
		scanf("%d",&t);
		switch(t)
		{
			case 1 : insert();
			break;

			case 2 : insert_pos();
			break;

			case 3 : delete();
			break;

			case 5 : display();
			break;

			case 6 : return 0;
			break;

			default : {}


		}
	}

	return 0;
}