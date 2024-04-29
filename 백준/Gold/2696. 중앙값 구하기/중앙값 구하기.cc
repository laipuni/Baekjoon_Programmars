#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAXSIZE 5000
typedef struct {
	int size;
	long long heap[MAXSIZE + 1];
}Heap;

void push(Heap* h, long long num) {
	h->size++;
	int child = h->size;
	int parent = child / 2;

	while ((child != 1) && (num > h->heap[parent])) {
		h->heap[child] = h->heap[parent];
		child = parent;
		parent = child / 2;
	}

	h->heap[child] = num;
}
void pop(Heap* h) {
	long long temp = h->heap[h->size--];
	int parent = 1;
	int child = 2;

	while (child <= h->size) {
		if (child < h->size && (h->heap[child] < h->heap[child + 1])) {
			child++;
		}

		if (temp >= h->heap[child]) {
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
long long* input(int n) {
	long long* arr = (long long*)malloc(sizeof(long long) * (n + 1));

	for (int i = 1; i <= n; i++) {
		scanf("%lld", &arr[i]);
	}

	return arr;
}
Heap* makeHeap() {
	Heap* h = (Heap*)calloc(1,sizeof(Heap));
	h->size = 0;

	return h;
}
void solve() {
	int n;
	Heap* max_h = makeHeap();
	Heap* min_h = makeHeap();

	scanf("%d", &n);

	long long* arr = input(n);
	long long* result = (long long*)malloc(sizeof(long long)*(n+1));
	int count = 1;

	push(max_h, arr[1]);
	result[count - 1] = arr[1];
	for (int i = 2; i <= n; i++) {
		if (max_h->heap[1] > arr[i]) {
			//넣을 원소가 최대 힙보다 작은 경우 
			if (max_h->size - min_h->size >= 1) {
				//최소 힙과 사이즈차이가 1이상 일 경우
				//항상 최대 힙이 많거나 같아야 한다.
				push(min_h, -max_h->heap[1]);
				pop(max_h);
			}
			push(max_h, arr[i]);
		}
		else if (-min_h->heap[1] < arr[i] || min_h->size == 0) {
			//넣을 원소가 최소 힙보다 작은 경우 
			if (min_h->size - max_h->size >= 0) {
				//최대 힙과 사이즈차이가 0이상 일 경우 
				//항상 최대 힙이 많거나 같아야 한다.
				push(max_h, -min_h->heap[1]);
				pop(min_h);
			}
			push(min_h, -arr[i]);
		}
		else {
			//최대 힙보다 크지만 최소 힙보다 작을 경우

			if (max_h->size > min_h->size) {
				push(min_h, -arr[i]);
			}
			else {
				//사이즈가 같은 경우
				push(max_h, arr[i]);
			}
		}

		if (i % 2 == 1) {
			count++;
			result[count - 1] = max_h->heap[1];
		}
	}

	printf("%d\n", count);
	for (int i = 0; i < count; i++) {
		printf("%lld ", result[i]);
	}
	printf("\n");
}
int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		solve();
	}
}