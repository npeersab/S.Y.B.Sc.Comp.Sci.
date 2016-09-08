/* driver program for dynamic linear queue implementation */
#include "head.h"
main()
{
	int n,choice;
	while(1)
	{
		printf("\n\t1.Initialize  Queue\n\t2.Inesrt an element in queue\n\t3.Delete element from queue\n\t4.Check if queue is empty\n\t5.Display Queue\n\t6.Exit\n\tSelect option: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				init();
				printf("\n\tQueue initialized...\n");
				break;
			case 2:
				printf("\n\tEnter element to be added: ");
				scanf("%d",&n);
				insertq(n);
				break;
			case 3:
				if(isempty())
					printf("\n\tQueue is empty...\n");
				else
					printf("\n\t%d Removed from the queue...\n",removeq());
				break;
			case 4:
				if(isempty())
					printf("\n\tQueue is empty...\n");
				else
					printf("\n\tQueue is not empty...\n");
				break;
			case 5:
				if(isempty())
					printf("\n\tQueue is empty...\n");
				else
				{
					printf("\n\tQueue :");
					displayq();
					printf("\n");
				}
				break;
			case 6:
				exit(0);
			default:
				printf("\n\tInvalid Option\n");
		}
	}		
}

