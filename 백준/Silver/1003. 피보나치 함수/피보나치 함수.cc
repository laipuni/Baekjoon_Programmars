#include<stdio.h>
int main()
{
	int dp_one[41] = {0,1,1};
	int dp_zero[41] = {1,0,1};
	int num = 0,i,o,f;
	int current = 2;
	scanf("%d", &num);
	for (i = 0;i < num;i++)
	{
		scanf("%d", &f);
		if (dp_one[f] == 0 && dp_zero[f] == 0)
		{   
			
			for (o = current-1;o <f - 1;o++)
			{   

				dp_zero[o + 2] = dp_zero[o] + dp_zero[o + 1];
				dp_one[o + 2] = dp_one[o] + dp_one[o + 1];
			}
			if (current < o + 1)
				current = o + 1;
		}
		printf("%d %d\n", dp_zero[f], dp_one[f]);
	}
}