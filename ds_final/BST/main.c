#include "head.h"
main()
{
	int n, choice;
	while(1)
	{
		printf("\n\t1.Create BST\n\t2.Traverse in Preorder\n\t3.Traverse in Inorder\n\t4.Traverse in Postorder\n\t5.Count Nodes\n\t6.Count Leaf nodes\n\t7.Count internal nodes\n\t8.Exit\n\tSelect option: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1 :
				printf("\n\t\tEnter size of BST: ");
				scanf("%d", &n);
				create_bst(n);
				break;
			case 2 :
				printf("\n\t\tPreorder: ");
				preorder(root);
				printf("\n");
				break;
			case 3 :
				printf("\n\t\tInorder: ");
				inorder(root);
				printf("\n");
				break;
			case 4 :
				printf("\n\t\tPostorder: ");
				postorder(root);
				printf("\n");
				break;
			case 5 :
				printf("\n\t\tNodes in tree: %d\n",count_node(root));
				break;
			case 6 :
				printf("\n\t\tLeaf nodes in tree: %d\n", count_leaf_node(root));
				break;
			case 7 :
				printf("\n\t\tInternal nodes in tree: %d\n", count_internal_node(root));
				break;
			case 8 :
				printf("\n");
				exit(0);
			default :
				printf("\n\t\tInvalid option...\n");
		
		}
	}
}
