#include<stdio.h>
#include<stdlib.h>

int binary_search(int *list,int size,int target) {
	int end = size;
	int start = 0;
	int mid;

	while (start < end) {
		mid = (start + end) / 2;

		if (list[mid] >= target) {
			end = mid;
		}
		else {
			start = mid + 1;
		}
	}

	return end;
}
int main() {
	int n,temp;
	int* list;
	int list_idx = 0;

	scanf("%d", &n);

	list = (int*)malloc((n + 1) * sizeof(int));

	scanf("%d", &temp);
	list[0] = temp;

	for (int i = 1;i < n;i++) {
		scanf("%d", &temp);

		if (list[list_idx] < temp) {
			list_idx += 1;
			list[list_idx] = temp;
		}
		else {
			int change_idx = binary_search(list, list_idx, temp);
			list[change_idx] = temp;
		}
	}

	printf("%d", n - (list_idx+1));

	free(list);
}