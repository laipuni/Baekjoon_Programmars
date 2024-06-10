#include<stdio.h>
#define MAX_NUM 1000000001
#define MAXSIZE 100000
typedef struct {
	int idx;
	int min;
}element;
int n,m;
int arr[MAXSIZE + 1];
element tree[MAXSIZE * 4 + 1];

element initTree(int start, int end, int node) {
	if (start == end) {
		tree[node].idx = start;
		tree[node].min = arr[start];
		return tree[node];
	}

	int mid = (start + end) / 2;

	element res1 = initTree(start, mid, node * 2);
	element res2 = initTree(mid + 1, end, node * 2 + 1);

	return tree[node] = res1.min <= res2.min ? res1 : res2;
}
element getAreaMin(int start, int end, int left, int right, int node) {
	if (right < start || end < left) {
		element temp = { 0,MAX_NUM };
		return temp;
	}

	if (left <= start && end <= right) {
		return tree[node];
	}

	int mid = (start + end) / 2;

	element res1 = getAreaMin(start, mid, left, right, node * 2);
	element res2 = getAreaMin(mid + 1, end, left, right, node * 2 + 1);

	return res1.min <= res2.min ? res1 : res2;
}
element update(int start, int end, int idx, int num, int node) {
	if (idx < start || end < idx) {
		return tree[node];
	}

	if (start == end) {
		tree[node].min = num;
		return tree[node];
	}

	int mid = (start + end) / 2;

	element res1 = update(start, mid, idx, num, node * 2);
	element res2 = update(mid + 1, end, idx, num, node * 2 + 1);

	return tree[node] = res1.min <= res2.min ? res1 : res2;
}
void input() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
}
int main() {
	input();

	initTree(1, n, 1);

	scanf("%d", &m);

	int select, a, b;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &select, &a, &b);

		if (select == 1) {
			arr[a] = b;
			update(1, n, a, b, 1);
		}
		else if(select == 2){
			printf("%d\n", getAreaMin(1, n, a, b, 1).idx);
		}
	}
}