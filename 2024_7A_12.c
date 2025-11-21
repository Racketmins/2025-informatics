#include <stdio.h>
#include <string.h>
#define MAX 100
int STACK[MAX];
int top = -1;
int iop(char op) {
	switch (op) {
	case '(':
	case ')': return 0;
	case '+':
	case '-': return 1;
	case '*':
	case '/': return 2;
	}
	return -1;
}
void intop(char exp[]) {
	int i;
	char ch, OP;
	for (i = 0; i < strlen(exp); i++) {
		ch = exp[i];
		switch (ch) {
		case '+':
		case '-':
		case '*':
		case '/':
			while (top != -1 &&
				(iop(ch) <= iop(STACK[top])))
				printf("%c", STACK[top--]);
			STACK[++top] = ch;
			break;
		case '(':
			STACK[++top] = ch;
			break;
		case ')':
			OP = STACK[top--];
			while (OP != '(') {
				printf("%c", OP);
				OP = STACK[top--];
			}
			break;
		default:
			printf("%c", ch); break;
		}
		//if (i == 7 || i == 11)
			//printf("%c", STACK[top]);
	}
	while (top != -1)
		printf("%c", STACK[top--]);
}
int main() {
	char exp[] = "(5+3)*2+7*(3+4*9)/3+7";
	intop(exp);
	return 0;
}
