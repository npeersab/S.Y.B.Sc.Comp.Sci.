#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NEWNODE (struct node *) malloc(sizeof(struct node))

struct node {
	int amount;
	char username[20];
	struct node *next;
} *head;

struct Machine {
	
	int amount, idle;
	char username[20];
} machine;

void init();
void addUser(char [], int);
void removeUser();
void removefromMachine();
void getStatus();
void displayUser();

void init() {

	head = NULL;
	machine.idle = 1;
}

void addUser(char name[], int amount) {

	struct node *temp1, *temp2, *temp3;

	temp1 = NEWNODE;
	temp1 -> amount = amount;
	strcpy(temp1 -> username, name);
	temp1 -> next = NULL;
	if(head == NULL) {
		head = temp1;
		removeUser();
		return;
	}
	if(amount > head -> amount) {
		temp1 -> next = head;
		head = temp1;
		removeUser();
		return;
	}
	temp3 = temp2 = head;
	while(temp2 -> amount > amount && temp2 -> next != NULL) {
		temp3 = temp2;	
		temp2 = temp2 ->  next;
	}
	temp1 -> next = temp3 -> next;
	temp3 -> next = temp1;
	removeUser();
}

void removeUser() {

	struct node *temp;

	if(machine.idle) {
		machine.amount = head -> amount;
		strcpy(machine.username, head -> username);
		printf("%s is having the machine...\n", machine.username);
		machine.idle = 0;
		temp = head;
		head = head -> next;
		free(temp);
	}
	
}

void removefromMachine() {

	if(!machine.idle)
		printf("%s returned the machine...\n", machine.username);
	machine.idle = 1;
	if(head != NULL) 
		removeUser();
	else
		printf("Machine is idle...\n");
}

void getStatus() {
	
	if(machine.idle) {
		printf("Machine is idle...\n");
		return;
	}
	printf("Current user : %s\nAmount : %d\n", machine.username, machine.amount);
}

void displayUser() {

	struct node *temp;
	
	if(head == NULL) {
		printf("There are no pending users...\n");
		return;
	}
	printf("Name\tamount\n\n");
	temp = head;
	while(temp != NULL) {
		printf("%s\t%d\n", temp -> username, temp -> amount);
		temp = temp -> next;
	}
}
