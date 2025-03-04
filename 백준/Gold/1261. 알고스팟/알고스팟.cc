#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAXSIZE 10000
typedef struct {
	int x;
	int y;
	int count;
}element;
typedef struct {
	int size;
	element heap[MAXSIZE];
}heap;
char map[100][101];
int n, m;//x,y

void push(heap* h, int x, int y, int count) {
	h->size++;
	int child = h->size;
	int parent = child / 2;

	while ((child != 1) && (count < h->heap[parent].count)) {
		h->heap[child] = h->heap[parent];
		child = parent;
		parent = child / 2;
	}

	h->heap[child].x = x;
	h->heap[child].y = y;
	h->heap[child].count = count;
}
void pop(heap* h) {
	element temp = h->heap[h->size--];
	int parent = 1;
	int child = 2;

	while (child <= h->size) {
		if ((child < h->size) && (h->heap[child].count > h->heap[child + 1].count)) {
			child++;
		}

		if (h->heap[child].count >= temp.count) {
			break;
		}
		else {
			h->heap[parent] = h->heap[child];
			parent = child;
			child = parent * 2;
		}
	}

	h->heap[parent] = temp;
}
bool isMap(int x, int y) {
	if ((0 <= x) && (x < n) && (0 <= y) && (y < m)) {
		return true;
	}
	else {
		return false;
	}
}
void input() {
	for (int i = 0; i < m; i++) {
		scanf("%s", map[i]);
		getchar();
	}
}
void solve() {
	int dx[4] = { -1,1,0,0 };
	int dy[4] = { 0,0,-1,1 };
	bool visited[100][100] = { false };
	heap* h = (heap*)malloc(sizeof(heap));
	h->size = 0;

	push(h, 0, 0, 0);

	while (h->size != 0) {
		element temp = h->heap[1];
		pop(h);

		if ((temp.x == (n - 1)) && (temp.y == (m - 1))) {
			printf("%d", temp.count);
			return;
		}

		for (int i = 0; i < 4; i++) {
			int next_x = temp.x + dx[i];
			int next_y = temp.y + dy[i];

			if (isMap(next_x, next_y)) {
				if (!visited[next_y][next_x]) {
					visited[next_y][next_x] = true;

					if (map[next_y][next_x] == '0') {
						push(h, next_x, next_y, temp.count);
					}
					else if (map[next_y][next_x] == '1') {
						push(h, next_x, next_y, temp.count + 1);
					}
				}
			}
		}

	}

	printf("못가는데여");

}
int main() {
	scanf("%d %d", &n, &m);

	input();

	solve();
}