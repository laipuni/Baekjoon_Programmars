#include<stdio.h>
int parent[201];
int root_height[201];

int find_root(int x) {
	if (x == parent[x]) {
		return x;
	}

	return parent[x] = find_root(parent[x]);
}
void union_root(int a, int b) {
	a = find_root(a);
	b = find_root(b);

	if (a == b) {
		return;
	}

	if (root_height[a] == root_height[b]) {
		parent[b] = a;
		root_height[a]++;
	}
	else if (root_height[a] > root_height[b]) {
		parent[b] = a;
	}
	else {
		parent[a] = b;
	}
}
int main() {
	int n, m;
	int temp;
	int city;

	scanf("%d %d", &n, &m);

	for (int i = 1;i <= n;i++) {
		/*처음은 부모가 없으니 자신으로*/
		parent[i] = i;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &temp);

			if (temp) {
				/*temp가 1이면 연결 되었으니 union*/
				union_root(i, j);
			}
		}
	}

	scanf("%d", &city);
	int region = find_root(city);

	for (int i = 1;i < m;i++) {
		scanf("%d", &city);

		if (region != find_root(city)) {
			printf("NO");
			return 0;
		}
	}

	printf("YES");
}