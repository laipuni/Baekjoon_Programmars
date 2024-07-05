#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20
#define MAX(a,b)a>b?a:b
int map[6][MAXSIZE][MAXSIZE];
int max;
int size;

void push(int* q, int* rear, int num) {
	if (*rear == MAXSIZE) {
		printf("큐 가득참");
		exit(1);
	}
	else {
		*rear = *rear + 1;
		q[*rear] = num;
	}
}
void pop(int* rear,int*front) {
	if (*rear == *front) {
		printf("큐 비었당");
		exit(1);
	}
	else {
		*front = *front + 1;
	}
}
void up(int n) {
	int q[20];
	int rear = -1;
	int front = -1;

	for (int x = 0; x < size; x++) {
		for (int y = 0; y < size; y++) {
			if (map[n - 1][y][x] != 0) {
				push(q, &rear, map[n - 1][y][x]);
			}
			map[n][y][x] = 0;
		}

		if (rear == -1) {
			continue;
		}

		int pos = 0;
		while (rear != front) {
			pop(&rear, &front);
			if (map[n][pos][x] == q[front]) {
				map[n][pos][x] += q[front];
				max = MAX(max, map[n][pos][x]);
				pos++;
			}
			else if(map[n][pos][x] == 0){
				map[n][pos][x] = q[front];
				max = MAX(max, map[n][pos][x]);
			}
			else {
				pos++;
				map[n][pos][x] = q[front];
				max = MAX(max, map[n][pos][x]);
			}
		}

		rear = -1;
		front = -1;
	}
}
void right(int n) {
	int q[20];
	int rear = -1;
	int front = -1;

	for (int y = 0; y < size; y++) {
		for (int x = size - 1; x >= 0; x--) {
			if (map[n - 1][y][x] != 0) {
				push(q, &rear, map[n - 1][y][x]);
			}
			map[n][y][x] = 0;
		}

		if (rear == -1) {
			continue;
		}

		int pos = size - 1;
		while (rear != front) {
			pop(&rear, &front);
			if (map[n][y][pos] == q[front]) {
				map[n][y][pos] *= 2;
				max = MAX(max, map[n][y][pos]);
				pos--;
			}
			else if (map[n][y][pos] == 0) {
				map[n][y][pos] = q[front];
				max = MAX(max, map[n][y][pos]);
			}
			else {
				pos--;
				map[n][y][pos] = q[front];
				max = MAX(max, map[n][y][pos]);
			}
		}

		rear = -1;
		front = -1;
	}
}
void down(int n) {
	int q[20];
	int rear = -1;
	int front = -1;

	for (int x = 0; x < size; x++) {
		for (int y = size - 1; y >= 0; y--) {
			if (map[n - 1][y][x] != 0) {
				push(q, &rear, map[n - 1][y][x]);
			}
			map[n][y][x] = 0;
		}

		if (rear == -1) {
			continue;
		}

		int pos = size - 1;

		while (rear != front) {
			pop(&rear, &front);
			if (map[n][pos][x] == q[front]) {
				map[n][pos][x] *= 2;
				max = MAX(max, map[n][pos][x]);
				pos--;
			}
			else if (map[n][pos][x] == 0) {
				map[n][pos][x] = q[front];
				max = MAX(max, map[n][pos][x]);
			}
			else {
				pos--;
				map[n][pos][x] = q[front];
				max = MAX(max, map[n][pos][x]);
			}
		}

		rear = -1;
		front = -1;
	}
}
void left(int n) {
	int q[20];
	int rear = -1;
	int front = -1;

	for (int y = 0; y < size; y++) {
		for (int x = 0; x < size; x++) {
			if (map[n - 1][y][x] != 0) {
				push(q, &rear, map[n - 1][y][x]);
			}
			map[n][y][x] = 0;
		}

		if (rear == -1) {
			continue;
		}

		int pos = 0;

		while (rear != front) {
			pop(&rear, &front);
			if (map[n][y][pos] == q[front]) {
				map[n][y][pos] *= 2;
				max = MAX(max, map[n][y][pos]);
				pos++;
			}
			else if (map[n][y][pos] == 0) {
				map[n][y][pos] = q[front];
				max = MAX(max, map[n][y][pos]);
			}
			else {
				pos++;
				map[n][y][pos] = q[front];
				max = MAX(max, map[n][y][pos]);
			}
		}

		rear = -1;
		front = -1;
	}
}
void DFS(int depth) {
	if (depth >= 5) {
		return;
	}

	up(depth+1);
	DFS(depth + 1);

	right(depth+1);
	DFS(depth + 1);

	down(depth+1);
	DFS(depth + 1);

	left(depth+1);
	DFS(depth + 1);
}
void input() {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			scanf("%d", &map[0][i][j]);
		}
	}
}
int main() {
	scanf("%d", &size);

	input();

	DFS(0);

	printf("%d", max);
}