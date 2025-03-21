#include<stdio.h>
#define MIN(a,b)a<b?a:b
#define MAX(a,b)a>b?a:b
int n, m;
int arr[101];
int c[101];
int dp[101][10001] = { 0 };
int min = 1.0e+8;

int main()
{	
	int sum = 0;

	scanf("%d %d", &n, &m);

	for (int i = 0;i < n;i++)
		scanf("%d", &arr[i]);

	for (int i = 0;i < n;i++)
	{
		scanf("%d", &c[i]);
		sum += c[i];
	}
	
	for (int i = 1;i <=n;i++)
	{
		for (int j = 0;j <= sum;j++)
		{
			if (c[i - 1] <= j)
				dp[i][j] = MAX(dp[i - 1][j - c[i - 1]] + arr[i - 1], dp[i - 1][j]);

			dp[i][j] =MAX(dp[i][j],dp[i - 1][j]);
	
			if (dp[i][j] >= m && min > j)
				min = j;
		}
	}

	printf("%d", min);
}