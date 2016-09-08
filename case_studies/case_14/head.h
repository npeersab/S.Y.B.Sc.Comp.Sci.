#include <stdio.h>
#include <stdlib.h>
#define MAX 10

struct Queue {
	int rear, front, data[MAX];
} queue;

void insertqueue(int);
int removequeue();
void BFS(int);
void init();
int isEmpty();
void acceptGraph(int);
int isConnected(int);

int visited[MAX], graph[MAX][MAX];

void init() {

	queue.rear = queue.front = - 1;
}

void acceptGraph(int n) {

	int i, j;

	printf("Enter adjacency matrix :\n");
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			scanf("%d", &graph[i][j]);
}

void insertqueue(int n) {

	queue.rear = (queue.rear + 1) % MAX;
	queue.data[queue.rear] = n;
}

int removequeue() {

	int n;
	queue.front = (queue.front + 1) % MAX;
	n = queue.data[queue.front];
	return n;
}

void BFS(int n) {
	
	int v = 0, i;
	init();
	for(i = 0; i < n; i++)
		visited[i] = 0;
	insertqueue(v);
	visited[v] = 1;
	while(!isEmpty()) {
		v = removequeue();
		for(i = 0; i < n; i++)
			if((!visited[i]) && graph[v][i]) {
				insertqueue(i);
				visited[i] = 1;
			}
	}
}

int isEmpty() {
	return queue.front == queue.rear;

}

int isConnected(int n) {
	int i;
	for(i = 0; i < n; i++)
		if(!visited[i])
			return 0;
	return 1;
}
