#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAXSIZE 10000
#define MIN(a,b)a<b?a:b
typedef struct Link{
	int num;
	struct Link* next;
}Link;
typedef struct {
	Link* next;
	Link* last;
}Graph;
int top = -1;
int setsize,id;
int d[MAXSIZE + 1];
int stack[MAXSIZE + 1];
Graph g[MAXSIZE + 1];
Graph SCC[MAXSIZE+1];
bool visited[MAXSIZE + 1];

void append(int v1, int v2) {
	Link* newnode = (Link*)malloc(sizeof(Link));
	newnode->num = v2;
	newnode->next = NULL;

	if (g[v1].next == NULL) {
		g[v1].last = newnode;
		g[v1].next = newnode;
	}
	else {
		Link* ptr = g[v1].last;

		ptr->next = newnode;
		g[v1].last = newnode;
	}
}
Link* insert(Link* scc, int n) {
	Link* newnode = (Link*)malloc(sizeof(Link));
	newnode->num = n;
	newnode->next = NULL;

	if (scc == NULL) {
		scc = newnode;
	}
	else {
		Link* ptr = scc;

		if (ptr->num > n) {
			newnode->next = ptr;
			return newnode;
		}

		while (ptr->next != NULL) {
			if (ptr->next->num > n) {
				newnode->next = ptr->next;
				ptr->next = newnode;
				break;
			}

			ptr = ptr->next;
		}

		if (ptr->next == NULL) {
			ptr->next = newnode;
		}
	}

	return scc;
}
int DFS(int n) {
	id++;
	d[n] = id;
	stack[++top] = n;

	int parent = d[n];
	Link* ptr = g[n].next;
	while (ptr != NULL) {
		if (d[ptr->num] == 0) {
			//아직 방문도 안한 이웃
			int temp = DFS(ptr->num);
			parent = MIN(parent, temp);
		}
		else if(!visited[ptr->num]) {
			//지금 노드와 이웃이고 작업중인 경우
			parent = MIN(parent, d[ptr->num]);
		}

		ptr = ptr->next;
	}

	if (parent == d[n]) {
		//집합에서 자신이 부모일 경우
		Link* scc = NULL;

		while (1) {
			int temp = stack[top--];
			scc = insert(scc, temp);
			visited[temp] = true;

			if (temp == n) 
				break;
		}

		setsize++;
		SCC[scc->num].next = scc;
	}

	return parent;
}
int main() {
	int v, e;
	int v1, v2;

	scanf("%d %d", &v, &e);

	for (int i = 0; i < e; i++) {
		scanf("%d %d", &v1, &v2);

		append(v1, v2);
	}

	for (int i = 1; i <= v; i++) {
		if (!visited[i]) {
			DFS(i);
		}
	}

	printf("%d\n", setsize);

	for (int i = 0; i <= v; i++) {
		Link* ptr = SCC[i].next;

		if (SCC[i].next == NULL) {
			continue;
		}

		while (ptr != NULL) {
			printf("%d ", ptr->num);
			ptr = ptr->next;
		}
		printf("-1\n");
	}
}