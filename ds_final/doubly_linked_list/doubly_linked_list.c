/* c program to implement doubly linked list*/
#include<stdlib.h>
#include<stdio.h>
#define NEW (struct node *)malloc(sizeof(struct node))
struct node
{
	int data;
	struct node *next,*prev;
}*head,*temp;
void create(int);
void display();
int count();
void add_after(int);
int is_empty();
int remove_last();
int remove_head();
void reset();
main()
{
	int n,choice;
	while(1)
	{
		printf("\n1.Create linked list \n2.Display linked list\n3.Count nodes\n4.Add node after item\n5.Check list is empty or not\n6.Remove last node\n7.Remove first node\n8.Reset linked list\n9.Exit\nSelect option: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\nEnter size of linked list: ");
				scanf("%d",&n);
				create(n);
				break;
			case 2:
				if(!is_empty())
				{
					printf("\nLinked list is: ");
					display();
				}
				break;
			case 3:
				if(!is_empty())
					printf("\nThere is/are %d nodes in linked list\n",count_node());
				break;
			case 4:
				printf("\nEnter item: ");
				scanf("%d",&n);
				add_after(n);
				break;
			case 5:
				if(!is_empty())
					printf("\nlist is not empty...\n");
				break;
			case 6:
				if(!is_empty())
					printf("\n%d removed from the list...\n",remove_last());
				break;
			case 7:
				if(!is_empty())
					printf("\n%d removed from the list...\n",remove_head());
				break;
			case 8:
				reset();
				printf("\nReset Complete...\n");
				break;
			case 9:
				exit(0);
			default:
				printf("\nInvalid option...\n");
		}
	}
}
void create(int n)
{
	struct node *current;
	int i;
	reset();
	head=NULL;
	for(i=0;i<n;i++)
	{
		temp=NEW;
		printf("Enter item: ");
		scanf("%d",&temp->data);
		temp->next=temp->prev=NULL;
		if(head==NULL)
			head=current=temp;
		else
		{
			current->next=temp;
			temp->prev=current;
			current=temp;
		}
	}
}
void display()
{
	temp=head;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
int count_node()
{
	int i=0;
	temp=head;
	while(temp!=NULL)
	{
		temp=temp->next;
		i++;
	}
	return i;
}
void add_after(int item)
{
	struct node *new;
	temp=head;
	if(is_empty())
	{
		printf("\nData will be added at head...\n");
		head=NEW;
		printf("Enter item: ");
		scanf("%d",&head->data);
		head->next=head->prev=NULL;
	}
	else
	{
		while(temp->data!=item && temp->next!=NULL)
			temp=temp->next;
		if(temp->next==NULL)
			printf("\nItem not found new item will be added at the end...\n");
		new=NEW;
		printf("\nEnter item to be added after the item: ");
		scanf("%d",&new->data);
		new->next=temp->next;
		temp->next=new;
		new->next->prev=new;
		printf("\nItem added...\n");
	}
}
int is_empty()
{
	if(head==NULL)
	{
		printf("\nlist is empty...\n");
		return 1;
	}
	else
		return 0;
}
int remove_last()
{
	int data;
	struct node *last;
	temp=head;
	if(head->next==NULL)
	{
		data=head->data;
		free(head);
		head=NULL;
		return data;
		
	}
	else
	{
		while(temp->next->next!=NULL)
			temp=temp->next;
		last=temp->next;
		data=last->data;
		free(last);
		temp->next=NULL;
	}
	return data;
}
int remove_head()
{
	int data;
	temp=head;
	data=head->data;
	head->prev=NULL;
	head=head->next;
	free(temp);
	return data;
}
void reset()
{
	int size,i;
	size=count_node();
	for(i=0;i<size;i++)
		remove_head();
}
