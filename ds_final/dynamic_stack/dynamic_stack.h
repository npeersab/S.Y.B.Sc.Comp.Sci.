/* header file for dynamic stack implementation*/
#include<stdio.h>
#include<stdlib.h>
#define NEW (struct node *)malloc(sizeof(struct node*))
struct node
{
	int data;
	struct node *next;
}*top;
void init()
{
	while(!isempty())
		pop();
	top=NULL;
}
void push(int n)
{
	struct node *temp;
	temp=NEW;
	temp->data=n;
	temp->next=NULL;
	if(top==NULL)
	{
		top=temp;
		return;
	}
	temp->next=top;
	top=temp;
}
int pop()
{
	struct node *temp;
	int n;
	n=top->data;
	temp=top;
	top=top->next;
	free(temp);
	return n;
}
int peak()
{
	return top->data;
}
int isempty()
{
	return top==NULL;
}
