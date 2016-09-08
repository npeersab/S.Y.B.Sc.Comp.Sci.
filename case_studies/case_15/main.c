#include "head.h"
	
main() {
	
	int v;
	
	initVisited();
	printf("Enter no. of vertices : ");
	scanf("%d", &n);
	acceptGraph(); 
	DFS(findSource(n));
	displayOrder();
}


