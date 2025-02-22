#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100000
typedef struct {
	int start;
	int end;
}element;

int cmp(const void* a, const void* b) {
	element x = *(element*)a;
	element y = *(element*)b;

	if (x.start > y.start) {
		return 1;
	}
	else if (x.start < y.start) {
		return -1;
	}
	else {
		if (x.end > y.end) {
			return 1;
		}

		return 0;
	}
}
void push(int* h, int* size, int num) {
	(*size)++;
	int child = *size;
	int parent = child / 2;

	while (child != 1 && (num < h[parent])) {
		h[child] = h[parent];
		child = parent;
		parent = child / 2;
	}

	h[child] = num;
}
void pop(int* h, int* size) {
	int temp = h[(*size)--];
	int parent = 1;
	int child = 2;

	while (child <= *size) {
		if (child < *size && h[child] > h[child + 1]) {
			child++;
		}

		if (temp <= h[child]) {
			break;
		}
		else {
			h[parent] = h[child];
			parent = child;
			child = parent * 2;
		}
	}

	h[parent] = temp;
}
int main() {
	int n;
	int size = 0;
	element* arr = (element*)malloc(sizeof(element) * (MAXSIZE + 1));
	int* h = (int*)malloc(sizeof(int) * (MAXSIZE + 1));

	scanf("%d", &n);

	int num;
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &num, &arr[i].start, &arr[i].end);
	}

	qsort(arr, n, sizeof(element), cmp);

	push(h, &size, arr[0].end);
	for (int i = 1; i < n; i++) {
		if (h[1] <= arr[i].start) {
			pop(h, &size);
		}

		push(h, &size, arr[i].end);
	}

	printf("%d", size);
}