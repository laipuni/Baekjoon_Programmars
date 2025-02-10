#include<stdio.h>
#include<stdlib.h>
int n,count=10;

void back(int start, int end,long long sum, int depth)
{
	if (count == n && depth == 0)
	{
		printf("%lld",sum/10);
		exit(0);
	}
	else if (depth == 0)
	{
		count++;
		return;
	}

	for (int i = start;i < end;i++)
	{	
		sum += i;
		back(start - 1, i,sum*10,depth-1);
		sum -=(sum % 10);
	}
}
int main()
{
	scanf("%d", &n);
	
	int i = 2;
	if (n <=10)
		printf("%d", n);
	else 
		while (i<=10)
		{
			back(i-1, 10,0,i);
			i++;
		}

	if(i>10)
		printf("-1");
	
}