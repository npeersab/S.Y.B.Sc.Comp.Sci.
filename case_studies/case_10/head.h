#include <stdio.h>
#include <stdlib.h>
#define NEWNODE (struct node *) malloc(sizeof(struct node))

struct node {
	
	int coe, exp;
	struct node *next;
};

void init(struct node *);
struct node * createPoly(int);
void display(struct node *, int);


void init(struct node *head) {
	
	head = NULL;
}

struct node * createPoly(int n) {

	struct node *temp1, *temp2, *temp3, *head;
	int i;

	for(i = 0; i < n; i++) {
		temp1 = NEWNODE;
		printf("Enter Coefficient : ");
		scanf("%d", &temp1 -> coe);
		printf("Enter Exponent : ");
		scanf("%d", &temp1 -> exp);
		temp1 -> next = NULL;
		if(head == NULL) {
			head = temp1;
			continue;
		}
		if(head -> exp < temp1 -> exp) {
			temp1 -> next = head;
			head = temp1;
			continue;
		}
		temp3 = temp2 = head;
		while(temp1 -> exp > temp2 -> exp && temp2 -> next != NULL) {
			temp3 = temp2;
			temp2 = temp2 -> next;
		}
		temp1 -> next = temp3 -> next;
		temp3 -> next = temp1;
	}
	temp1 = NEWNODE;
	temp1 -> next = head;
	head = temp1;
	return head;
}

void display(struct node *head, int n) {
	
	struct node *temp;
	int i;
	
	temp = head -> next;
	for(i = 0; i < n; i++) {
		printf(" (%d ^ %d) ", temp -> coe, temp -> exp);
		temp = temp -> next;
		if(i < n - 1)
			printf("+");
	}
}

struct node * addPoly(struct node *p1, struct node *p2, int n1, int n2) {
	
	struct node *p3, *temp, *last;
	int n3 = 0;
	
	while(n1 != 0 || n2 != 0) {
		if(p1 -> exp == p2 -> exp) {
			temp = NEWNODE;
			temp -> coe = p1 -> coe + p2 -> coe;
			temp -> exp = p1 -> exp;
			temp -> next == NULL;
			if(p3 == NULL)
				p3 = last = temp;
			else {
				last -> next = temp;
				last = temp;
			}
		p1 = p1 -> next;
		p2 = p2 -> next;
		n1--, n2--, n3++;
		}
		if(p1 -> exp > p2 -> exp && n1 != 0) {
			temp = NEWNODE;
			temp -> coe = p1 -> coe;
			temp -> exp = p1 -> exp;
			temp -> next == NULL;
			if(p3 == NULL)
				p3 = last = temp;
			else {
				last -> next = temp;
				last = temp;
			}	
			p1 = p1 -> next;
			n1--, n3++;
		}
		if(p2 -> exp > p1 -> exp && n2 != 0) {
			temp = NEWNODE;
			temp -> coe = p2 -> coe;
			temp -> exp = p2 -> exp;
			temp -> next == NULL;
			if(p3 == NULL)
				p3 = temp;
			else {
				last -> next = temp;
				last = temp;
			}
			p2 = p2 -> next;
			n2--, n3++;
		}
	}
	temp = NEWNODE;
	temp -> next = p3;
	p3 = temp;
	printf("Addtion of Polynomials is : ");
	display(p3, n3);
}
