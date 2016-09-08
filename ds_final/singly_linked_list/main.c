/* c program to implement singly linked list*/
#include "head.h"
main()
{
	int n,choice;
	while(1)
	{
		printf("\n\t1.Create linked list \n\t2.Display linked list\n\t3.Count nodes\n\t4.Add node after item\n\t5.Check list is empty or not\n\t6.Remove last node\n\t7.Remove first node\n\t8.Sort Linked List\n\t9.Reset linked list\n\t10.Exit\n\tSelect option: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\n\t\tEnter size of linked list: ");
				scanf("%d",&n);
				create(n);
				break;
			case 2:
				if(!is_empty())
				{
					printf("\n\t\tLinked list is: ");
					display();
				}
				break;
			case 3:
				if(!is_empty())
					printf("\n\t\tThere is/are %d nodes in linked list\n",count_node());
				break;
			case 4:
				printf("\n\t\tEnter item: ");
				scanf("%d",&n);
				add_after(n);
				break;
			case 5:
				if(!is_empty())
					printf("\n\t\tlist is not empty...\n");
				break;
			case 6:
				if(!is_empty())
					printf("\n\t\t%d removed from the list...\n",remove_last());
				break;
			case 7:
				if(!is_empty())
					printf("\n\t\t%d removed from the list...\n",remove_head());
				break;
			case 8 :
				sort();
				printf("\n\t\tList Sorted...\n");
				break;
			case 9 :
				reset();
				printf("\n\t\tReset Complete...\n");
				break;
			case 10 :
				exit(0);
			default:
				printf("\n\t\tInvalid option...\n");
		}
	}
}

