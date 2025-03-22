#include<stdio.h>
#include<stdlib.h>
int top=-1;
int n;
const int front = -1;
int* stack;
int* arr;
int* result;
void solve()
{	
	top = (top + 1) % n;
	stack[top] = arr[n - 1];
	for (int i = n-2;i>=0;i--)
	{
		while (front != top)
		{
			if (stack[top] > arr[i])
			{
				result[i] = stack[top];
				break;
			}
			top--;
		}
		top = (top + 1)%n;
		stack[top] = arr[i];
	}
}
int main()
{
	scanf("%d", &n);
	stack = (int*)calloc(n + 1, sizeof(int));
	arr = (int*)calloc(n + 1, sizeof(int));
	result = (int*)calloc(n + 1, sizeof(int));
	for (int i = 0;i < n;i++)
		scanf("%d", &arr[i]);
	solve();
	for (int i = 0; i < n;i++)
		printf("%d ", result[i]!=0? result[i]:-1);
}