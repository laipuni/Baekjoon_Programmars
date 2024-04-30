#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAXSIZE 1000
typedef struct Link{
	int num;
	struct Link* next;
}Link;
typedef struct {
	int inDgree;
	int cost;
	Link* next;
	Link* last;
}Data;
typedef struct {
	int tower;
	int cost;
}element;
typedef struct {
	int size;
	element heap[MAXSIZE + 1];
}heap;

void push(heap* h, int tower, int cost) {
	h->size++;
	int child = h->size;
	int parent = child / 2;

	while ((child != 1) && (cost < h->heap[parent].cost)) {
		h->heap[child] = h->heap[parent];
		child = parent;
		parent = child / 2;
	}

	h->heap[child].tower = tower;
	h->heap[child].cost = cost;
}
void pop(heap* h) {
	element temp = h->heap[h->size--];
	int parent = 1;
	int child = 2;

	while (child <= h->size) {
		if ((child < h->size) && (h->heap[child].cost > h->heap[child + 1].cost)) {
			child++;
		}

		if (h->heap[child].cost >= temp.cost) {
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
void append(Data* head, int tower) {
	Link* newnode = (Link*)malloc(sizeof(Link));
	newnode->num = tower;
	newnode->next = NULL;

	if (head->next == NULL) {
		head->next = newnode;
		head->last = newnode;
	}
	else {
		Link* ptr = head->last;

		ptr->next = newnode;
		head->last = newnode;
	}

}
Data* headSetting(int n) {
	Data* head = (Data*)malloc(sizeof(Data) * (n + 1));

	for (int i = 0; i <= n; i++) {
		(head + i)->cost = 0;
		(head + i)->inDgree = 0;
		(head + i)->last = NULL;
		(head + i)->next = NULL;
	}
	
	return head;
}
void input(Data* head,int n,int k) {
	int a, b;
	int temp;
	for (int i = 1; i <= n; i++) {
		//건물의 건설시간 입력
		scanf("%d", &temp);
		(head + i)->cost = temp;
	}

	for (int i = 0; i < k; i++) {
		//진입조건 입력
		scanf("%d %d", &a, &b);
		(head + b)->inDgree++;
		append((head + a), b);
	}
}
int topologySort() {
	int n, k;
	int target;
	heap* h = (heap*)malloc(sizeof(heap));
	h->size = 0;

	scanf("%d %d", &n, &k);

	Data* head = headSetting(n);

	input(head, n, k);

	//목표 건물입력
	scanf("%d", &target);

	for (int i = 1; i <= n; i++) {
		if ((head + i)->inDgree == 0) {
			push(h, i, (head+i)->cost);
		}
	}

	for (int i = 0; i < n; i++) {
		if (h->size == 0) {
			printf("사이클 발생");
			return -1;
		}

		int tower = h->heap[1].tower;
		int cost = h->heap[1].cost;
		pop(h);

		if (tower == target) {
			return cost;
		}

		Link* ptr = (head + tower)->next;

		while (ptr != NULL) {
			(head + (ptr->num))->inDgree--;
			if ((head + (ptr->num))->inDgree == 0) {
				push(h, ptr->num, cost + (head + (ptr->num))->cost);
			}
			ptr = ptr->next;
		}
	}
}
int main() {
	int T;
	
	scanf("%d", &T);

	while (T--) {
		printf("%d\n", topologySort());
	}
}