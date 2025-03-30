#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100000
#define Long long long
typedef struct {
	Long start;
	Long end;
}element;
int n;
element arr[MAXSIZE + 1];

void push(Long num, Long* heap,int* size) {
	(*size)++;
	int child = *size;
	int parent = child / 2;

	while (child != 1 && (num < heap[parent])) {
		heap[child] = heap[parent];
		child = parent;
		parent = child / 2;
	}

	heap[child] = num;
}
void pop(Long* heap, int* size) {
	Long temp = heap[(*size)--];
	int parent = 1;
	int child = 2;

	while (child <= *size) {
		if (child < *size && heap[child] > heap[child + 1]) {
			child++;
		}

		if (temp <= heap[child]) {
			break;
		}
		else {
			heap[parent] = heap[child];
			parent = child;
			child = parent * 2;
		}
	}

	heap[parent] = temp;
}
int cmp(const void* a, const void* b) {
	element x = *(element*)a;
	element y = *(element*)b;

	if (x.start > y.start) {
		return 1;
	}
	else if(x.start < y.start){
		return -1;
	}
	else {
		if (x.end > y.end) {
			return 1;
		}

		return 0;
	}
}
void input() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &arr[i].start, &arr[i].end);
	}
}
int main() {
	Long* heap = (Long*)malloc(sizeof(Long) * (MAXSIZE + 1));
	int size = 0;
	input();

	qsort(arr, n, sizeof(element), cmp);

	push(arr[0].end, heap, &size);
	for (int i = 1; i < n; i++) {
		if (heap[1] <= arr[i].start) {
			pop(heap, &size);
		}
		
		push(arr[i].end, heap, &size);
	}

	printf("%d", size);
}