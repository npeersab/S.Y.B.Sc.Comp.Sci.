/* c program to implement static linear queue*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 20
struct quueu
{
	int front,rear,array[MAX];
}qu;
void initqu();
void insertqu(int);
int removequ();
int isemptyqu();
int isfullqu();
main()
{
	int choice,item;
	while(1)
	{
		printf("\n1.Initialize/Reset Queue (Before any operation you should intialize Queue)\n2.Insert an element to queue\n3.Remove an element from queue\n4.Check queue is empty or not\n5.Check queue is full or not\n6.Exit\nSelect option: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				initqu();
				printf("\nQueue initialized...\n");
				break;
			case 2:
				if(isfullqu())
					printf("\nCant insert element !!\nQueue is full...\n");
				else
				{
					printf("\nEnter element to be inserted in queue: ");
					scanf("%d",&item);
					insertqu(item);
				}
				break;
			case 3:
				if(isemptyqu())
					printf("\nThere is no element in Queue...\n");
				else
					printf("\nElement removed from queue: %d\n",removequ());
				break;
			case 4:
				if(isemptyqu())
					printf("\nQueue is empty...\n");
				else
					printf("\nQueue is not empty...");
				break;
			case 5:
				if(isfullqu())
					printf("\nQueue is full...\n");
				else
					printf("\nQueue is not full...\n");
				break;
			case 6:
				exit(0);
			default:
				printf("\nInvalid Option ...\n");
		}
	}
}
void initqu()
{
	qu.front=qu.rear=(-1);
}
void insertqu(int item)
{
	qu.array[++qu.rear]=item;
}
int removequ()
{
	int item;
	item=qu.array[++qu.front];
	return item;
}
int isemptyqu()
{
	if(qu.front==qu.rear)
		return 1;
	else
		return 0;
}
int isfullqu()
{
	if(qu.rear==MAX-1)
		return 1;
	else
		return 0;
}	
