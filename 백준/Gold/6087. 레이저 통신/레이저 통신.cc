#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MIN(a,b)a<b?a:b
#define MAXQSIZE 50000
#define INF 1.0e+9
typedef struct {
	int x;
	int y;
	int direct;
	int mirror;//방향 전환 횟수 == 거울 수;
}element;
char** map;
int c[2][2];//레이저 위치(x,y)

void push(element* q, int* rear,int x,int y,int m,int direct) {
	if (*rear == MAXQSIZE) {
		return;
	}
	else {
		*rear = (*rear + 1);
		(q + (*rear))->x = x;
		(q + (*rear))->y = y;
		(q + (*rear))->direct = direct;
		(q + (*rear))->mirror = m;
	}
}
void pop(int* rear, int* front) {
	if (*rear == *front) {
		return;
	}
	else {
		*front = (*front + 1);
	}
}
void mapsetting(int w,int h) {
	for (int i = 0; i < h; i++) {
		scanf("%s", map[i]);
	}

	int idx = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (map[i][j] == 'C') {
				map[i][j] = '.';
				c[idx][0] = j;
				c[idx][1] = i;
				idx++;
			}
		}
	}
}
bool isMap(int x, int y,int w,int h) {
	//맵 범위 탈출 여부를 확인하는 변수
	if ((0 <= x) && (x < w) && (0 <= y) && (y < h) && (map[y][x] == '.')) {
		return true;
	}
	else {
		return false;
	}
}
void BFS(int w,int h) {
	int min = INF;
	int visited[101][101][4];

	for (int i = 0; i <= h; i++) {
		for (int j = 0; j <= w; j++) {
			visited[i][j][0] = INF;
			visited[i][j][1] = INF;
			visited[i][j][2] = INF;
			visited[i][j][3] = INF;
		}
	}

	element* q = (element*)malloc(sizeof(element) * (MAXQSIZE + 1));
	int rear = -1;
	int front = -1;
	
	int dir[4][2] = { {0,-1},{0,1},{-1,0},{1,0} }; //x,y

	visited[c[0][1]][c[0][0]][0] = 0;
	visited[c[0][1]][c[0][0]][1] = 0;
	visited[c[0][1]][c[0][0]][2] = 0;
	visited[c[0][1]][c[0][0]][3] = 0;

	for (int i = 0; i < 4; i++) {
		int x = c[0][0] + dir[i][0];
		int y = c[0][1] + dir[i][1];
		if (isMap(x, y, w, h)) {
			push(q, &rear, x, y, 0, i);
			visited[y][x][i] = 0;
		}
	}

	while (rear != front) {
		pop(&rear, &front);

		int x = (q + front)->x;
		int y = (q + front)->y;
		int direct = (q + front)->direct;
		int m = (q + front)->mirror;

		if ((x == c[1][0]) && (y == c[1][1])) {
			min = MIN(min, m);
			continue;
		}

		int nextx = x + dir[direct][0];
		int nexty = y + dir[direct][1];

		if (isMap(nextx, nexty, w, h) && (visited[nexty][nextx][direct] > m)) {
			push(q, &rear, nextx, nexty, m, direct);
			visited[nexty][nextx][direct] = m;
		}

		if (direct < 2) {
			//상, 하로 향하는 레이저
			if (isMap(x - 1, y, w, h) && (visited[y][x - 1][2] > m + 1)) {
				push(q, &rear, x - 1, y, m + 1, 2);
				visited[y][x - 1][2] = m + 1;
			}

			if (isMap(x + 1, y, w, h) && (visited[y][x + 1][3] > m + 1)) {
				push(q, &rear, x + 1, y, m + 1, 3);
				visited[y][x + 1][3] = m + 1;
			}

		}

		if (direct >= 2) {
			//좌, 우로 향하는 레이저
			if (isMap(x, y - 1, w, h) && (visited[y - 1][x][0] > m + 1)) {
				push(q, &rear, x, y - 1, m + 1, 0);
				visited[y - 1][x][0] = m + 1;
			}

			if (isMap(x, y + 1, w, h) && (visited[y + 1][x][1] > m + 1)) {
				push(q, &rear, x, y + 1, m + 1, 1);
				visited[y + 1][x][1] = m + 1;
			}
		}
	}

	printf("%d",min);
}
int main() {
	int w, h;

	scanf("%d %d", &w, &h);

	map = (char**)malloc(sizeof(char*) * h);

	for (int i = 0; i < h; i++) {
		map[i] = (char*)malloc(sizeof(char) * (w + 1));
	}

	mapsetting(w, h);

	BFS(w, h);
}