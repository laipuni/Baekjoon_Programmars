#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100000
typedef struct Link{
	int n;
	struct Link* next;
}Link;
typedef struct {
	Link* next;
	Link* last;
}Graph;
int n, m;
int dp[MAXSIZE+1];
Graph graph[MAXSIZE + 1];

void append(int v1, int v2) {
	Link* newnode = (Link*)malloc(sizeof(Link));
	newnode->n = v2;
	newnode->next = NULL;

	if (graph[v1].next == NULL) {
		graph[v1].next = newnode;
		graph[v1].last = newnode;
	}
	else {
		Link* ptr = graph[v1].last;

		ptr->next = newnode;
		graph[v1].last = newnode;
	}
}
void DFS(int num) {
	Link* ptr = graph[num].next;
	while (ptr != NULL) {
		dp[ptr->n] += dp[num];
		DFS(ptr->n);

		ptr = ptr->next;
	}
}
void input() {
	int ans;
	scanf("%d %d", &n, &m);

	scanf("%d", &ans);

	for (int i = 2; i <= n; i++) {
		scanf("%d", &ans);
		append(ans, i);
	}

	int p, w;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &p, &w);

		dp[p] += w;
	}
}
void print() {
	for (int i = 1; i <= n; i++) {
		printf("%d ", dp[i]);
	}
}
int main() {
	input();

	DFS(1);

	print();
}