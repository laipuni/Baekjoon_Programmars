#include <stdio.h>
int main()
{
	int num, a, b,i,o;
	int sum = 1;
	scanf("%d", &num);
	for (i = 0; i <num; i++)
	{
		scanf("%d %d", &a, &b);
		for (o = 0; o < b; o++)
		{
			sum *= a;
			sum %= 10;
		}
		if (sum == 0)
			sum = 10;
		printf("%d\n", sum);
		sum = 1;
	}
}