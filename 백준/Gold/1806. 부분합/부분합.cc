#include<stdio.h>
#include<stdlib.h>
#define MIN(a,b)a<b?a:b
int n, s, sum,min=100001;
int *arr;
int start, end;
int main()
{	
	scanf("%d %d", &n,&s);
	arr = (int*)calloc(n+1, sizeof(int));
	for (int i = 0;i <n;i++)
		scanf("%d", &arr[i]);

	while (end <= n || sum >= s)
	{
		if (sum >= s)
		{
			min = MIN(min, end - start);
			sum -= arr[start];
			start++;
		}
		else
		{
			sum += arr[end];
			end++;
		}
	}
	if (min == 100001)
		printf("0");
	else
		printf("%d", min);
}