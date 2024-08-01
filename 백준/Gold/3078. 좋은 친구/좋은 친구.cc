#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int check[20];
char** friends;
int n, k;
int* q;
void input()
{
	for (int i = 0;i < n;i++)
	{
		scanf("%s", friends[i]);
		getchar();
	}
}
long long solve()
{
	long long sum=0;
	int front = 0, top = 0,len;
	for (int i = n - 1;i >= 0;i--)
	{
		len = strlen(friends[i]) - 1;
		if (top - front>k)
			check[q[front++]]--;
		sum += check[len];
		check[len]++;
		q[top] = len;
		top = (top + 1) % n;
	}
	return sum;
}
int main()
{
	scanf("%d %d", &n, &k);
	friends = (char**)calloc(n + 1, sizeof(char*));
	q = (int*)calloc(n + 1, sizeof(int));
	for (int i = 0;i <= n;i++)
		friends[i] = (char*)calloc(21, sizeof(char));
	input();
	printf("%lld",solve());
}