#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAXSIZE 15
int length, n;
bool checked[MAXSIZE + 1];
char str[MAXSIZE + 1];
char depth_str[MAXSIZE + 1][MAXSIZE + 1];

int cmp(const void* a, const void* b) {
	char x = *(char*)a;
	char y = *(char*)b;

	if (x > y) {
		return 1;
	}
	else if (x < y) {
		return -1;
	}
	else {
		return 0;
	}
}
bool is_gather(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
		return true;
	}

	return false;
}
void DFS(int depth,int con,int ga,char pre) {
	if (depth == length) {
		if (con >= 2 && ga >= 1) {
			printf("%s\n", depth_str[depth]);
		}

		return;
	}

	strcpy(depth_str[depth + 1], depth_str[depth]);

	for (int i = 0; i < n; i++) {
		if (checked[i] || str[i] < pre) {
			continue;
		}

		checked[i] = true;
		depth_str[depth + 1][depth] = str[i];

		if (is_gather(str[i])) {
			DFS(depth + 1, con, ga + 1, str[i]);
		}
		else {
			DFS(depth + 1, con + 1, ga, str[i]);
		}

		checked[i] = false;
	}
}
int main() {
	scanf("%d %d", &length, &n);

	for (int i = 0; i < n; i++) {
		scanf(" %c", &str[i]);
	}

	qsort(str, n, sizeof(char), cmp);

	DFS(0, 0, 0, 0);
}