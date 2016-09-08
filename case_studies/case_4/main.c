#include <stdio.h>
#include "stack.h"

main() {
	int evaluate(char *);
	char str[50];
	printf("Enter the postfix  expression to be evaluated : ");
	scanf("%s", str);
	printf("The evaluation of expression is %d\n", evaluate(str));
}

int evaluate(char *str) {
	int i, op1, op2, n;
	for(i = 0; str[i] != '\0'; i++) {
		switch(str[i]) {
			case '+' :
				op2 = pop();
				op1 = pop();
				push(op1 + op2);
				break;
			case '-' :
				op2 = pop();
				op1 = pop();
				push(op1 - op2);
				break;
			case '*' :
				op2 = pop();
				op1 = pop();
				push(op1 * op2);
				break;
			case '/':
				op2 = pop();
				op1 = pop();
				push(op1 / op2);
				break;
			default:
				printf("Enter the value of %c : ", str[i]);
				scanf("%d", &n);
				push(n);
				break;
		}
	}
	return pop();
}
