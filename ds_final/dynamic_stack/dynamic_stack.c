/* driver program for dyanamic stack functions */
#include "dynamic_stack.h"
main()
{
        int choice,n;
        while(1)
        {
        printf("\n1.Init Stack\n2.Push\n3.Pop\n4.Peak\n5.Check if stack is empty\n6.Exit\nSelect Option:");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:
                                init();
                                break;
                        case 2:
                                printf("\nEnter element:");
				scanf("%d",&n);
                                push(n);
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
                                        printf("\nElement at top in stack: %d\n",peak());
                                break;
                        case 5:
                                if(isempty())
                                        printf("\nThe stack is empty...\n");
                                else
                                        printf("\nThe stack is not empty...\n");
                                break;
                        case 6:
                                exit(0);
                        default:
                                printf("\nPlease select option from menu\n");
                }
        }
}

