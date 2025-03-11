#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAX_MAPSIZE 500
typedef struct {
	short x;
	short y;
	int num;//타일 번호 변수
	int count;//타일 이동횟수 변수
	int parent;//이전에 방문한 노드를 담는 변수
}element;
int n;
short map[MAX_MAPSIZE][2*MAX_MAPSIZE];
bool visited[MAX_MAPSIZE][2*MAX_MAPSIZE];

void push(element* q, short x, short y,int num, int count,int parent, int* rear) {
	if (*rear == 2*MAX_MAPSIZE*MAX_MAPSIZE) {
		printf("큐 참");
		exit(1);
	}
	else {
		*rear = *rear + 1;
		(q + (*rear))->x = x;
		(q + (*rear))->y = y;
		(q + (*rear))->count = count;
		(q + (*rear))->num = num;
		(q + (*rear))->parent = parent;
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
bool isMap(int x, int y) {
	if ((0 <= x) && (x < 2*n) && (0 <= y) && (y < n)) {
		return true;
	}

	return false;
}
void input() {
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			//홀수 줄은 0부터 시작해서 2*n까지 받는다.
			for (int j = 0; j < 2*n; j+=2) {
				scanf("%d %d", &map[i][j], &map[i][j + 1]);
			}
		}
		else {
			//홀수 줄은 1부터 시작해서 2*n-1까지 받는다.
			for (int j = 1; j < 2*n - 1; j += 2) {
				scanf("%d %d", &map[i][j], &map[i][j + 1]);
			}
		}
	}
}
void move(element* q,int *rear,int *front,int num,int count,int dir,int x,int y) {
	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { -1,0,1,0 };
	int next_x = x + dx[dir];
	int next_y = y + dy[dir];

	if (dir == 0) {
		//상 방향으로 이동할 때
		if (map[next_y][next_x] != map[y][x]) {
			return;
		}

		int temp = num - n;
		if (y % 2 == 0) {
			if (x % 2 == 1) {
				//타일 뒷 부분 일 경우, 짝수 행일 경우
				push(q, next_x, next_y, temp + 1, count + 1, *front, rear);
				push(q, next_x + 1, next_y, temp + 1, count + 1, *front, rear);
				visited[next_y][next_x] = true;
				visited[next_y][next_x + 1] = true;
			}
			else {
				push(q, next_x, next_y, temp, count + 1, *front, rear);
				push(q, next_x - 1, next_y, temp, count + 1, *front, rear);
				visited[next_y][next_x] = true;
				visited[next_y][next_x - 1] = true;
			}
		}
		else {
			if (x % 2 == 0) {
				//타일 뒷 부분 일 경우, 홀수 행일 경우
				push(q, next_x, next_y, temp + 1, count + 1, *front, rear);
				push(q, next_x + 1, next_y, temp + 1, count + 1, *front, rear);
				visited[next_y][next_x] = true;
				visited[next_y][next_x + 1] = true;
			}
			else{
				//타일 앞 부분 일 경우, 홀수 행일 경우
				push(q, next_x, next_y, temp, count + 1, *front, rear);
				push(q, next_x - 1, next_y, temp, count + 1, *front, rear);
				visited[next_y][next_x] = true;
				visited[next_y][next_x - 1] = true;
			}
		}

	}
	else if (dir == 2) {
		//하 방향으로 이동할 때
		if (map[next_y][next_x] != map[y][x]) {
			return;
		}

		int temp = num + n;

		if (y % 2 == 0) {
			if (x % 2 == 0) {
				//타일 앞 부분 일 경우, 짝수 행일 경우
				push(q, next_x, next_y, temp - 1, count + 1, *front, rear);
				push(q, next_x - 1, next_y, temp - 1, count + 1, *front, rear);
				visited[next_y][next_x] = true;
				visited[next_y][next_x - 1] = true;
			}
			else {
				push(q, next_x, next_y, temp, count + 1, *front, rear);
				push(q, next_x + 1, next_y, temp, count + 1, *front, rear);
				visited[next_y][next_x] = true;
				visited[next_y][next_x + 1] = true;
			}
		}

		if (y % 2 == 1) {
			if (x % 2 == 1) {
				//타일 앞 부분 일 경우, 홀수 행일 경우
				push(q, next_x, next_y, temp - 1, count + 1, *front, rear);
				push(q, next_x - 1, next_y, temp - 1, count + 1, *front, rear);
				visited[next_y][next_x] = true;
				visited[next_y][next_x - 1] = true;
			}
			else{
				//타일 뒷 부분 일 경우, 홀수 행일 경우
				push(q, next_x, next_y, temp, count + 1, *front, rear);
				push(q, next_x + 1, next_y, temp, count + 1, *front, rear);
				visited[next_y][next_x] = true;
				visited[next_y][next_x + 1] = true;
			}

		}
		
	}
	else if (dir == 1) {
		//우 방향으로 이동할 때
		if(x%2 == 1 && y % 2 == 0) {
			//타일의 끝 부분 짝수 행일 경우
			if (map[next_y][next_x] == map[y][x]) {
				push(q, next_x, next_y, num + 1, count + 1, *front, rear);
				push(q, next_x + 1, next_y, num + 1, count + 1, *front, rear);
				visited[next_y][next_x] = true;
				visited[next_y][next_x + 1] = true;
			}
		}

		if(x%2 == 0 && y % 2 == 1) {
			//타일의 끝 부분 홀수 행일 경우
			if (map[next_y][next_x] == map[y][x]) {
				push(q, next_x, next_y, num + 1, count + 1, *front, rear);
				push(q, next_x + 1, next_y, num + 1, count + 1, *front, rear);
				visited[next_y][next_x] = true;
				visited[next_y][next_x + 1] = true;
			}
		}
	}
	else if (dir == 3) {
		//좌 방향으로 이동할 때
		if(x%2 == 0 && y % 2 == 0) {
			//타일의 첫 부분 짝수 행일 경우
			if (map[next_y][next_x] == map[y][x]) {
				push(q, next_x, next_y, num - 1, count + 1, *front, rear);
				push(q, next_x - 1, next_y, num - 1, count + 1, *front, rear);
				visited[next_y][next_x] = true;
				visited[next_y][next_x - 1] = true;
			}
		}

		if(x%2 == 1 && y % 2 == 1) {
			//타일의 첫 부분 홀수 행일 경우
			if (map[next_y][next_x] == map[y][x]) {
				push(q, next_x, next_y, num - 1, count + 1, *front, rear);
				push(q, next_x - 1, next_y, num - 1, count + 1, *front, rear);
				visited[next_y][next_x] = true;
				visited[next_y][next_x - 1] = true;
			}
		}
		
	}
}
void BFS() {
	//탐색 방향 순서 12시 방향부터 시계방향으로 돌아감(상,우,하,좌)
	int max_num = 0;
	int max_parent, min_count = 987654321;
	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { -1,0,1,0 };
	element* q = (element*)malloc(sizeof(element) * (2*MAX_MAPSIZE * MAX_MAPSIZE + 1));
	int rear = -1;
	int front = -1;


	push(q, 0, 0, 1, 1, -1, &rear);
	push(q, 1, 0, 1, 1, -1, &rear);
	visited[0][0] = true;
	visited[0][1] = true;

	while (rear != front) {
		pop(&rear, &front);

		int x = (q + front)->x;
		int y = (q + front)->y;
		int num = (q + front)->num;
		int count = (q + front)->count;

		if (max_num <= num) {
			if (max_num < num) {
				max_num = num;
				min_count = count;
				max_parent = front;
			}
			else {
				if (min_count > count) {
					min_count = count;
					max_parent = front;
				}
			}
		}

		for (int i = 0; i < 4; i++) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			if (!isMap(next_x, next_y)) {
				continue;
			}

			if (map[next_y][next_x] == 0) {
				//홀수 행은 x좌표로 0,2*n 양쪽이 0이다.
				continue;
			}

			if (visited[next_y][next_x]) {
				continue;
			}

			move(q, &rear, &front, num, count, i, x, y);
		}
	}

	printf("%d\n", min_count);
	int now = (q+max_parent)->parent;
	int now_num = max_num;
	int* result = (int*)malloc(sizeof(int) * (max_parent + 1));
	int idx = 1;
	result[0] = now_num;

	while (now != -1) {
		if (now_num != (q + now)->num) {
			now_num = (q + now)->num;
			result[idx++] = now_num;
		}

		now = (q + now)->parent;
	}

	for (int i = idx - 1; i >= 0; i--) {
		printf("%d ", result[i]);
	}
}
int main() {
	scanf("%d", &n);

	input();

	BFS();
}