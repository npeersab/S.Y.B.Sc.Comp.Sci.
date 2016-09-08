#include<stdio.h>
void mergesort(int array[],int lb,int ub);
void display(int array[],int n);
void create(int array[],int n);
void merge(int array[],int lb,int mid,int ub);
main()
{
	int n,choice,array[50];
	do
	{
		printf("\n1.Create Array\n2.Display Array\n3.Sort Array\n4.Exit\nSelect Option:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter Size (Max 50):");
				scanf("%d",&n);
				create(array,n);
				break;
			case 2:
				
				display(array,n);
				break;
			case 3:
				mergesort(array,0,n-1);
				break;
			case 4:
				break;
			default:
				printf("Please Select Correct Option\n");
		}
	}while(choice!=4);
}
void mergesort(int array[],int lb,int ub)
{
	int mid;
	if(lb<ub)
	{
		mid=(lb+ub)/2;
		mergesort(array,lb,mid);
		mergesort(array,mid+1,ub);
		merge(array,lb,mid,ub);
	} 
}
void merge(int array[],int lb,int mid,int ub)
{
	int i,j,k,temp[50];
	i=lb;
	j=mid+1;
	k=0;
	while((i<=mid)&&(j<=ub))
	{
		if(array[i]<=array[j])
			temp[k]=array[i++];
		else
			temp[k]=array[j++];
		k++;
	}
	while(i<=mid)
		temp[k++]=array[i++];
	while(j<=ub)
		temp[k++]=array[j++];
	for(i=lb,k=0;i<=ub;i++,k++)
		array[i]=temp[k];
}
void create(int array[50],int n)
{
	int i;
	for(i=0;i<n;i++)
		array[i]=random()%100;
}
void display(int array[50],int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ",array[i]);
}
