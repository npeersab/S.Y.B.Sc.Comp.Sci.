#include "head.h"

main() {
	
	struct node *poly1, *poly2;
	int choice, n1, n2;
	
	init(poly1);
	init(poly2);
	while(1) {
		printf("\n1.Create Polynomials\n2.Display Polynomials\n3.Display addtion\n4.Exit\nEnter your choice : ");
		scanf("%d", &choice);
		switch(choice) {
			case 1 :
				printf("Enter size of Polynomial 1 : ");
				scanf("%d", &n1);
				poly1 = createPoly(n1);
				printf("Enter size of Polynomial 2 : ");
				scanf("%d", &n2);
				poly2 = createPoly(n2);
				break;
			case 2 :
				printf("Polynomial 1 :");
				display(poly1, n1);
				printf("Polynomial 2 :");
				display(poly2, n2);
				break;
			case 3 :
				addPoly(poly1, poly2, n1, n2);
				break;
			case 4 :
				exit(0);
		}
	}
}
