#include<stdio.h>
#include<stdlib.h>
#define Long long long
#define MAX(a,b)a>b?a:b
#define MAXSIZE 100000
#define MAX_NUM 1000000
int n;
int arr[MAXSIZE + 1];
int tree[MAXSIZE * 4 + 1];
Long max = 0;

void initTree(int start, int end, int node) {
	if (start == end) {
		tree[node] = start;
		return;
	}

	int mid = (start + end) / 2;

	initTree(start, mid, node * 2);
	initTree(mid + 1, end, node * 2 + 1);

	tree[node] = arr[tree[node * 2]] < arr[tree[node * 2 + 1]] ? tree[node * 2] : tree[node * 2 + 1];
}
int getAreaMin(int start,int end,int left,int right,int node) {
	if (right < start || end < left) {
		return MAX_NUM;
	}

	if (left <= start && end <= right) {
		return tree[node];
	}
	
	int mid = (start + end) / 2;

	int left_idx = getAreaMin(start, mid, left, right, node * 2);
	int right_idx = getAreaMin(mid + 1,end, left, right, node * 2 + 1);

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

	max = MAX(max, (Long)arr[idx] * (right - left + 1));

	solve(left, idx - 1);
	solve(idx + 1, right);
}
int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	initTree(0, n - 1, 1);

	solve(0, n - 1);

	printf("%lld", max);
}