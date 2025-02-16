#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAXSIZE 500
#define MAX(a,b)a>b?a:b
bool visited[MAXSIZE + 1][MAXSIZE + 1];
int map[MAXSIZE + 1][MAXSIZE + 1];
int dp[MAXSIZE + 1][MAXSIZE + 1];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int n;

bool isMap(int x,int y) {
	if ((0 <= x) && (x < n) && (0 <= y) && (y < n)) {
		return true;
	}

	return false;
}
int DFS(int x,int y) {
	if (dp[y][x] != -1) {
		return dp[y][x];
	}

	int max = 0;
	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if (!isMap(next_x,next_y)) {
			continue;
		}

		if (map[y][x] >= map[next_y][next_x]) {
			continue;
		}

		max = MAX(max,DFS(next_x, next_y) + 1);
	} 

	dp[y][x] = max;

	return dp[y][x];
}
void input() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
			dp[i][j] = -1;
		}
	}
}
int main() {
	scanf("%d", &n);

	input();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				DFS(j, i);
			}
		}
	}

	int max = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			max = MAX(max, dp[i][j]);
		}
	}

	printf("%d", max + 1);
}