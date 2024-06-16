#include<stdio.h>
#define MAX_DAY 1000000
#define Long long long
Long tree[MAX_DAY * 4 + 1];

void update(int start, int end, int idx, int dif, int node) {
	if (idx < start || end < idx) {
		return;
	}

	tree[node] += dif;

	if (start == end) {
		return;
	}

	int mid = (start + end) / 2;

	update(start, mid, idx, dif, node * 2);
	update(mid+1,end, idx, dif, node * 2 + 1);
}
Long getAreaMin(int start, int end, int left, int right, int node) {
	if (right < start || end < left) {
		return 0;
	}

	if (left <= start && end <= right) {
		return tree[node];
	}

	int mid = (start + end) / 2;

	return getAreaMin(start, mid, left, right, node * 2) + getAreaMin(mid + 1, end, left, right, node * 2 + 1);
}
int main() {
	int n, q;
	int type, a, b;
	scanf("%d %d", &n, &q);

	for (int i = 0; i < q; i++) {
		scanf("%d %d %d", &type, &a, &b);

		if (type == 1) {
			update(0, n - 1, a-1, b, 1);
		}
		else if (type == 2) {
			printf("%lld\n", getAreaMin(0, n - 1, a - 1, b - 1, 1));
		}
	}
}