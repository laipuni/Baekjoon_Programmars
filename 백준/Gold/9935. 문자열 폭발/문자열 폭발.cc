#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 1000000
int top = -1;
const int front = -1;
char* str;
char* boom;
char* stack;
int boom_len, str_len;
void solve()
{
	int find = 1;
	for (int i = 0;i < str_len;i++)
	{
		if (boom[boom_len - 1] == str[i])
		{
			for (int j = 1;j < boom_len;j++)
			{
				if (stack[top - j + 1] != boom[boom_len - j - 1])
				{	
					find = 0;
					top = (top + 1) % MAXSIZE;
					stack[top] = str[i];
					break;
				}
			}
			if (find)
				top -= boom_len - 1;
			else
				find = 1;
		}
		else
		{
			top = (top + 1) % MAXSIZE;
			stack[top] = str[i];
		}
	}
	if (top != front)
		for (int i = 0;i <= top;i++)
			printf("%c", stack[i]);
	else
		printf("FRULA");
}
int main()
{
	str = (char*)calloc(MAXSIZE+1, sizeof(char));
	boom = (char*)calloc(37, sizeof(char));
	stack= (char*)calloc(MAXSIZE+1, sizeof(char));
	scanf("%s",str);
	getchar();
	scanf("%s",boom);
	boom_len = strlen(boom);
	str_len = strlen(str);
	solve();
}