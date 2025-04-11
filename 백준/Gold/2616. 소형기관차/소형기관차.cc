#include<stdio.h>
#define MAXSIZE 50000
#define MAX(a,b)a>b?a:b
int arr[MAXSIZE + 1];//1:n 까지의 1~n까지 합을 담고있다.
int dp[4][MAXSIZE + 1];

int main() {
	int n, m;

	scanf("%d", &n);

	int ans;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &ans);

		sum += ans;
		arr[i] = sum;
	}

	scanf("%d", &m);

	for (int i = 1; i <= 3; i++) {
		for (int j = i * m; j <= n; j++) {
			dp[i][j] = MAX(dp[i][j - 1], dp[i - 1][j - m] + (arr[j] - arr[j - m]));
		}
	}

	printf("%d", dp[3][n]);
}