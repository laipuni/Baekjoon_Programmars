#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX_MAP 200
#define MAX_HORCE 30
#define MAX_Q 2000000
typedef struct {
	short x;
	short y;
	short count;
	short horse;
}element;
int w, h, k;
int map[MAX_MAP + 1][MAX_MAP + 1];
bool visited[MAX_HORCE + 1][MAX_MAP + 1][MAX_MAP + 1];

void push(element* q,int* rear, int x, int y, int count ,int horse) {
	if (*rear == MAX_Q) {
		printf("큐 꽉참");
		exit(1);
	}
	else {
		*rear = *rear + 1;
		(q + (*rear))->x = x;
		(q + (*rear))->y = y;
		(q + (*rear))->count = count;
		(q + (*rear))->horse = horse;
	}
}
void pop(int* rear, int* front) {
	if (*rear == *front) {
		printf("큐 빔");
		exit(1);
	}
	else {
		*front = *front + 1;
	}
}
bool is_map(int x, int y) {
	return ((0 <= x) && (x < w) && (0 <= y) && (y < h)) ? true : false;
}
int BFS() {
	int dx[4] = { -1,1,0,0 };
	int dy[4] = { 0,0,-1,1 };
	int horse_dx[8] = { -2,-1,1,2,2,1,-1,-2 };
	int horse_dy[8] = { -1,-2,-2,-1,1,2,2,1 };

	element* q = (element*)malloc(sizeof(element) * (MAX_Q));
	int rear = -1;
	int front = -1;

	push(q, &rear, 0, 0, 0, 0);
	visited[0][0][0] = true;

	while (rear != front) {
		pop(&rear, &front);

		int x = (q + front)->x;
		int y = (q + front)->y;
		int count = (q + front)->count;
		int horse = (q + front)->horse;

		for (int i = 0; i < 4; i++) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			if (!is_map(next_x, next_y)) {
				continue;
			}

			if (visited[horse][next_y][next_x] || map[next_y][next_x] == 1) {
				continue;
			}

			if (next_x == w - 1 && next_y == h - 1) {
				return count + 1;
			}

			visited[horse][next_y][next_x] = true;
			push(q, &rear, next_x, next_y, count + 1, horse);
		}

		if (horse >= k) {
			continue;
		}

		for (int i = 0; i < 8; i++) {
			int next_x = x + horse_dx[i];
			int next_y = y + horse_dy[i];

			if (!is_map(next_x, next_y)) {
				continue;
			}

			if (visited[horse + 1][next_y][next_x] || map[next_y][next_x] == 1) {
				continue;
			}

			if (next_x == w - 1 && next_y == h - 1) {
				return count + 1;
			}

			visited[horse + 1][next_y][next_x] = true;
			push(q, &rear, next_x, next_y, count + 1, horse + 1);
		}
	}

	return -1;
}
void input() {
	scanf("%d %d %d", &k, &w, &h);

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			scanf("%d", &map[i][j]);
		}
	}
}
int main() {
	input();

	if (w == 1 && h == 1) {
		printf("0");
	}
	else {
		printf("%d", BFS());
	}
}