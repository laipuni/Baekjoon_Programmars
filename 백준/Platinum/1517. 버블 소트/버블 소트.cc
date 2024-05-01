#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 500000
int n;
int arr[MAXSIZE + 1];
int temp[MAXSIZE + 1];
long long result;

void merge(int left, int mid, int right) {
	int i = left;
	int j = mid + 1;
	int idx = left;
	long long count = 0;

	while (i <= mid && j <= right) {
		if (arr[i] > arr[j]) {
			count++;
			temp[idx++] = arr[j++];
		}
		else {
			result += count;
			temp[idx++] = arr[i++];
		}
	}

	if (i > mid) {
		while (j <= right) {
			count++;
			temp[idx++] = arr[j++];
		}
	}
	else {
		while (i <= mid) {
			result += count;
			temp[idx++] = arr[i++];
		}
	}

	for (int i = left; i <= right; i++) {
		arr[i] = temp[i];
	}
}
void mergeSort(int left,int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort(left, mid);
		mergeSort(mid + 1, right);
		merge(left, mid, right);
	}
}
void input() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
}
int main() {
	input();

	mergeSort(0, n - 1);

	printf("%lld\n", result);

}