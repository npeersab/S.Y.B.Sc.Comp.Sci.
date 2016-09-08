struct stack {
	int data[100], top;
} st;

void initStack();
void push(int);
int pop();

void initStack() {
	st.top = -1;
}

void push(int n) {
	st.data[++st.top] = n;
}

int pop() {
	return st.data[st.top--];
}
 
