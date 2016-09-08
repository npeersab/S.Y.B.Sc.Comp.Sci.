#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NEWNODE (struct node *)malloc(sizeof(struct node))

struct node {
	char name[20];
	struct node *next;
} *first = NULL, *pos = NULL;

void createPlayer(int);

void createPlayer(int size) {
	int i;
	char temp_nm[20];
	struct node *temp;
	for(i = 0; i < size; i++) {
		printf("Enter Player %d name : ", i + 1);
		scanf("%s", temp_nm);
		if(first == NULL) {
			first = pos = NEWNODE;
			strcpy(pos -> name, temp_nm);
			pos -> next = first;
		}
		else {
			temp = NEWNODE;
			strcpy(temp -> name, temp_nm);
			temp -> next = first;
			pos -> next = temp;
			pos = temp;
		}
	}
}

void eliminatePlayer(int n) {
	struct node *temp = pos, *temp_prev;
	int i;
	for(i = 0; i < n; i++) {
		temp_prev = temp;
		temp = temp -> next;
	}
	pos = temp_prev -> next = temp -> next;
	printf("\n%s is eliminated\n\n", temp -> name);
	free(temp);
	if(pos -> next == pos) {
		printf("%s Wins !!!\n", pos -> name);
		exit(0);
	}
}
