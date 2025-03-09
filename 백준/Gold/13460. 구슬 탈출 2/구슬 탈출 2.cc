#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAXSIZE 1000000
typedef struct {
	int x;
	int y;
}pos;
typedef struct {
	pos r;//빨간 구슬
	pos b;//파란 구슬
	int count;//횟수
}element;
char map[10][11];
bool visited[10][10][10][10]; // y1,x1,y2,x2

void push(element* q, pos r, pos b,int count,int* rear) {
	if (*rear == MAXSIZE) {
		printf("큐 가득참");
		exit(1);
	}
	else {
		*rear = *rear + 1;
		(q + (*rear))->r = r;
		(q + (*rear))->b = b;
		(q + (*rear))->count = count;
	}
}
void pop(int* rear, int* front) {
	if (*rear == *front) {
		printf("큐 비었음");
		exit(1);
	}
	else {
		*front = *front + 1;
	}
}
bool move(pos* moveball, pos otherball, int dirx, int diry) {
	while ((map[moveball->y + diry][moveball->x + dirx] != '#') && (moveball->x + dirx != otherball.x || moveball->y + diry != otherball.y)) {
		moveball->x += dirx;
		moveball->y += diry;

		if (map[moveball->y][moveball->x] == 'O') {
			moveball->x = 0;
			moveball->y = 0;
			return true;
		}
	}

	return false;
}
void BFS(pos r, pos b) {
	pos dir[4] = { {0,-1},{1,0},{0,1},{-1,0} };//상,좌,하,우 {y,x}
	element* q = (element*)malloc(sizeof(element) * (MAXSIZE + 1));
	int rear = -1;
	int front = -1;

	push(q, r, b, 0, &rear);

	while (rear != front) {
		pop(&rear, &front);
		pos red = (q + front)->r;
		pos blue = (q + front)->b;
		int count = (q + front)->count;

		if (count >= 10) {
			break;
		}

		for (int i = 0; i < 4; i++) {
			pos nextred = red;
			pos nextblue = blue;
			bool redGoalin = false;
			bool blueGoalin = false;
			switch (i) {
				case 0:
					//상 y좌표 비교 후 작은 y좌표를 가진 공이 먼저 움직임
					if (red.y < blue.y) {
						redGoalin = move(&nextred, nextblue, dir[i].x, dir[i].y);
						blueGoalin = move(&nextblue, nextred, dir[i].x, dir[i].y);
					}
					else {
						blueGoalin = move(&nextblue, nextred, dir[i].x, dir[i].y);
						redGoalin = move(&nextred, nextblue, dir[i].x, dir[i].y);
					}
					break;
				case 1:
					if (red.x > blue.x) {
						redGoalin = move(&nextred, nextblue, dir[i].x, dir[i].y);
						blueGoalin = move(&nextblue, nextred, dir[i].x, dir[i].y);
					}
					else {
						blueGoalin = move(&nextblue, nextred, dir[i].x, dir[i].y);
						redGoalin = move(&nextred, nextblue, dir[i].x, dir[i].y);
					}
					break;
				case 2:
					if (red.y > blue.y) {
						redGoalin = move(&nextred, nextblue, dir[i].x, dir[i].y);
						blueGoalin = move(&nextblue, nextred, dir[i].x, dir[i].y);
					}
					else {
						blueGoalin = move(&nextblue, nextred, dir[i].x, dir[i].y);
						redGoalin = move(&nextred, nextblue, dir[i].x, dir[i].y);
					}
					break;
				case 3:
					if (red.x < blue.x) {
						redGoalin = move(&nextred, nextblue, dir[i].x, dir[i].y);
						blueGoalin = move(&nextblue, nextred, dir[i].x, dir[i].y);
					}
					else {
						blueGoalin = move(&nextblue, nextred, dir[i].x, dir[i].y);
						redGoalin = move(&nextred, nextblue, dir[i].x, dir[i].y);
					}
					break;
			}

			if (redGoalin && !blueGoalin) {
				//빨간 공만 들어간 경우
				printf("%d", count + 1);
				return;
			}

			if (visited[nextred.y][nextred.x][nextblue.y][nextblue.x]) {
				continue;
			}
			else if (!redGoalin && !blueGoalin) {
				//둘다 구멍에 못 들어간 경우
				visited[nextred.y][nextred.x][nextblue.y][nextblue.x] = true;
				push(q, nextred, nextblue, count + 1, &rear);
			}
		}
	}

	printf("-1");
}
void input(int n,int m,pos* r, pos* b) {
	for (int i = 0; i < n; i++) {
		scanf("%s", map[i]);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 'R') {
				r->x = j;
				r->y = i;
			}

			if (map[i][j] == 'B') {
				b->x = j;
				b->y = i;
			}
		}
	}
}
int main() {
	int n, m;
	pos r;
	pos b;

	scanf("%d %d", &n, &m);

	input(n, m, &r, &b);

	BFS(r, b);
}
