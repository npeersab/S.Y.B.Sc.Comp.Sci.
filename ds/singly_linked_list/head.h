#include<stdlib.h>
#include<stdio.h>
#define NEW (struct node *)malloc(sizeof(struct node))
struct node
{
	int data;
	struct node *next;
}*head,*temp;
void reset();
void create(int n)
{
	struct node *current;
	int i;
	reset();
	head=NULL;
	for(i=0;i<n;i++)
	{
		temp=NEW;
		printf("\t\t\tEnter item: ");
		scanf("%d",&temp->data);
		if(head==NULL)
		{
			head=temp;
			current=temp;
		}
		else
		{
			current->next=temp;
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
		printf("\n\t\t\tData will be added at head...\n");
		head=NEW;
		printf("\t\t\tEnter item: ");
		scanf("%d",&head->data);
		head->next=NULL;
	}
	else
	{
		while(temp->data!=item && temp->next!=NULL)
			temp=temp->next;
		if(temp->next==NULL)
			printf("\n\t\t\tItem not found new item will be added at the end...\n");
		new=NEW;
		printf("\n\t\t\tEnter item to be added after the item: ");
		scanf("%d",&new->data);
		new->next=temp->next;
		temp->next=new;
		printf("\n\t\t\tItem added...\n");
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
void sort()
{
	struct node *temp1, *temp2;
	int temp_data, n, i, j;
	n = count_node();
	for(i = 0, temp1 = head; i < n; i++)
	{
		for(j = 0, temp2 = temp1; j < n-i-1; j++, temp2 = temp2->next)
		{
			if(temp2->data > temp2->next->data)
			{
				temp_data = temp2->data;
				temp2->data = temp2->next->data;
				temp2->next->data = temp_data;
			}
		}
	}

}
