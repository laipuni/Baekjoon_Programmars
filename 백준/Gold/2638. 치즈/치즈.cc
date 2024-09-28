#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef struct {
	int x;
	int y;
}element;
int n, m;
int cheese;
int map[MAXSIZE + 1][MAXSIZE + 1];

void push(element* q, int* rear, int x, int y) {
	if (*rear == MAXSIZE * MAXSIZE) {
		printf("q 참");
		exit(1);
	}
	else {
		*rear = *rear + 1;
		(q + (*rear))->x = x;
		(q + (*rear))->y = y;
	}
}
void pop(int* rear, int* front) {
	if (*rear == *front) {
		printf("q 빔");
		exit(1);
	}
	else {
		*front = *front + 1;
	}
}
bool is_Map(int x, int y) {
	if ((0 <= x) && (x < m) && (0 <= y) && (y < n)) {
		return true;
	}

	return false;
}
void findOutAir() {
	int dx[4] = { -1,1,0,0 };
	int dy[4] = { 0,0,-1,1 };
	element* q = (element*)malloc(sizeof(element) * (MAXSIZE * MAXSIZE + 1));
	bool visited[MAXSIZE + 1][MAXSIZE + 1] = { false };
	int rear = -1;
	int front = -1;

	push(q, &rear, 0, 0);
	visited[0][0] = true;
	map[0][0] = -1;

	while (rear != front) {
		pop(&rear, &front);

		int x = (q + front)->x;
		int y = (q + front)->y;

		for (int i = 0; i < 4; i++) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			if (!is_Map(next_x, next_y)) {
				continue;
			}

			if (visited[next_y][next_x] || map[next_y][next_x] == 1) {
				continue;
			}

			map[next_y][next_x] = -1;
			visited[next_y][next_x] = true;
			push(q, &rear, next_x, next_y);
		}
	}

	free(q);
}
element* removeCheese(element* r_q,int* r_rear,int* r_front) {
	int dx[4] = { -1,1,0,0 };
	int dy[4] = { 0,0,-1,1 };
	element* delete_arr = (element*)malloc(sizeof(element) * (MAXSIZE * MAXSIZE + 1));
	element* q = (element*)malloc(sizeof(element) * (MAXSIZE * MAXSIZE + 1));
	int rear = -1;
	int front = -1;
	int idx = 0;

	while (*r_rear != *r_front) {
		pop(r_rear, r_front);

		int x = (r_q + (*r_front))->x;
		int y = (r_q + (*r_front))->y;
		int air = 0;

		for (int i = 0; i < 4; i++) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			if (!is_Map(next_x, next_y)) {
				continue;
			}

			if (map[next_y][next_x] == -1) {
				air++;
			}
		}

		if (air >= 2) {
			delete_arr[idx].x = x;
			delete_arr[idx].y = y;
			idx++;
		}
		else {
			push(q, &rear, x, y);
		}
	}

	cheese -= idx;
	for (int i = 0; i < idx; i++) {
		map[delete_arr[i].y][delete_arr[i].x] = -1;
	}

	*r_rear = rear;
	*r_front = front;
	free(delete_arr);
	free(r_q);
	return q;
}
void input(element* q,int* rear,int*front) {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);

			if (map[i][j] == 1) {
				push(q, rear, j, i);
				cheese++;
			}
		}
	}
}
int solve() {
	element* q = (element*)malloc(sizeof(element) * (MAXSIZE * MAXSIZE + 1));
	int rear = -1;
	int front = -1;
	int time = 0;

	input(q, &rear, &front);

	while (cheese > 0) {
		time++;
		findOutAir();
		q = removeCheese(q, &rear, &front);
	}

	return time;
}
int main() {
	printf("%d", solve());
}