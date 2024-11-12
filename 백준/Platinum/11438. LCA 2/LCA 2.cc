#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAXSIZE 100000
#define SWAP(a,b,t)(t = a, a = b, b = t)
typedef struct Link {
	int num;
	struct Link* next;
}Link;
typedef struct {
	Link* next;
	Link* last;
}Graph;
Graph g[MAXSIZE + 1] = { NULL };
int parent[MAXSIZE + 1][18]; // log2(100000) = 16.69....
bool visited[MAXSIZE + 1];
int level[MAXSIZE + 1];
int max_level;

void push(int* q, int num, int* rear) {
	if (*rear == MAXSIZE) {
		printf("큐 참");
		exit(1);
	}
	else {
		*rear = *rear + 1;
		q[*rear] = num;
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
void append(int v1, int v2) {
	Link* newnode = (Link*)malloc(sizeof(Link));
	newnode->num = v2;
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
int LCA(int v1, int v2) {
	if (level[v1] < level[v2]) {
		int temp;
		SWAP(v1, v2, temp);
	}

	/*
	높이가 똑같아야 root노드 부터 내려가면서 확인 할 수 있다.
	우리는 parent[node][k] = node 2^k번째 부모를 저장 했다.
	예를 들면 13일 경우 1, 4, 8로 2^0 , 2^2, 2^3이다. 2의 제곱수로 뺀다고 생각 하면 된다.
	다르게 표현하면 parent[parent[parent[v1][0]][2]][3] 이다.
	*/
	int dif = level[v1] - level[v2];

	for (int i = 0; dif > 0; i++) {
		if ((dif % 2) == 1) {
			v1 = parent[v1][i];
		}

		dif = dif >> 1;
	}

	if (v1 == v2) {
		return v1;
	}

	//root부터 내려가는 이유는 최소 공통 조상부터는 항상 공통 조상이기 때문이다.
	//즉 내려가면서 공통 조상이 아닐 때 노드의 부모가 최소 공통 조상이다.
	for (int i = max_level; i >= 0; i--) {
		if (parent[v1][i] != 0 && parent[v1][i] != parent[v2][i]) {
			v1 = parent[v1][i];
			v2 = parent[v2][i];
		}
	}

	v1 = parent[v1][0];

	return v1;
}
void parentSetting(int node) {
	for (int i = 1; i <= max_level; i++) {
		int temp = parent[parent[node][i - 1]][i - 1];

		if (temp == 0) {
			return;
		}

		parent[node][i] = temp;
	}
}
void TreeSet(int n) {
	int* q = (int*)malloc(sizeof(int) * (MAXSIZE + 1));
	int rear = -1;
	int front = -1;

	push(q, 1, &rear);
	visited[1] = true;

	//노드들의 level과 바로 위 2^0번째 부모를 저장
	while (rear != front) {
		pop(&rear, &front);

		int node = q[front];
		
		Link* ptr = g[node].next;
		while (ptr != NULL) {
			if (!visited[ptr->num]) {
				level[ptr->num] = level[node] + 1;
				parent[ptr->num][0] = node;

				parentSetting(ptr->num);//각 노드들의 2^max_level번째 부모를 저장

				visited[ptr->num] = true;
				push(q, ptr->num, &rear);
			}

			ptr = ptr->next;
		}
	}
}
int main() {
	int n,m;

	scanf("%d", &n);

	int v1, v2;
	for (int i = 0; i < n-1; i++) {
		scanf("%d %d", &v1, &v2);

		append(v1, v2);
		append(v2, v1);
	}

	int temp = n;
	while (temp > 1) {
		temp = temp >> 1;
		max_level++;
	}

	TreeSet(n);

	scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		scanf("%d %d", &v1, &v2);
		printf("%d\n", LCA(v1, v2));
	}
}