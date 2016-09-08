#include<stdio.h>
void swap(int *,int *);
int partition(int array[50],int,int);
void quicksort(int array[50],int lb,int ub);
void display(int array[50],int n);
void create(int array[50],int n);
main()
{
	int n,choice,array[50];
	do
	{
		printf("\n-----------------------------------------\n1.Create Array\n2.Display Array\n3.Sort Array\n4.Exit\nSelect Option:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter Size (Max 50):");
				scanf("%d",&n);
				create(array,n);
				break;
			case 2:
				printf("Array is:\n");
				display(array,n);
				break;
			case 3:
				quicksort(array,0,n-1);
				break;
			case 4:
				break;
			default:
				printf("Please Select Correct Option\n");
		}
	}while(choice!=4);
}
void swap(int *a,int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
int partition(int array[50],int lb,int ub)
{
	int pivot,left,right;
	pivot = array[lb];
	left = lb;
	right = ub;
	while(left < right)
	{
		while(array[left] <= pivot && left < ub)
			left++;
		while(array [right] > pivot)
			right--;
		if(left < right)
			swap(&array[left],&array[right]);
	}
	swap(&array[lb],&array[right]);
	return right;
}
void quicksort(int array[50],int lb,int ub)
{
	int j;
	if(lb<ub)
	{
		j=partition(array,lb,ub);
		quicksort(array,lb,j-1);
		quicksort(array,j+1,ub);
	}
}
void create(int array[50],int n)
{
	int i;
	for(i=0;i<n;i++)
		array[i]=random()%50;
		scanf("%d",&array[i]);
}
void display(int array[50],int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ",array[i]);
}

