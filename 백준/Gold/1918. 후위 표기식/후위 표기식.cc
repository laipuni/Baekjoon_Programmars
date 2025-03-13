#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define MAX_EXPR_SIZE 100
#define MAX_STACK_SIZE 100
typedef enum { lparan, rparen, plus, minus, times, divide, mod, eos, operand } precedence;
int stack[MAX_STACK_SIZE];
char expr[MAX_EXPR_SIZE];

void push(int* top, int num) {
	if (*top == MAX_STACK_SIZE - 1) {
		printf("스택 가득 찼다.\n");
		return;
	}
	else {
		*top = (*top) + 1;
		stack[*top] = num;
	}
}
void printToken(int temp) {

	switch (temp) {
	case plus: printf("+");return;
	case minus: printf("-");return;
	case divide: printf("/");return;
	case times: printf("*");return;
	case mod: printf("%%");return;
	default: return;
	}
}
precedence getToken(char* symbol, int* n) {
	*symbol = expr[(*n)++];

	switch (*symbol) {
	case '(': return lparan;
	case ')': return rparen;
	case '+': return plus;
	case '-': return minus;
	case '/': return divide;
	case '*': return times;
	case '%': return mod;
	case '\0': return eos;
	default: return operand;
	}

}
void postfix() {
	int isp[8] = { 0,19,12,12,13,13,13,0 };
	int icp[8] = { 20,19,12,12,13,13,13,0 };
	char symbol;
	precedence token;
	int n = 0;
	int top = 0;
	stack[0] = eos;

	for (token = getToken(&symbol, &n); token != eos; token = getToken(&symbol, &n)) {

		if (token == operand) {
			printf("%c", symbol);
		}
		else if (token == rparen) {

			while (stack[top] != lparan) {
				printToken(stack[top--]);
			}
			top--;
		}
		else {

			while (isp[stack[top]] >= icp[token]) {
				printToken(stack[top--]);
			}
			push(&top, token);
		}
	}
	while (stack[top] != eos) {
		printToken(stack[top--]);
	}
}
int calculator() {
	precedence token;
	char symbol;
	int op1, op2;
	int n = 0;
	int top = -1;
	token = getToken(&symbol, &n);

	while (token != eos) {
		if (token == operand) {
			push(&top, symbol - '0');
		}
		else {
			op2 = stack[top--];
			op1 = stack[top--];

			switch (token) {
			case plus: push(&top, op1 + op2); break;
			case minus:push(&top, op1 - op2); break;
			case times: push(&top, op1 * op2); break;
			case divide:push(&top, op1 / op2); break;
			case mod: push(&top, op1 % op2); break;
			}
		}

		token = getToken(&symbol, &n);
	}

	return stack[top--];
}
int main() {

	scanf( "%s", expr);

	postfix();
}