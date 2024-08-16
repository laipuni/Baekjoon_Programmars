#include<stdio.h>
#include<stdlib.h>
#define MAX(a,b)a>b?a:b
int main()
{
	int n,max=0;
	int* arr;
	int* up_dp;
	int* down_dp;
	scanf("%d", &n);
	arr = (int*)calloc(n+1, sizeof(int));
	up_dp = (int*)calloc(n+1, sizeof(int));
	down_dp = (int*)calloc(n+1, sizeof(int));
	for (int i = 0;i < n;i++)
		scanf("%d", &arr[i]);
	for (int i = 1;i < n;i++)
	{
		for (int j = 0;j < i;j++)
		{
			if (arr[j] < arr[i])
			{
				up_dp[i] = MAX(up_dp[i], up_dp[j] + 1);
			}
		}
	}
	for (int i = n-2;i>=0 ;i--)
	{
		for (int j = n-1;j > i;j--)
		{
			if (arr[j] < arr[i])
			{
				down_dp[i] = MAX(down_dp[i], down_dp[j] + 1);
			}
		}
	}
	for (int i = 0;i < n;i++)
	{
		max = MAX(up_dp[i] + down_dp[i] + 1, max);
	}
	printf("%d", max);
}