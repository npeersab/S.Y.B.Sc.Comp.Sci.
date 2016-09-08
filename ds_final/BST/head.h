/* header file for binary search tree */
#include<stdio.h>
#include<stdlib.h>
#define NEW (struct node*)malloc(sizeof(struct node*))
struct node
{
	int data;
	struct node *right,*left;
}*root;
void create_bst(int no)
{
	struct node *temp,*new_node;
	int i,n;
	for(i = 0; i < no; i++)
	{
		temp = NEW;
		printf("\n\t\tEnter element: ");
		scanf("%d",&n);
		temp->data = n;
		temp->right = temp->left = NULL;
		if(root == NULL)
			root = temp;
		else
		{
			new_node = root;
			while(1)
			{
				if(n < new_node->data)
				{
					if(new_node->left == NULL)
					{
						new_node->left = temp;
						break;
					}
					else
						new_node = new_node->left;
				}
				else
				{
					if(new_node->right == NULL)
					{
						new_node->right = temp;
						break;
					}
					else
						new_node = new_node->right;
				}
			}
		}	
	}
}
void inorder(struct node *temp)
{
	if(temp != NULL)
	{
		inorder(temp->left);
		printf("%d ",temp->data);
		inorder(temp->right);
	}
}
void preorder(struct node *temp)
{
	if(temp!=NULL)
	{
		printf("%d ", temp->data);
		preorder(temp->left);
		preorder(temp->right);
	}
}
void postorder(struct node *temp)
{
	if(temp!=NULL)
	{
		postorder(temp->left);
		postorder(temp->right);
		printf("%d ", temp->data);
	}
}
int count_node(struct node *temp)
{
	if(temp == NULL)
		return 0;
	return 1 + (count_node(temp->left) + count_node(temp->right));
}
int count_leaf_node(struct node *temp)
{
	static int count=0;
	if(temp != NULL)
	{
		if(temp->left == NULL && temp->right == NULL)
			count++;
		count_leaf_node(temp->right);
		count_leaf_node(temp->left);
	}
	return count;
}
int count_internal_node(struct node *temp)
{
	static int count=0;
	if(temp != NULL)
	{
		if(temp->left !=NULL || temp->right !=NULL)
			count++;
		count_internal_node(temp->left);
		count_internal_node(temp->right);
	}
	return count;
}
