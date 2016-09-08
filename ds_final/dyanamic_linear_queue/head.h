/* header file to implement dynamic linear queue */
#include<stdio.h>
#include<stdlib.h>
#define NEW (struct node *)malloc(sizeof(struct node *))
struct node
{
 		int data;
	struct node *next;
}*front,*rear;
void init()
{
	front=rear=NULL;
}
void insertq(int n)
{
	struct node *temp;
	temp=NEW;
	temp->data=n;
	temp->next=NULL;
	if(isempty())
	{
		front=rear=temp;
		return;
	}
	rear->next=temp;
	rear=temp;
}
int removeq()
{
	int n;
	struct node *temp;
	n=front->data;
	temp=front;
	front=front->next;
	free(temp);
	return n;
}
int isempty()
{
	return front==NULL;
}
void displayq()
{
	struct node *temp;
	temp=front;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
}
