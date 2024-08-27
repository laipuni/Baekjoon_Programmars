#include<stdio.h>
#include<stdlib.h>
int map[2188][2188];
int n;
void printf_map()
{
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			printf("%c", map[i][j]==1?'*':' ');
		}
		printf("\n");
	}
}
void solve(int num, int x, int y)
{
	for (int i = y;i <= y + num * 2;i += num)
	{
		for (int j = x;j <= x + num * 2;j += num)
		{
			if ((i - y) / num == 1 && (j - x) / num == 1)
				continue;
			else if (num == 1)
				map[i][j] = 1;
			else
				solve(num / 3, i, j);
		}
	}
}
int main()
{	
	scanf("%d", &n);
	solve(n / 3, 0, 0);
	printf_map();
}