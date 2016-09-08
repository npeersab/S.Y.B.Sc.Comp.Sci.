/* C program to implement stack using array*/
int array[10],top;
void push(int);
int pop();
int peak();
int isempty();
int isfull();
void initstack();
#include<stdio.h>
#include<stdlib.h>
main()
{
	int choice,n;
	while(1)
	{
	printf("\n1.Init Stack\n2.Push\n3.Pop\n4.Peak\n5.Check if stack is empty\n6.Check if stack is full\n7.Exit\nSelect Option:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				initstack();
				break;
			case 2:
				if(isfull())
					printf("\nUnable to push element\nStack is full!!\n");
				else
				{
					printf("\nEnter element:");
					scanf("%d",&n);
					push(n);
				}
				break;
			case 3:
				if(isempty())
					printf("\nUnable to pop element\nStack is empty !!!\n");
				else
					printf("\nElement removed from  stack: %d\n",pop());
				break;
			case 4:
				if(isempty())
					printf("\nUnable to peak element\nStack is emtpy !!!\n");
				else
					printf("\nElement at top in stack: %d",peak());
				break;
			case 5:
				if(isempty())
					printf("\nThe stack is empty...\n");
				else
					printf("\nThe stack is not empty...\n");
				break;
			case 6:
				if(isfull())
					printf("\nStack is full!!\n");
				else 
					printf("\nStack is not full!!\n");
				break;
			case 7:
				exit(0);
			default:
				printf("\nPlease select option from menu\n");
		}
	}
}
void initstack()
{
	top=-1;
}
void push(int n)
{
	top++;
	array[top]=n;
}
int pop()
{
	int n;
	n=array[top];
	top--;
	return n;
}
int peak()
{
	int n;
	n=array[top];
	return n;
}
int isempty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}
int isfull()
{
	if(top==9)
		return 1;
	else 
		return 0;
}
