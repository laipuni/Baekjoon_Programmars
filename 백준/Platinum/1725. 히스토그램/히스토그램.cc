#include<stdio.h>
#define MAXSIZE 100000
#define MAX_NUM 1000000000
#define MIN(a,b)a<b?a:b
#define MAX(a,b)a>b?a:b
int n;
int result;
int arr[MAXSIZE + 1];
int tree[MAXSIZE * 4 + 1];

int initTree(int start, int end, int node) {
	if (start == end) {
		return tree[node] = start;
	}

	int mid = (start + end) / 2;

	int left_idx = initTree(start, mid, node * 2);
	int right_idx = initTree(mid + 1, end, node * 2 + 1);

	return tree[node] = arr[left_idx] < arr[right_idx] ? left_idx : right_idx;
}
int getAreaMin(int start, int end, int left, int right, int node) {
	if (right < start || end < left) {
		return MAX_NUM;
	}

	if (left <= start && end <= right) {
		return tree[node];
	}

	int mid = (start + end) / 2;

	int left_idx = getAreaMin(start, mid, left, right, node * 2);
	int right_idx = getAreaMin(mid + 1, end, left, right, node * 2 + 1);

	if (left_idx == MAX_NUM) {
		return right_idx;
	}
	else if (right_idx == MAX_NUM) {
		return left_idx;
	}
	else {
		return arr[left_idx] < arr[right_idx] ? left_idx : right_idx;
	}
}
void solve(int left, int right) {
	if (left > right) {
		return;
	}

	int idx = getAreaMin(0, n - 1, left, right, 1);

	result = MAX(result, arr[idx] * (right - left + 1));

	solve(left, idx - 1);
	solve(idx + 1, right);
}
void input() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
}
int main() {
	input();

	initTree(0, n - 1, 1);

	solve(0, n - 1);

	printf("%d", result);
}