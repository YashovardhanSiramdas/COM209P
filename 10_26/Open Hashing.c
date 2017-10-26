/*
Author:- Yashovardhan Siramdas
Roll No:- CED16I028
COM209P
Lab session 12 (26/10/17)

Open Hashing

Hash Function:- If last digit of Roll Number =0,then h(k)=9
				else h(k)=last digit-1

Each node contains key,name,marks

Key is the last two digits of Roll Number(Type casting of last two digits is done)

Dynamic Input

Input Roll No in the format CED16I0 _ _		
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	int key;
	char name[30];
	int marks;
	struct node *link;
};

struct node *head[10];

void insert()
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	char roll[10];
	printf("Enter Roll Number\n");
	scanf("%s",roll);
	int kod=roll[8]-'0',ktd=roll[7]-'0';
	temp->key=(ktd*10)+kod;
	printf("Enter Name\n");
	scanf("%s",temp->name);
	printf("Enter Marks\n");
	scanf("%d",&temp->marks);
	int arr_index;
	if(kod==0)
		arr_index=9;
	else
		arr_index=kod-1;

	temp->link=NULL;

	if(head[arr_index]==NULL)
	{
		head[arr_index]=temp;
	}
	else
	{
		struct node *t=head[arr_index];
		while(t->link!=NULL)
		{
			t=t->link;
		}
		t->link=temp;
	}
	printf("Record is successfully inserted at array index %d and with key %d\n",arr_index,temp->key);

}

void delete()
{
	char roll[10];
	printf("Enter Roll Number of the record to be deleted\n");
	scanf("%s",roll);
	int kod=roll[8]-'0',ktd=roll[7]-'0';
	int arr_index;
	if(kod==0)
		arr_index=9;
	else
		arr_index=kod-1;

	struct node *t=head[arr_index];
	int key=(ktd*10)+kod;

	if(t==NULL)
	{
		printf("Entered Roll Number not found\n");
		return;
	}

	if(t->key==key)
	{
		head[arr_index]=t->link;
		printf("Record with the Roll Number %s is deleted\n",roll);
		return;
	}
	t=t->link;

	struct node *prev=head[arr_index];

	while(t!=NULL)
	{
		if(key==t->key)
		{
			prev->link=t->link;
			printf("Record with the Roll Number %s is deleted\n",roll);
			return;
		}

		prev=t;
		t=t->link;
	}
	printf("Entered Roll Number not found\n");
}

void search()
{
	char roll[10];
	printf("Enter Roll Number to be searched for\n");
	scanf("%s",roll);
	int kod=roll[8]-'0',ktd=roll[7]-'0';
	int arr_index;
	if(kod==0)
		arr_index=9;
	else
		arr_index=kod-1;

	struct node *t=head[arr_index];
	int key=(ktd*10)+kod;

	while(t!=NULL)
	{
		if(key==t->key)
		{
			if(t->key<10)
				printf("Roll No: CED16I00%d, Name: %s, Marks: %d\n",t->key,t->name,t->marks);
			else
				printf("Roll No: CED16I0%d, Name: %s, Marks: %d\n",t->key,t->name,t->marks);

			return;
		}

		t=t->link;
	}
	printf("Entered Roll Number not found\n");
}

void display()
{
	struct node *t;
	int i;
	for(i=0;i<10;i++)
	{
		t=head[i];
		if(t==NULL)
			continue;
		else
		{
			while(t!=NULL)
			{
				if(t->key<10)
					printf("Roll No: CED16I00%d, Name: %s, Marks: %d\n",t->key,t->name,t->marks);
				else
					printf("Roll No: CED16I0%d, Name: %s, Marks: %d\n",t->key,t->name,t->marks);	
				t=t->link;
			}
		}
	}
}

int main()
{
	int i,t;
	for(i=0;i<10;i++)
		head[i]=NULL;
	while(1)
	{
		printf("1.Insert\n2.Delete\n3.Search\n4.Display all Records\n5.Exit\n");
		scanf("%d",&t);
		switch(t)
		{
			case 1 :
			{
				insert();
			}
			break;

			case 2 :
			{
				delete();
			}
			break;

			case 3 :
			{
				search();
			}
			break;

			case 4 :
			{
				display();
			}
			break;

			case 5 :
			{
				return 0;
			}
			break;

			default : {}
		}
	}
}