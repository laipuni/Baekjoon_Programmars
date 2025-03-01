#include<stdio.h>
int main()
{	
	int CASE = 0,a=0,b=0;
	int C[31][31] = {0};
	for (int i = 0;i <31;i++)
	{
		for (int o = 0;o <= i;o++)
		{
			if (o == 0 || i == o)
			{
				C[i][o] = 1;
			}
			else if (o == 1||i-o==1)
			{
				C[i][o] = i;
			}
			else
			{
				C[i][o] = C[i - 1][o - 1] + C[i - 1][o];
			}
		}
	}
	scanf("%d", &CASE);
	for (int i = 0;i < CASE;i++)
	{
		scanf("%d %d", &a,&b);
		printf("%d\n", C[b][a]);
	}
	
}