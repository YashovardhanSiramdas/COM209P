/*
Author:- Yashovardhan Siramdas
Roll No:- CED16I028

COM209P
21/09/17,Lab session 9

Contains following functions:-

(i) insert-Inserts a new node
(ii) delete- Deletes a node in BST
(iii) sort- sorts the BST in ascending order and stores in an array
*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
	struct node *lcptr;
	int data;
	struct node *rcptr;
};

struct node *root=NULL;
int c=0,i=0,f=0;

void insert()
{
	int x;
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	printf("Enter integer to be inserted\n");
	scanf("%d",&x);
	temp->data=x;
	temp->lcptr=temp->rcptr=NULL;
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		struct node *t=root;
		struct node *pt=NULL;
		while(t!=NULL)
		{
			pt=t;
			if(x<t->data)
				t=t->lcptr;
			else
				t=t->rcptr;
		}
		if(x<pt->data)
			pt->lcptr=temp;
		else
			pt->rcptr=temp;
	}
	printf("%d is successfully inserted in BST\n",x);
}

struct node *leastNode(struct node* root)
{
    struct node *temp = root;
 
    while (temp->lcptr != NULL)
        temp = temp->lcptr;
 
    return temp;
}

struct node *delete(struct node *root, int x)
{
    if (root == NULL) 
    	return root;

    if (x < root->data)
        root->lcptr = delete(root->lcptr, x);
 
    else if (x > root->data)
        root->rcptr = delete(root->rcptr, x);

    else
    {
        // node with 0 or 1 child
        if (root->lcptr == NULL)
        {
            struct node *temp = root->rcptr;
            free(root);
            f=1;
            return temp;
        }
        else if (root->rcptr == NULL)
        {
            struct node *temp = root->lcptr;
            free(root);
            f=1;
            return temp;
        }
 
        // node with 2 children
        struct node *temp = leastNode(root->rcptr); //gets inorder successor
        root->data = temp->data; //inorder successor's data is copied to the node whose data is to be deleted
        root->rcptr = delete(root->rcptr, temp->data); //deleting inorder successor's node
    }
    return root;
}

void count(struct node *root)
{
	if(root!=NULL)
	{
		count(root->lcptr);
		count(root->rcptr);
		c++;
	}
}

void sort(struct node *root,int c,int a[c])
{
	if(root!=NULL)
	{
     	sort(root->lcptr,c,a);
     	a[i]=root->data;
     	i++;
     	sort(root->rcptr,c,a);
	}
}

int main()
{
	int t;
	while(1)	
	{
		printf("1.Insert\n2.Delete\n3.Sort\n4.Exit\n");
		scanf("%d",&t);
		switch(t)
		{
			case 1 : 
				insert();
				break;

			case 2 :
			 {
				int x;
				printf("Enter integer to be deleted\n");
				scanf("%d",&x);
				f=0;
				root=delete(root,x);
				if(f==1)
					printf("%d is successfully deleted from BST\n",x);
				else
					printf("%d is not present in BST\n",x);
				break;
			}

			case 3 :
			 {
				i=c=0;
				count(root);
				int a[c];
				sort(root,c,a);
				printf("Elements in sorted order:-\n");
				for(i=0;i<c;i++)
					printf("%d ",a[i]);
				printf("\n");
				break;
			 }

			case 4 :
				 return 0;

			default : {}
		}
	}
}
