#include<stdio.h>
#include<stdbool.h>
#define MAXSIZE 500000
typedef struct {
	long long num;
	int idx;
}element;
int n;
element stack[MAXSIZE + 1];
long long arr[MAXSIZE + 1];
long long oasis[MAXSIZE + 1];
int top = -1;

int main() {
	long long result = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}

	top++;
	stack[top].num = arr[0];
	stack[top].idx = 0;

	for (int i = 1; i < n; i++) {
		while (top != -1 && stack[top].num < arr[i]) {
			result++;
			top--;
		}

		if (top != -1) {
			oasis[i]++;
			result++;
		}

		if (stack[top].num == arr[i]) {
			oasis[i] += oasis[stack[top].idx];
			result += oasis[stack[top].idx];
		}

		top++;
		stack[top].num = arr[i];
		stack[top].idx = i;
	}

	printf("%lld", result);
}