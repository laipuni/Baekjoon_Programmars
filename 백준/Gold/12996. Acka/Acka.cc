#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 50
#define DIV 1000000007
int s, A, B, C;
int sing[3];
long long dp[MAXSIZE + 1][MAXSIZE + 1][MAXSIZE + 1][MAXSIZE + 1];//depth, dotorya(A), kesakiyo(B), hongjun7(C)

void resetDP() {
	for (int i = 0; i <= MAXSIZE; i++) {
		for (int j = 0; j <= MAXSIZE; j++) {
			for (int k = 0; k <= MAXSIZE; k++) {
				for (int o = 0; o <= MAXSIZE; o++) {
					dp[i][j][k][o] = -1;
				}
			}
		}
	}
}
long long DFS(int depth, int a, int b, int c) {
	if (a == A && b == B && c == C && depth == s) {
		return 1;
	}
	else if (depth >= s) {
		return 0;
	}

	if (dp[a][b][c][depth] != -1) {
		return dp[a][b][c][depth];
	}

	dp[a][b][c][depth] = 0;

	if (a < A) {
		dp[a][b][c][depth] += DFS(depth + 1, a + 1, b, c) % DIV;
	}

	if (b < B) {
		dp[a][b][c][depth] += DFS(depth + 1, a, b + 1, c) % DIV;
	}

	if (c < C) {
		dp[a][b][c][depth] += DFS(depth + 1, a, b, c + 1) % DIV;
	}

	if (a < A && b < B) {
		dp[a][b][c][depth] += DFS(depth + 1, a + 1, b + 1, c) % DIV;
	}

	if (a < A && c < C) {
		dp[a][b][c][depth] += DFS(depth + 1, a + 1, b, c + 1) % DIV;
	}

	if (b < B && c < C) {
		dp[a][b][c][depth] += DFS(depth + 1, a, b + 1, c + 1) % DIV;
	}

	if (a < A && b < B && c < C) {
		dp[a][b][c][depth] += DFS(depth + 1, a + 1, b + 1, c + 1) % DIV;
	}

	return dp[a][b][c][depth] % DIV;
}
int main() {
	scanf("%d %d %d %d", &s, &A, &B, &C);

	resetDP();

	printf("%lld", DFS(0, 0, 0, 0));
}