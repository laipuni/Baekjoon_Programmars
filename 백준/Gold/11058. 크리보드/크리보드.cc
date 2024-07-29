#include<stdio.h>
#define MAX(a,b)a>b?a:b
long long dp[101];
int n;

int main() {

	for (int i = 1;i <= 100;i++) {
		dp[i] = i;
	}

	for (int i = 1;i <= 100;i++) {
		for (int j = i + 3;j <= 100;j++) {
			dp[j] = MAX(dp[j],dp[i] * (j - (i + 1)));
		}
	}

	scanf("%d", &n);
    printf("%lld",dp[n]);
}