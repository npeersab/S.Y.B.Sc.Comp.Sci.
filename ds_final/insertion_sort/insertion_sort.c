# include<stdio.h>
main()
{
	void insertsort(int array[],int n);
	void display(int array[],int n);
	void create(int array[],int n);
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
				insertsort(array,n);
				break;
			case 4:
				break;
			default:
				printf("Please Select Correct Option\n");
		}
	}while(choice!=4);
}
void insertsort(int array[50],int n)
{
	int i,j,temp;
	for(i=1;i<n;i++)
	{
		temp=array[i];
		for(j=i-1;j>0 && array[j]>temp;j--)
			array[j+1]=array[j];
		array[j+1]=temp;
	}
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

