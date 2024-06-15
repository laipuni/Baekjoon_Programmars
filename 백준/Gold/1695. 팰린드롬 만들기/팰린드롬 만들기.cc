#include<stdio.h>
#define MAXSIZE 5000
#define MAX(a,b)a>b?a:b
int dp[MAXSIZE + 1][MAXSIZE + 1];
int arr[MAXSIZE + 1];

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[n - i + 1] == arr[j]) {
				dp[i][j] = MAX(dp[i - 1][j - 1] + 1,dp[i][j-1]);
				dp[i][j] = MAX(dp[i][j], dp[i - 1][j]);
			}
			else {
				dp[i][j] = MAX(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}

	printf("%d", n - dp[n][n]);
}