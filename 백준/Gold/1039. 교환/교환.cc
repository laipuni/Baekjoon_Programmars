#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAXSIZE 1000000
#define SWAP(a,b,t)(t=a,a=b,b=t)
#define MAX(a,b)a>b?a:b
typedef struct {
	short count;
	int* arr;
}element;
int length;
bool visited[10][MAXSIZE+1];

void push(element* q, int count, int* ptr,int* rear) {
	if (*rear == MAXSIZE) {
		printf("큐 꽉찼는데요");
		exit(1);
	}
	else {
		*rear = *rear + 1;
		(q + (*rear))->count = count;
		(q + (*rear))->arr = ptr;
	}
}
void pop(int* rear, int* front) {
	if (*rear == *front) {
		printf("큐 비었는데요");
		exit(1);
	}
	else {
		*front = *front + 1;
	}
}
int* makeArr(int n) {
	int* arr = (int*)malloc(sizeof(int) * 7);
	int temp = 10;
	while (temp <= n) {
		temp *= 10;
	}

	temp /= 10;

	while (temp != 0) {
		arr[length++] = n / temp;
		n %= temp;
		temp /= 10;
	}

	return arr;
}
int invertArr(int* arr) {
	int temp = 0;

	for (int i = 0; i < length; i++) {
		temp *= 10;
		temp += arr[i];
	}

	return temp;
}
int* change(int x, int y, int* arr) {
	int* newarr = (int*)malloc(sizeof(int) * length);

	for (int i = 0; i < length; i++) {
		newarr[i] = arr[i];
	}

	int temp;
	SWAP(newarr[x], newarr[y], temp);

	return newarr;
}
void BFS(int* arr,int k) {
	int max = 0;
	element* q = (element*)malloc(sizeof(element) * (MAXSIZE));
	int rear = -1;
	int front = -1;

	push(q, 0, arr, &rear);

	while (rear != front) {
		pop(&rear, &front);
		int count = (q + front)->count;
		int* ptr = (q + front)->arr;

		if ((q + front)->count == k) {
			max = MAX(max, invertArr((q + front)->arr));
			continue;
		}

		if ((q + front)->arr[0] == 0) {
			continue;
		}

		for (int i = 0; i < length - 1; i++) {

			for (int j = i + 1; j < length; j++) {

				if ((i == 0) && (ptr[j] == 0)) { // 이거 없으면 91%에서 틀림
					continue;
				}

				int* nextptr = change(i, j, ptr);
				int temp = invertArr(nextptr);

				if (!visited[count][temp]) {
					visited[count][temp] = true;
					push(q, count + 1, nextptr, &rear);
				}
			}
		}
	}

	if (max == 0) {
		printf("-1");
	}
	else {
		printf("%d", max);
	}
}
int main() {
	int n, k;
	
	scanf("%d %d", &n, &k);

	BFS(makeArr(n), k);
}