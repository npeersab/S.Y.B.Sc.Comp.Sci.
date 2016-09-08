#include "head.h"

main() {
	int n;
	printf("Enter size of graph : ");
	scanf("%d", &n);
	acceptGraph(n);
	BFS(n);
	if(isConnected(n))
		printf("Graph is Connected...\n");
	else
		printf("Graph is not connected...\n");
}

