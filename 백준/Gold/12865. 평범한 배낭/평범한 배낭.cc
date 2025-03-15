#include<stdio.h>
#include<stdlib.h>
#define MAX(a,b)a>b?a:b
typedef struct
{
	int w;
	int v;
}object;
int main()
{	
	int **dp;
	int n, k,result=0;
	scanf("%d %d", &n, &k);
	object* arr = (object*)calloc(n+1,sizeof(object));
	dp = (int**)calloc(n+1,sizeof(int*));
	for(int i=0;i<=n;i++)
		dp[i] = (int*)calloc(k+1, sizeof(int));
	for (int i = 1;i <=n;i++)
		scanf("%d %d",&(arr+i)->w,&(arr + i)->v);
	for (int i = 1;i <=n;i++)
	{
		for (int o = 1;o <=k;o++)
		{
			if ((arr+i)->w<= o)
			{
				if ((arr + i)->v+dp[i-1][o-(arr+i)->w] > dp[i - 1][o])
				{
					dp[i][o] = (arr + i)->v + dp[i - 1][o - (arr + i)->w];
				}
				else
				{
					dp[i][o] = dp[i - 1][o];
				}
					
			}
			else
			{
				dp[i][o] = dp[i - 1][o];
			}
			result = MAX(result, dp[i][o]);
		}
	}
	printf("%d", result);
}