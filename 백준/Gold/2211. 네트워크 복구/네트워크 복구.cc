#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAXSIZE 1000
#define INF 1.0e+9
typedef struct Link {
	short num;
	short weight;
	struct Link* next;
}Link;
typedef struct {
	Link* next;
	Link* last;
}Graph;
typedef struct {
	short v1;
	short v2;
	short weight;
}element;
typedef struct {
	int size;
	element heap[MAXSIZE + 1];
}heap;
int path[MAXSIZE + 1];
int dis[MAXSIZE + 1];
bool visited[MAXSIZE + 1];
Graph g[MAXSIZE + 1];

void append(int v1, int v2,int w) {
	Link* newnode = (Link*)malloc(sizeof(Link));
	newnode->num = v2;
	newnode->weight = w;
	newnode->next = NULL;

	if (g[v1].next == NULL) {
		g[v1].next = newnode;
		g[v1].last = newnode;
	}
	else {
		Link* ptr = g[v1].last;

		ptr->next = newnode;
		g[v1].last = newnode;
	}
}
void push(heap* h, element temp) {
	h->size++;
	int child = h->size;
	int parent = child / 2;

	while (child != 1 && (temp.weight < h->heap[parent].weight)) {
		h->heap[child] = h->heap[parent];
		child = parent;
		parent = child / 2;
	}

	h->heap[child] = temp;
}
void pop(heap* h) {
	element temp = h->heap[h->size--];
	int parent = 1;
	int child = 2;

	while (child <= h->size) {
		if (child < h->size && (h->heap[child].weight > h->heap[child + 1].weight)) {
			child++;
		}

		if (temp.weight <= h->heap[child].weight) {
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
heap* HeapReset() {
	heap* h = (heap*)malloc(sizeof(heap));
	h->size = 0;

	return h;
}
void daikstra(int n, int m) {
	heap* h = HeapReset();

	element temp = { 1,1,0 };
	push(h, temp);

	while(h->size !=0) {
		temp = h->heap[1];
		pop(h);

		if (dis[temp.v2] < temp.weight) {
			continue;
		}

		path[temp.v2] = temp.v1;
		visited[temp.v2] = true;

		Link* ptr = g[temp.v2].next;
		while (ptr != NULL) {
			int next = ptr->weight + temp.weight;

			if (dis[ptr->num] > next && !visited[ptr->num]) {
				element next_temp = { temp.v2, ptr->num, next };

				dis[ptr->num] = next;
				push(h,next_temp);
			}

			ptr = ptr->next;
		}
	}

	printf("%d\n", n - 1);
	for (int i = 2; i <= n; i++) {
		printf("%d %d\n", i, path[i]);
	}
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 2; i <= n; i++) {
		dis[i] = INF;
	}

	int v1, v2, w;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &v1, &v2, &w);

		append(v1, v2, w);
		append(v2, v1, w);
	}

	daikstra(n, m);
}