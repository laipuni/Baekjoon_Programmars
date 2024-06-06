#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define Long long long
#define MAX_MAP 100
typedef struct {
	short x;
	short y;
}element;
int ans, n, m;
bool key[27];
bool is_find;
bool visited[MAX_MAP][MAX_MAP];
char map[MAX_MAP + 1][MAX_MAP + 1];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

void reset() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = false;
		}
	}
}
bool is_map(int x, int y) {
	return ((0 <= x) && (x < m) && (0 <= y) && (y < n));
}
void DFS(int x,int y) {
	visited[y][x] = true;

	if (map[y][x] == '$') {
		map[y][x] = '.';
		ans++;
	}

	if (('a' <= map[y][x] && map[y][x] <= 'z') && !key[map[y][x] - 'a']) {
		key[map[y][x] - 'a'] = true;
		map[y][x] = '.';
		is_find = true;
	}

	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if (!is_map(next_x, next_y)) {
			continue;
		}

		if (visited[next_y][next_x] || map[next_y][next_x] == '*') {
			continue;
		}

		if (('A'<= map[next_y][next_x] && map[next_y][next_x] <= 'Z') && !key[map[next_y][next_x] - 'A']) {
			continue;
		}

		DFS(next_x, next_y);
	}

}
void input() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%s", map[i]);
	}

	char str[27];
	scanf("%s", str);

	if (str[0] != '0') {
		for (int i = 0; i < strlen(str); i++) {
			key[str[i] - 'a'] = true;
		}
	}
}
bool is_enter(int i, int j) {
	if (map[i][j] == '.' || map[i][j] == '$' || ('a' <= map[i][j] && map[i][j] <= 'z')) {
		return true;
	}

	if ('A' <= map[i][j] && map[i][j] <= 'Z' && key[map[i][j] - 'A']) {
		return true;
	}

	return false;
}
void solve() {
	input();

	do {
		is_find = false;

		for (int i = 0; i < n; i++) {
			if (is_enter(i, 0)) {
				DFS(0, i);
			}

			if (is_enter(i, m - 1)) {
				DFS(m - 1, i);
			}

		}

		for (int i = 0; i < m; i++) {
			if (is_enter(0, i)) {
				DFS(i, 0);
			}

			if (is_enter(n - 1, i)) {
				DFS(i, n - 1);
			}

		}

		reset();
	} while (is_find);

	printf("%d\n", ans);
	
	//다음 케이스를 위한 초기화
	ans = 0;
	for (int i = 0; i <= 26; i++) {
		key[i] = false;
	}
}
int main() {
	int t;
	
	scanf("%d", &t);

	while (t--) {
		solve();
	}
}