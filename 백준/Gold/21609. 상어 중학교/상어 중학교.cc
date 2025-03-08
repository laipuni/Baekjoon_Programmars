#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAXSIZE 20
typedef struct {
	int row;
	int col;
	int size;
	int rainbow;
}Group;
typedef struct {
	int x;
	int y;
}element;
int n, m;
int map[MAXSIZE + 1][MAXSIZE + 1];//-1:검은 공, 0:무지개 공, 1~5:일반 공, 6:빈칸
bool visited[MAXSIZE + 1][MAXSIZE];

void push(element* q, int x, int y, int* rear) {
	if (*rear == MAXSIZE * MAXSIZE) {
		printf("큐 참");
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
		printf("큐 빔");
		exit(1);
	}
	else {
		*front = *front + 1;
	}
}
bool isMap(int x, int y) {
	if ((0 <= x) && (x < n) && (0 <= y) && (y < n)) {
		return true;
	}

	return false;
}
void visitedReset() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = false;
		}
	}
}
void findBFS(int start_x, int start_y, int color, Group* g) {
	int count = 1;
	int dx[4] = { -1,1,0,0 };
	int dy[4] = { 0,0,-1,1 };
	element* stack = (element*)malloc(sizeof(element) * (MAXSIZE * MAXSIZE + 1));//무지개공을 담는 스택
	element* q = (element*)malloc(sizeof(element) * (MAXSIZE * MAXSIZE + 1));
	int rear = -1;
	int front = -1;
	int top = -1;

	push(q, start_x, start_y, &rear);
	visited[start_y][start_x] = true;

	while (rear != front) {
		pop(&rear, &front);

		int x = (q + front)->x;
		int y = (q + front)->y;

		for (int i = 0; i < 4; i++) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			if (!isMap(next_x, next_y)) {
				continue;
			}

			if (map[next_y][next_x] != 0 && map[next_y][next_x] != color) {
				continue;
			}

			if (visited[next_y][next_x]) {
				continue;
			}

			if (map[next_y][next_x] == 0) {
				top++;
				(stack + top)->x = next_x;
				(stack + top)->y = next_y;
			}
			
			count++;
			visited[next_y][next_x] = true;
			push(q, next_x, next_y, &rear);
		}
	}
	g->rainbow = top + 1;
	g->size = count;

	while (top != -1) {
		//무지개공의 방문체크를 false로 바꾸기
		int x = (stack + top)->x;
		int y = (stack + top)->y;
		top--;
		visited[y][x] = false;
	}
}
void removeBFS(int start_x, int start_y, int color) {
	int dx[4] = { -1,1,0,0 };
	int dy[4] = { 0,0,-1,1 };
	bool checked[MAXSIZE + 1][MAXSIZE + 1] = { false };
	element* q = (element*)malloc(sizeof(element) * (MAXSIZE * MAXSIZE + 1));
	int rear = -1;
	int front = -1;

	push(q, start_x, start_y, &rear);
	checked[start_y][start_x] = true;
	map[start_y][start_x] = -2;

	while (rear != front) {
		pop(&rear, &front);

		int x = (q + front)->x;
		int y = (q + front)->y;

		for (int i = 0; i < 4; i++) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			if (!isMap(next_x, next_y)) {
				continue;
			}

			if (map[next_y][next_x] != 0 && map[next_y][next_x] != color) {
				continue;
			}

			if (checked[next_y][next_x]) {
				continue;
			}

			map[next_y][next_x] = -2;
			checked[next_y][next_x] = true;
			push(q, next_x, next_y, &rear);
		}
	}
}
int seleteGroup(Group* g, int group_num) {
	Group* max = (Group*)malloc(sizeof(Group));
	max->col = 0;
	max->row = 0;
	max->rainbow = 0;
	max->size = 0;

	int selete = -1;
	for (int i = 0; i < group_num; i++) {
		if ((g + i)->size < 2) {
			continue;
		}

		if (max->size < (g + i)->size) {
			max = (g + i);
			selete = i;
			continue;
		}

		if (max->size > (g + i)->size) {
			continue;
		}

		if (max->rainbow < (g + i)->rainbow) {
			max = (g + i);
			selete = i;
			continue;
		}

		if (max->rainbow > (g + i)->rainbow) {
			continue;
		}

		if (max->row < (g + i)->row) {
			max = (g + i);
			selete = i;
			continue;
		}

		if (max->row == (g + i)->row && max->col < (g + i)->col) {
			max = (g + i);
			selete = i;
			continue;
		}
	}

	return selete;
}
int findGroup() {
	int group_num = 0;
	Group* g = (Group*)malloc(sizeof(Group) * (MAXSIZE * MAXSIZE + 1));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] > 0 && !visited[i][j] && map[i][j] != -2) {
				(g + group_num)->col = j;
				(g + group_num)->row = i;
				findBFS(j, i, map[i][j], (g + group_num));
				group_num++;
			}
		}
	}

	visitedReset();//방문 체크배열을 초기화

	int selete = seleteGroup(g, group_num);

	if (selete == -1) {
		//조건에 만족하는 블록그룹이 없는 경우
		return -1;
	}

	int color = map[(g + selete)->row][(g + selete)->col];

	removeBFS((g + selete)->col, (g + selete)->row, color);

	return (g + selete)->size * (g + selete)->size;
}
void rotation() {
	int temp[MAXSIZE + 1][MAXSIZE + 1];//회전한 map을 잠시 저장할 배열

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp[n - j - 1][i] = map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = temp[i][j];
		}
	}
}
void gravity() {
	int* q = (int*)malloc(sizeof(int) * (MAXSIZE + 1));

	for (int i = 0; i < n; i++) {
		int rear = -1;
		int front = -1;
		int search = n - 1;
		int current = n - 1;

		while (search >= 0) {
			//큐에 담는 반복문
			while (search >= 0) {
				if (map[search][i] == -1) {
					//검은 공을 만나면 종료
					search--;
					break;
				}

				if (map[search][i] != -2) {
					//빈칸이 아닐 경우(빈칸은 -2)
					rear++;
					q[rear] = map[search][i];
					map[search][i] = -2;
				}

				search--;
			}

			//큐에 담긴 공들을 아래칸으로 옮기는 반복문
			while (rear != front) {
				front++;
				map[current--][i] = q[front];
			}

			current = search;
		}
	}
}
int solve() {
	int sum = 0;

	while (1) {
		int res = findGroup();
		if (res == -1) {
			return sum;
		}
		sum += res;

		gravity();
		rotation();
		gravity();

	}
}
void input() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
}
int main() {
	scanf("%d %d", &n, &m);
	input();
	printf("%d", solve());
}