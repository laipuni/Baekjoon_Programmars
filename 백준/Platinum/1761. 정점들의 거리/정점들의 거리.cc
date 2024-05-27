#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define SWAP(a,b,t)(t=a,a=b,b=t)
#define MAXSIZE 40000
typedef struct Link {
	unsigned short num;
	unsigned short dis;
	struct Link* next;
}Link;
typedef struct {
	Link* next;
	Link* last;
}Graph;
int dis[MAXSIZE + 1][16];
int parent[MAXSIZE + 1][16];
int depth[MAXSIZE + 1];
Graph g[MAXSIZE + 1];
bool visited[MAXSIZE + 1];
int max_depth;

void append(int v1, int v2,int dis) {
	Link* newnode = (Link*)malloc(sizeof(Link*));
	newnode->dis = dis;
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
void parentSetting(int node) {
	for (int i = 1; i <= max_depth; i++) {
		int temp = parent[parent[node][i - 1]][i - 1];

		if (temp == 0) {
			return;
		}

		parent[node][i] = temp;

		// 2^i번째 부모까지의 거리 = 2^i-1번째에서 부모 -> 2^i번째 부모 까지 거리 + 2^i-1번째 부모까지에 거리
		dis[node][i] = dis[parent[node][i - 1]][i - 1] + dis[node][i - 1];
	}
}
void TreeSet() {
	int* q = (int*)malloc(sizeof(int) * (MAXSIZE + 1));
	int rear = -1;
	int front = -1;

	push(q, 1, &rear);
	visited[1] = true;

	while (rear != front) {
		pop(&rear, &front);

		int node = q[front];

		Link* ptr = g[node].next;
		while (ptr != NULL) {
			if (!visited[ptr->num]) {
				depth[ptr->num] = depth[node] + 1;
				dis[ptr->num][0] = ptr->dis;//1번째 부모까지 거리
				parent[ptr->num][0] = node;

				parentSetting(ptr->num);

				visited[ptr->num] = true;
				push(q, ptr->num, &rear);
			}
			
			ptr = ptr->next;
		}
	}
}
int getdepth(int dif,int* v1) {
	int sum = 0;

	for (int i = 0; dif > 0; i++) {
		if ((dif % 2) == 1) {
			sum += dis[*v1][i];
			*v1 = parent[*v1][i];
		}

		dif = dif >> 1;
	}

	return sum;
}
int LCA(int v1, int v2) {
	int sum = 0;

	if (depth[v1] < depth[v2]) {
		int temp;

		SWAP(v1, v2, temp);
	}

	int dif = depth[v1] - depth[v2];

	sum += getdepth(dif, &v1);

	if (v1 == v2) {
		return sum;
	}

	int min_parent;
	int temp_v1 = v1;
	int temp_v2 = v2;

	for (int i = max_depth; i >= 0; i--) {
		if (parent[temp_v1][i] != 0 && parent[temp_v1][i] != parent[temp_v2][i]) {
			temp_v1 = parent[temp_v1][i];
			temp_v2 = parent[temp_v2][i];
		}
	}

	min_parent = parent[temp_v1][0];//최소 공통 조상

	dif =  depth[v1]- depth[min_parent];//최소 공통 조상에서 v1까지의 거리를 구하기 위해 높이차를 계산

	sum += getdepth(dif, &v1);//조상까지 거슬러 올라가면서 거리를 계산
	sum += getdepth(dif, &v2);

	return sum;
}
int main() {
	int n,m;
	int v1, v2,dis;
	
	scanf("%d", &n);

	for (int i = 0; i < n - 1; i++) {
		scanf("%d %d %d", &v1, &v2, &dis);

		append(v1, v2, dis);
		append(v2, v1, dis);
	}

	int temp = n;
	while (temp > 1) {
		temp = temp >> 1;
		max_depth++;
	}

	TreeSet();//거리, 부모 전처리

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &v1, &v2);

		printf("%d\n", LCA(v1, v2));
	}
}