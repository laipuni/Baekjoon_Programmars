#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#define MAXSIZE 100
#define MAX_Q 100000
typedef struct {
	short x;
	short y;
	short count;
	short dir;
}element;
int n, m;
int start_x, start_y, start_dir;
int end_x, end_y, end_dir;
int map[MAXSIZE + 1][MAXSIZE + 1];
bool visited[5][MAXSIZE + 1][MAXSIZE + 1];

void push(element* q, int* rear, int x, int y, int count, int dir) {
	if (*rear == MAX_Q) {
		printf("큐 꽉참");
		exit(1);
	}
	else {
		*rear = *rear + 1;
		(q + (*rear))->x = x;
		(q + (*rear))->y = y;
		(q + (*rear))->count = count;
		(q + (*rear))->dir = dir;
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
	return ((0 <= x) && (x < m) && (0 <= y) && (y < n)) ? true : false;
}
int BFS() {
	int dir_x[4] = { 1,-1,0,0 };
	int dir_y[4] = { 0,0,1,-1 };

	element* q = (element*)malloc(sizeof(element) * (MAX_Q));
	int rear = -1;
	int front = -1;

	push(q, &rear, start_x - 1, start_y - 1, 0, start_dir);
	visited[start_dir][start_y - 1][start_x - 1] = true;

	while (rear != front) {
		pop(&rear, &front);

		int x = (q + front)->x;
		int y = (q + front)->y;
		int count = (q + front)->count;
		int dir = (q + front)->dir;

		if (x == end_x - 1 && y == end_y - 1 && dir == end_dir) {
			return count;
		}

		if (dir == 1 || dir == 2) {
			//동, 서
			if (!visited[3][y][x]) {
				visited[3][y][x] = true;
				push(q, &rear, x, y, count + 1, 3);
			}

			if (!visited[4][y][x]) {
				visited[4][y][x] = true;
				push(q, &rear, x, y, count + 1, 4);
			}
		}
		else {
			if (!visited[1][y][x]) {
				visited[1][y][x] = true;
				push(q, &rear, x, y, count + 1, 1);
			}

			if (!visited[2][y][x]) {
				visited[2][y][x] = true;
				push(q, &rear, x, y, count + 1, 2);
			}
		}

		for (int i = 1; i <= 3; i++) {
			int next_x = x + dir_x[dir - 1] * i;
			int next_y = y + dir_y[dir - 1] * i;

			if (!is_map(next_x, next_y)) {
				continue;
			}

			if (visited[dir][next_y][next_x]) {
				continue;
			}

			if (map[next_y][next_x] == 1) {
				break;
			}

			visited[dir][next_y][next_x] = true;
			push(q, &rear, next_x, next_y, count + 1, dir);
		}
	}
}
void input(){
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	scanf("%d %d %d", &start_y, &start_x, &start_dir);
	scanf("%d %d %d", &end_y, &end_x, &end_dir);
}
int main() {
	input();

	printf("%d", BFS());
}