#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAXSIZE 20000
#define RED 1
#define BLUE -1
typedef struct Link{
	int num;
	struct Link* next;
}Link;
typedef struct {
	Link* next;
	Link* last;
}Graph;
int colors[MAXSIZE + 1];

void append(Graph* g, int n) {
	Link* newnode = (Link*)malloc(sizeof(Link));
	newnode->num = n;
	newnode->next = NULL;

	if (g->next == NULL) {
		g->next = newnode;
		g->last = newnode;
	}
	else {
		Link* ptr = g->last;

		ptr->next = newnode;
		g->last = newnode;
	}
}
bool DFS(Graph* g,int n) {
	Link* ptr = (g + n)->next;
	bool res = true;

	while (ptr != NULL) {
		if (colors[ptr->num] == colors[n]) {
			return false;
		}

		if (colors[ptr->num] == 0) {
			colors[ptr->num] = -colors[n];
			res = DFS(g, ptr->num);
		}

		if (!res) {
			return res;
		}

		ptr = ptr->next;
	}

	return true;
}
Graph* makeGraph(int v) {
	Graph* g = (Graph*)malloc(sizeof(Graph) * (v + 1));

	for (int i = 0; i <= v; i++) {
		(g + i)->next = NULL;
	}

	return g;
}
void Reset(int n) {
	for (int i = 0; i <= n; i++) {
		colors[i] = 0;
	}
}
void solve() {
	int v, e;
	int v1, v2;
	scanf("%d %d", &v, &e);

	Reset(v);
	Graph* g = makeGraph(v);

	for (int i = 0; i < e; i++) {
		scanf("%d %d", &v1, &v2);

		append((g + v1), v2);
		append((g + v2), v1);
	}

	for (int i = 1; i <= v; i++) {
		if (colors[i] != 0) {
			continue;
		}

		colors[i] = RED;

		if (!DFS(g, i)) {
			printf("NO\n");
			return;
		}
	}

	printf("YES\n");
}
int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		solve();
	}
}