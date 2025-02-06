#include<stdio.h>
#include<stdlib.h>
#define MAX(a,b)a>b?a:b
typedef struct Link{
	int num;
	struct Link* next;
}Link;
typedef struct {
	int cost;
	int inDgree;
	Link* next;
	Link* last;
}Data;
void append(Data* head, int num) {
	Link* newnode = (Link*)malloc(sizeof(Link));
	newnode->num = num;
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
	Data* head = (Data*)malloc(sizeof(Data)*(n+1));

	for (int i = 0; i <= n; i++) {
		(head + i)->cost = 0;
		(head + i)->inDgree = 0;
		(head + i)->last = NULL;
		(head + i)->next = NULL;
	}

	return head;
}
void topologySort(int n) {
	int cost;
	int temp;
	Data* head = headSetting(n);

	int* q = (int*)malloc(sizeof(int) * (n + 1));
	int* arr = (int*)malloc(sizeof(int) * (n + 1));
	int rear = -1;
	int front = -1;


	for (int i = 1; i <= n; i++) {
		scanf("%d", &cost);
		(head + i)->cost = cost;
		arr[i] = cost;

		while (1) {
			scanf("%d", &temp);

			if (temp == -1) {
				break;
			}

			(head + i)->inDgree++;
			append((head + temp), i);
		}
	}

	for (int i = 1; i <= n; i++) {
		if ((head + i)->inDgree == 0) {
			q[++rear] = i;
		}
	}

	for (int i = 0; i < n; i++) {
		if (rear == front) {
			printf("사이클 발생");
		}

		front++;

		Link* ptr = (head + q[front])->next;

		while (ptr != NULL) {
			(head + (ptr->num))->inDgree--;
			(head + (ptr->num))->cost = MAX((head + (ptr->num))->cost,(head+q[front])->cost + arr[ptr->num]);

			if ((head + (ptr->num))->inDgree == 0) {
				rear++;
				q[rear] = ptr->num;
			}

			ptr = ptr->next;
		}
	}

	for (int i = 1; i <= n; i++) {
		printf("%d\n", (head + i)->cost);
	}
}
int main() {
	int n;
	scanf("%d", &n);

	topologySort(n);
}