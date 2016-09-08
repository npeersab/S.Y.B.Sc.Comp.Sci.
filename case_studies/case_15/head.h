#include <stdio.h>
#include <stdlib.h>
#define NEWNODE (struct node *) malloc(sizeof(struct node))

struct node {
	int data;
	struct node *next;
} *head = NULL, *temp = NULL;

int graph[10][10], visited[10], n;

void acceptGraph();
void initVisited();
void DFS(int);
void addNode(int);
int findSource();
void displayOrder();

void acceptGraph() {

	int i, j;

	printf("Enter adjacency matrix :\n");
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			scanf("%d", &graph[i][j]);
}

void initVisited() {
	
	int i;
	
	for(i = 0; i < n; i++)
		visited[i] = 0;
}

void DFS(int i) {
	
	int j;

	visited[i] = 1;
	addNode(i + 1);
	for(j = 0; j < n; j++)
		if((!visited[j]) && graph[i][j])
			DFS(j);
}

int findSource(int n) {

	int i, j, od;

	for(i = 0; i < n; i++) {
		od = 0;
		for(j = 0; j < n; j++) {
			od = od + graph[j][i];
		}
		if(od == 0)
			return i;
	}
	printf("Cannot find topological order : No source found in the graph\n");
	exit(1);
}

void addNode(int n) {

	if(head == NULL) {
		head = NEWNODE;
		head -> next = NULL;
		head -> data = n;
		return;
	}
	temp = head;
	while(temp -> next != NULL)
		temp = temp -> next;
	temp -> next = NEWNODE;
	temp -> next -> data = n;
	temp -> next -> next = NULL;
}

void displayOrder() {
	temp = head;
	printf("Topological Order is : ");
	while(temp != NULL) {
		printf("v%d ", temp -> data);
		temp = temp -> next;
	}
	printf("\n");
}
