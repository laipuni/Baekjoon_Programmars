#include<stdio.h>
#define MAXSIZE 500000
int n,k,save;
int result;
int arr[MAXSIZE + 1];
int temp[MAXSIZE + 1];

void findResult(int num) {
	save++;
	if (save == k) {
		result = num;
	}
}
void merge(int start, int mid, int end) {
	int i = start;
	int j = mid + 1;
	int idx = start;

	while (i <= mid && j <= end) {
		if (arr[i] > arr[j]) {
			temp[idx] = arr[j];
			findResult(arr[j]);
			j++;
			idx++;
		}
		else {
			temp[idx] = arr[i];
			findResult(arr[i]);
			i++;
			idx++;
		}
	}

	if (i > mid) {
		while (j <= end) {
			temp[idx] = arr[j];
			findResult(arr[j]);
			idx++;
			j++;
		}
	}
	else {
		while (i <= mid) {
			temp[idx] = arr[i];
			findResult(arr[i]);
			idx++;
			i++;
		}
	}

	for (int i = start; i <= end; i++) {
		arr[i] = temp[i];
	}
}
void merge_sort(int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		merge_sort(start, mid);
		merge_sort(mid + 1, end);
		merge(start, mid, end);
	}
}
int main() {
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	merge_sort(0, n-1);

	if (save < k) {
		printf("-1");
	}
	else {
		printf("%d", result);
	}
}