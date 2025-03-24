#include<stdio.h>
#define MIN(a,b)a<b?a:b
#define INF 1.0e+7
int RGB[1001][3];
int dp[1001][3];
int n;
int min = INF;

int main()
{	

	scanf("%d", &n);

	for (int i = 0;i < n;i++)
		scanf("%d %d %d", &RGB[i][0], &RGB[i][1], &RGB[i][2]);


	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			if (j == i)
				dp[0][j] = RGB[0][j];
			else
				dp[0][j] = INF;
		}

		for (int k = 1; k < n; k++)
		{
			dp[k][0] = MIN(dp[k - 1][1] + RGB[k][0], dp[k - 1][2] + RGB[k][0]);
			dp[k][1] = MIN(dp[k - 1][0] + RGB[k][1], dp[k - 1][2] + RGB[k][1]);
			dp[k][2] = MIN(dp[k - 1][0] + RGB[k][2], dp[k - 1][1] + RGB[k][2]);
		}

		for (int j = 0;j < 3;j++)
		{
			if (j == i)
				dp[n-1][j]=INF;
			min = MIN(min, dp[n - 1][j]);
		}
	}

	printf("%d", min);
	
}