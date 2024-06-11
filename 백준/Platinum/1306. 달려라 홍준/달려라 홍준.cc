#include<stdio.h>
#define MAXSIZE 1000000
#define MAX(a,b)a>b?a:b
int arr[MAXSIZE + 1];
int tree[MAXSIZE * 4 + 1];

void initTree(int start, int end, int node) {
	if (start == end) {
		tree[node] = arr[start];
		return;
	}

	int mid = (start + end) / 2;

	initTree(start, mid, node * 2);
	initTree(mid + 1, end, node * 2 + 1);

	tree[node] = MAX(tree[node * 2],tree[node * 2 + 1]);
}
int getAreaMin(int start ,int end,int left, int right,int node) {
	if (right < start || end < left) {
		return 0;
	}

	if (left <= start && end <= right) {
		return tree[node];
	}

	int mid = (start + end) / 2;

	int left_res = getAreaMin(start, mid, left, right, node * 2);
	int right_res = getAreaMin(mid+1 ,end, left, right, node * 2 + 1);


	return MAX(left_res,right_res);
}
int main() {
	int n, m;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	initTree(0, n - 1, 1);

	for (int i = m - 1; i < n - m + 1; i++) {
		printf("%d ", getAreaMin(0, n - 1, i - m + 1, i + m - 1, 1));
	}
}