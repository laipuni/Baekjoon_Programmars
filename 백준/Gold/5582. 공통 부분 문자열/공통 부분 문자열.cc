#include<stdio.h>
#include<string.h>
#define MAXSIZE 4000
#define MAX(a,b)a>b?a:b
int dp[MAXSIZE + 1][MAXSIZE + 1];
char str1[MAXSIZE + 1];
char str2[MAXSIZE + 1];

int main() {
	int max = 0;
	int str1_len;
	int str2_len;
	scanf("%s", str1);
	scanf("%s", str2);

	str1_len = strlen(str1);
	str2_len = strlen(str2);

	for (int i = 1; i <= str1_len; i++) {
		for (int j = 1; j <= str2_len; j++) {
			if (str1[i-1] == str2[j-1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				max = MAX(dp[i][j], max);
			}
		}
	}

	printf("%d", max);
}