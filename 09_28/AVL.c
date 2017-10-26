/*
Author:- Yashovardhan Siramdas
Roll No:- CED16I028

COM209P
28/09/17,Lab session 10

AVL Tree insertion & deletion

Contains following functions:-

(i) HT-returns height of a given node
(ii) HeightUpdate- updates height of a given node
(iii) RotateRight- Performs right rotation
(iv) RotateLeft- Performs left rotation
(v) RotateLeftRight-Performs left rotation and then right rotation
(vi) RotateRightLeft-Performs right rotation and then left rotation
(vii) BalanceFactor-returns Balance Factor for given node
(viii) leastNode- returns the address of inorder successor of ptr if ptr->rcptr is passed as argument
(ix)inorder-prints inorder sequence
(x) postorder-prints postorder sequence
(xi) insert-inserts the given integer in tree and balances the tree if it is disturbed after insertion
(xii) delete- deletes the given integer from tree and balances the tree if it is disturbed after deletion
*/

#include<stdio.h>
#include<stdlib.h>

int f=0;

struct node
{
	struct node *lcptr;
	int data;
	int height;
	struct node *rcptr;
};

struct node *rptr=NULL;

int HT(struct node *ptr) 
{
	if(ptr!=NULL)
		return(ptr->height);
	else
		return(-1);
}

void HeightUpdate(struct node* ptr) 
{

	int h1=HT(ptr->lcptr),h2=HT(ptr->rcptr);
	
	if(h1<h2) 
	{
		ptr->height=h2+1;
		
	}

	else
	{
		ptr->height=h1+1;
	}
}


struct node *RotateRight(struct node *ptr)
{

	struct node *jptr=ptr;
	struct node * kptr=jptr->lcptr;
	
	jptr->lcptr=kptr->rcptr;
	kptr->rcptr=jptr;
	HeightUpdate(jptr);
	HeightUpdate(kptr);
	return(kptr);
}

struct node *RotateLeft(struct node *ptr)
{

	struct node *jptr=ptr;
	struct node * kptr=jptr->rcptr;
	
	jptr->rcptr=kptr->lcptr;
	kptr->lcptr=jptr;

	HeightUpdate(jptr);
	HeightUpdate(kptr);
	return(kptr);
	
}

struct node *RotateLeftRight(struct node *ptr)
{

	struct node *jptr=ptr;
	struct node *kptr=jptr->lcptr;
	
	jptr->lcptr=RotateLeft(kptr);

	
	
	return(RotateRight(jptr));

}

struct node *RotateRightLeft(struct node *ptr)
{

	struct node *jptr=ptr;
	struct node *kptr=jptr->rcptr;
	
	jptr->rcptr=RotateRight(kptr);
	
	
	return(RotateLeft(jptr));

}

int BalanceFactor(struct node *ptr) 
{
    if (ptr == NULL)
        return 0;

    return HT(ptr->lcptr)-HT(ptr->rcptr);
}

struct node *leastNode(struct node* rptr) 
{
    struct node *temp = rptr;
 
    while (temp->lcptr != NULL)
        temp = temp->lcptr;
 
    return temp;
}

void inorder(struct node *ptr)
{
	if(ptr!=NULL)
	{
		
		inorder(ptr->lcptr);
		printf("%d  ",ptr->data);
		inorder(ptr->rcptr);
	}
}

void postorder(struct node *ptr)
{
	if(ptr!=NULL)
	{
		
		postorder(ptr->lcptr);
		postorder(ptr->rcptr);
		printf("%d  ",ptr->data);
	}
}

struct node *insert(struct node *ptr ,int x)
{
	if(ptr==NULL)
	{	ptr= (struct node* ) malloc(sizeof(struct node));
		ptr->data=x;
		ptr->height=0;
		ptr->lcptr=NULL;
		ptr->rcptr=NULL;
	}

	else
	{
					if(x<ptr->data)
					{
						ptr->lcptr=insert(ptr->lcptr,x);	
					
						if((BalanceFactor(ptr)==2) || (BalanceFactor(ptr)==-2))
						{
						 if(x<(ptr->lcptr)->data)
						 	ptr=RotateRight(ptr);
						 else
						 	ptr=RotateLeftRight(ptr);
						}
					}
					
					else
					{
						ptr->rcptr=insert(ptr->rcptr,x);
					
					
						if((BalanceFactor(ptr)==2) || (BalanceFactor(ptr)==-2))
						{
							 if(x<(ptr->rcptr)->data)
							 	ptr=RotateRightLeft(ptr);
							 else
							 	ptr=RotateLeft(ptr);
						}
					
					
					
					}
					
					HeightUpdate(ptr);
					
	}

	return(ptr);
}


struct node *delete(struct node *rptr,int x)
{
	if (rptr == NULL) 
    	return rptr;

    if (x < rptr->data)
        rptr->lcptr = delete(rptr->lcptr, x);
 
    else if (x > rptr->data)
        rptr->rcptr = delete(rptr->rcptr, x);

    else
    {
        // node with 0 or 1 child
        if (rptr->lcptr == NULL)
        {
            struct node *temp = rptr->rcptr;
            free(rptr);
            f=1;
            return temp;
        }
        else if (rptr->rcptr == NULL)
        {
            struct node *temp = rptr->lcptr;
            free(rptr);
            f=1;
            return temp;
        }
 
        // node with 2 children
        struct node *temp = leastNode(rptr->rcptr); //gets inorder successor
        rptr->data = temp->data; //inorder successor's data is copied to the node whose data is to be deleted
        rptr->rcptr = delete(rptr->rcptr, temp->data); //deleting inorder successor's node
    }

    if (rptr == NULL) //If root is NULL after deleting node
      return rptr;
    
    HeightUpdate(rptr); //updating height of current node
 
    // Left Left Case
    if (BalanceFactor(rptr) > 1 && BalanceFactor(rptr->lcptr) >= 0)
        return RotateRight(rptr);
 
    // Left Right Case
    if (BalanceFactor(rptr) > 1 && BalanceFactor(rptr->lcptr) < 0)
        return RotateLeftRight(rptr);
 
    // Right Right Case
    if (BalanceFactor(rptr) < -1 && BalanceFactor(rptr->rcptr) <= 0)
        return RotateLeft(rptr);
 
    // Right Left Case
    if (BalanceFactor(rptr) < -1 && BalanceFactor(rptr->rcptr) > 0)
        return RotateRightLeft(rptr);
 
    return rptr;

}

void avlcheck(struct node *rptr)
{
	if(rptr!=NULL)
	{
		avlcheck(rptr->lcptr);
		avlcheck(rptr->rcptr);
		printf("Data:  %d Balance Factor:  %d\n",rptr->data,BalanceFactor(rptr));
	}
}

int main()
{
	int t;
	while(1)
	{
		printf("1.Insert\n2.Delete\n3.Inorder\n4.Postorder\n5.AVL Check\n");
		scanf("%d",&t);
		switch(t)
		{
			case 1 : 
			{
				int x;
				printf("Enter integer to be inserted:-\n");
				scanf("%d",&x);
				rptr=insert(rptr,x);
			}
			break;

			case 2 : 
			{
				int x;
				f=0;
				printf("Enter integer to be deleted:-\n");
				scanf("%d",&x);
				rptr=delete(rptr,x);
				if(f==1)
					printf("%d is successfully deleted\n",x);
				else
					printf("%d is not present in AVL Tree.Hence cannot be deleted\n",x);
			}
			break;

			case 3 : 
			{
				printf("Inorder sequence:-\n");
				inorder(rptr);
				printf("\n");
			}
			break;

			case 4 : 
			{
				printf("Postorder sequence:-\n");
				postorder(rptr);
				printf("\n");
			}
			break;

			case 5 :
			{
				printf("Balance Factor for each node:-\n");
				avlcheck(rptr);
			}
			break;

			default : {}

		}
	}


	return(0);
}				




















			
