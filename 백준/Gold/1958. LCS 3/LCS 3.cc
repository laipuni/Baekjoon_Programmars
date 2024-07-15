#include<stdio.h>
#include<string.h>
#define MAX(a,b)a>b?a:b
int LCS[101][101][101];
char str1[101],str2[101],str3[101];
int main()
{
	int len1, len2, len3;
	int i, j,o;
	scanf("%s %s %s", str1, str2, str3);
	len1 = strlen(str1), len2 = strlen(str2), len3 = strlen(str3);
	for (i = 1;i <=len1;i++)
	{
		for (j = 1;j <=len2;j++)
		{
			for (o = 1;o <=len3;o++)
			{
				if (str1[i - 1] == str2[j - 1]&&str2[j-1]==str3[o-1])
					LCS[i][j][o] = LCS[i - 1][j - 1][o-1] + 1;
				else
				{
					LCS[i][j][o] = MAX(LCS[i - 1][j][o], LCS[i][j - 1][o]);
					LCS[i][j][o] = MAX(LCS[i][j][o], LCS[i][j][o-1]);
				}
					
			}
		}
	}
	printf("%d", LCS[i-1][j-1][o-1]);
}