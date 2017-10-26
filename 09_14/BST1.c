/*
Author:- Yashovardhan Siramdas
Roll No:- CED16I028

COM209P
Lab Session 8
14/09/2017

Contains following functions:-
(i)insert-Inserting a new node
(ii) pre order-prints the tree in pre order traversing
(iii) in order-prints the tree in  inorder traversing
(iv) post order-prints the tree in postorder traversing
(v) search-checks if the element is present in BST
(vi) count- counts total number of nodes in BST
(vii) height- calculates height of BST
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
int c=0;

struct node *insert(struct node *root,int x)
{
	if(root==NULL)
	{
		struct node *temp=(struct node *)malloc(sizeof(struct node));
		temp->data=x;
		temp->lcptr=temp->rcptr=NULL;
		root=temp;
	}
	else
	{
		if(x<root->data)
			root->lcptr=insert(root->lcptr,x);
		else
			root->rcptr=insert(root->rcptr,x);
	}
	return root;
}

void preorder(struct node *root)
{
	if(root!=NULL)
	{
		printf("%d ", root->data);
     	preorder(root->lcptr);
     	preorder(root->rcptr);
	}
}

void inorder(struct node *root)
{
	if(root!=NULL)
	{
     	inorder(root->lcptr);
     	printf("%d ", root->data);
     	inorder(root->rcptr);
	}
}

void postorder(struct node *root)
{
	if(root!=NULL)
	{
     	postorder(root->lcptr);
     	postorder(root->rcptr);
     	printf("%d ", root->data);
	}
}

void search()
{
	int x,f=0;
	printf("Enter integer to be searched\n");
	scanf("%d",&x);
	struct node *t=root;
	while(t!=NULL)
	{
		if(x==t->data)
		{
			f=1;
			break;
		}
		else
		{
			if(x<t->data)
				t=t->lcptr;
			else
				t=t->rcptr;
		}
		
	}
	if(f==1)
		printf("%d is found in BST\n",x);
	else
		printf("%d is not found in BST\n",x);	
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

int height(struct node *root)
{
	if(root==NULL)
		return -1;
	else
	{
		int left_height=height(root->lcptr);
		int right_height=height(root->rcptr);

		if(left_height>right_height)
			return left_height+1;
		else
			return right_height+1;
	}
}

int main()
{
	int t;
	while(1)	
	{
		printf("1.Insert\n2.Pre Order\n3.In order\n4.Post Order\n5.Search\n6.Count\n7.Height\n8.Exit\n");
		scanf("%d",&t);
		switch(t)
		{
			case 1 :
			 {
				int x;
				printf("Enter integer to be inserted\n");
				scanf("%d",&x);
				root=insert(root,x);
				printf("%d is successfully inserted\n",x);
			}	
				break;

			case 2 :
			{
			 	printf("Pre Order:-\n");
			 	preorder(root);
			 	printf("\n");
			}
				break;

			case 3 : 
			{
				printf("In Order:-\n");
				inorder(root);
				printf("\n");
			}
				break;

			case 4 :
			{
				printf("Post Order:-\n");
				postorder(root);
				printf("\n");
			}
				break;

			case 5 : 
				search();
				break;

			case 6 : 
			{
				c=0;
				count(root);
				printf("Number of Nodes present in BST are %d\n",c);
			}
				break;

			case 7 : 
				printf("Height of the BST is %d\n",height(root));
				break;	

			case 8 :
				 return 0;
			

			default : {}

			

			
		}
	}
}
