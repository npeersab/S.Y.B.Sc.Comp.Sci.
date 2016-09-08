#define MAX 50 

struct stack {
	char data[MAX];
	int  top;
} st;

void init();
void push(char);
char pop();
int isEmpty();
int isFull();
char peak();

void init() {

	st.top = -1;
}

void push(char ch) {

	st.data[++st.top] = ch;
}

char pop() {

	return st.data[st.top--];
}

char peak() {
	
	return st.data[st.top];
}

int isEmpty() {
	
	return st.top == -1;

}

int isFull() {
	
	return st.top == MAX - 1;
}
