#include<stdio.h>
int question();
int dfs(int(*p)[50], int y, int x, int n, int m);
int main()
{
	int i;
	int T;
	scanf("%d", &T);
	for ( i = 0;i < T;i++)
	{
		printf("%d\n",question());
	}
}
int question()
{
	int arr[50][50] = { 0 };
	int n, m, k, x, y,sum=0;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0;i < k;i++)
	{
		scanf("%d %d", &x, &y);
		arr[y][x] = 1;
	}
	for (int i = 0;i < m;i++)
	{
		for (int o = 0;o < n;o++)
		{
			if (arr[i][o] == 1)
				sum+=dfs(arr,i,o,n,m);
		}
	}
	return sum;
}
int dfs(int (*p)[50],int y,int x,int n,int m)
{
	if (p[y][x] == 0)
		return 0;
	else if (x < 0 || y < 0 || x >= n || y >= m)
		return 0;
	p[y][x] = 0;
	dfs(p, y + 1, x, n, m);
	dfs(p, y -1, x, n, m);
	dfs(p, y, x+1, n, m);
	dfs(p, y, x-1, n, m);
	return 1;
}