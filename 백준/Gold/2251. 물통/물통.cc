#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX_WATER 200
int a, b, c;
bool visited[MAX_WATER + 1][MAX_WATER + 1][MAX_WATER + 1];
bool result[MAX_WATER + 1];

int poured(int x,int y,int z) {
	return (x + y) > z ? z : (x + y);
}
int pour(int x, int y,int z) {
	return  (y - (z - x)) > 0 ? (y - (z - x)) : 0;
}
void DFS(int A, int B, int C) {
	if (visited[A][B][C]) {
		return;
	}

	visited[A][B][C] = true;

	if (A == 0) {
		result[C] = true;
	}

	if (C != 0) {
		DFS(A, poured(B,C,b), pour(B,C,b));
		DFS(poured(A, C, a), B, pour(A, C, a));
	}

	if (B != 0) {
		DFS(poured(A, B, a), pour(A, B, a), C);
		DFS(A, pour(C, B, c), poured(C, B, c));
	}

	if(A != 0){
		DFS(pour(B, A, b), poured(B, A, b), C);
		DFS(pour(C, A, c), B, poured(C, A, c));
	}
}
int main() {
	scanf("%d %d %d", &a, &b, &c);

	DFS(0, 0, c);

	for (int i = 0; i <= MAX_WATER; i++) {
		if (result[i]) {
			printf("%d ", i);
		}
	}
}