#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#define MAXSIZE 100000
typedef struct {
	int pos;
	int v;
}pos;
typedef struct {
	int v1;
	int v2;
	int dis;
}element;
typedef struct {
	int size;
	element h[3 * MAXSIZE];
}heap;
int n;
pos planet_x[MAXSIZE + 1];
pos planet_y[MAXSIZE + 1];
pos planet_z[MAXSIZE + 1];
int parent[MAXSIZE + 1];

int find(int x) {
	if (x == parent[x]) {
		return x;
	}

	return parent[x] = find(parent[x]);
}
int cmp(const void* a, const void* b) {
	pos x = *(pos*)a;
	pos y = *(pos*)b;

	if (x.pos > y.pos) {
		return 1;
	}
	else if (x.pos < y.pos) {
		return -1;
	}
	else {
		return 0;
	}
}
void push(heap* h, int v1, int v2, int dis) {
	h->size++;
	int child = h->size;
	int parent = child / 2;

	while (child != 1 && (dis < h->h[parent].dis)) {
		h->h[child] = h->h[parent];
		child = parent;
		parent = child / 2;
	}

	h->h[child].v1 = v1;
	h->h[child].v2 = v2;
	h->h[child].dis = dis;
}
void pop(heap* h) {
	element temp = h->h[h->size--];
	int parent = 1;
	int child = 2;

	while (child <= h->size) {
		if (child < h->size && (h->h[child].dis > h->h[child + 1].dis)) {
			child++;
		}

		if (temp.dis <= h->h[child].dis) {
			break;
		}
		else {
			h->h[parent] = h->h[child];
			parent = child;
			child = parent * 2;
		}
	}

	h->h[parent] = temp;
}
void input() {
	scanf("%d", &n);

	int x, y, z;
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &x, &y, &z);

		planet_x[i].pos = x;
		planet_x[i].v = i+1;

		planet_y[i].pos = y;
		planet_y[i].v = i+1;

		planet_z[i].pos = z;
		planet_z[i].v = i+1;
	}
}
void putHeapDistance(heap* h) {
	qsort(planet_x, n, sizeof(pos), cmp);
	qsort(planet_y, n, sizeof(pos), cmp);
	qsort(planet_z, n, sizeof(pos), cmp);
	

	//힙에 x좌표 넣기
	for (int i = 0; i < n - 1; i++) {
		int dis = abs(planet_x[i].pos - planet_x[i + 1].pos);
		int v1 = planet_x[i].v;
		int v2 = planet_x[i + 1].v;

		push(h, v1, v2, dis);
	}

	//y좌표 넣기
	for (int i = 0; i < n - 1; i++) {
		int dis = abs(planet_y[i].pos - planet_y[i + 1].pos);
		int v1 = planet_y[i].v;
		int v2 = planet_y[i + 1].v;

		push(h, v1, v2, dis);
	}

	//z좌표 넣기
	for (int i = 0; i < n - 1; i++) {
		int dis = abs(planet_z[i].pos - planet_z[i + 1].pos);
		int v1 = planet_z[i].v;
		int v2 = planet_z[i + 1].v;

		push(h, v1, v2, dis);
	}
}
void initParent() {
	//부모 초기화
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}
}
heap* initHeap() {
	heap* h = (heap*)malloc(sizeof(heap));
	h->size = 0;

	return h;
}
int kruskal(heap* h) {
	int sum = 0;
	int line = 0;

	while (line < n - 1 && h->size > 0) {
		//최소 스패닝 트리의 간선 개수는 항상 n-1(노드 개수 - 1)
		element temp = h->h[1];
		pop(h);
		
		int x = find(temp.v1);
		int y = find(temp.v2);

		if (x != y) {
			parent[y] = x;
			line++;
			sum += temp.dis;
		}
	}

	return sum;
}
int main() {
	heap* h = initHeap();

	input();

	initParent();

	putHeapDistance(h);

	printf("%d", kruskal(h));
}