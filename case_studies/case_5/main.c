#include <stdio.h>
#include <ctype.h>
#include "stack.h"

int priority(char);

main() {

	char x, exp[50];
	int i;
	

	init();
	printf("\nEnter Infix expression : ");
	scanf("%s", exp);
	printf("\nThe Postfix expression is : ");
	for(i = 0; exp[i] != '\0'; i++) {
		if(isalnum(exp[i]))
			printf("%c", exp[i]);
		else 
			if(exp[i] == '(')
				push('(');
			else {
				if(exp[i] == ')')
					while((x = pop())!='(')
						printf("%c", x);
				else {
					while(priority(exp[i]) <= priority(peak()) && !isEmpty()) {
						x = pop();
						printf("%c",x);
					}
					push(exp[i]);
				}
			}
	}
	while(!isEmpty()) {
		x = pop();
		printf("%c", x);
	}
	printf("\n");
}

int priority(char x)
{
	if(x == '(')
		return 0;
	if(x == '+' || x == '-')
		return 1;
	if(x == '*' || x == '/' || x == '%')
		return 2;
	return 3;
}

