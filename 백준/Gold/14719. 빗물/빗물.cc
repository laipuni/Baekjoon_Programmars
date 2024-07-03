#include<stdio.h>
#include<stdlib.h>
int MAX(int a, int b) { return (a > b ? a : b);}
int MIN(int a, int b) { return (a < b ? a : b);}
int main()
{
	int right = 0, left = 0, result = 0;
	int h, w;
	int *arr;
	scanf("%d %d", &h, &w);
	arr = (int*)malloc(sizeof(int) * w);
	for (int i = 0;i < w;i++)
		scanf("%d", &arr[i]);
	for (int i = 1;i < w-1;i++)
	{
		for (int o = 0;o<i;o++)
		{
			left = MAX(arr[o], left);
		}
		for (int o = i+1;o < w;o++)
		{
			right = MAX(arr[o], right);
		}
		result += MAX(0, MIN(left, right) - arr[i]);
		left = 0;right = 0;
	}
	printf("%d", result);
}