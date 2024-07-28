#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define MIN(a,b)a<b?a:b
#define INF 1.0e+9
int n;/* 1<=n<=3 */
int dp[61][61][61];

int DFS(int scv1,int scv2,int scv3){
	if ((scv1 == 0) && (scv2 == 0) && (scv3 == 0)) {
		return 0;
	}
	
	if (dp[scv1][scv2][scv3] != 0) {
		return dp[scv1][scv2][scv3];
	}

	dp[scv1][scv2][scv3] = INF;

	dp[scv1][scv2][scv3] = MIN(dp[scv1][scv2][scv3], 1 + DFS((scv1 - 9) < 0 ? 0 : (scv1 - 9), (scv2 - 3) < 0 ? 0 : (scv2 - 3), (scv3 - 1) < 0 ? 0 : (scv3 - 1)));
	dp[scv1][scv2][scv3] = MIN(dp[scv1][scv2][scv3], 1 + DFS((scv1 - 9) < 0 ? 0 : (scv1 - 9), (scv2 - 1) < 0 ? 0 : (scv2 - 1), (scv3 - 3) < 0 ? 0 : (scv3 - 3)));
	dp[scv1][scv2][scv3] = MIN(dp[scv1][scv2][scv3], 1 + DFS((scv1 - 3) < 0 ? 0 : (scv1 - 3), (scv2 - 9) < 0 ? 0 : (scv2 - 9), (scv3 - 1) < 0 ? 0 : (scv3 - 1)));
	dp[scv1][scv2][scv3] = MIN(dp[scv1][scv2][scv3], 1 + DFS((scv1 - 3) < 0 ? 0 : (scv1 - 3), (scv2 - 1) < 0 ? 0 : (scv2 - 1), (scv3 - 9) < 0 ? 0 : (scv3 - 9)));
	dp[scv1][scv2][scv3] = MIN(dp[scv1][scv2][scv3], 1 + DFS((scv1 - 1) < 0 ? 0 : (scv1 - 1), (scv2 - 9) < 0 ? 0 : (scv2 - 9), (scv3 - 3) < 0 ? 0 : (scv3 - 3)));
	dp[scv1][scv2][scv3] = MIN(dp[scv1][scv2][scv3], 1 + DFS((scv1 - 1) < 0 ? 0 : (scv1 - 1), (scv2 - 3) < 0 ? 0 : (scv2 - 3), (scv3 - 9) < 0 ? 0 : (scv3 - 9)));

	return dp[scv1][scv2][scv3];
}
int main() {
	int scv[3] = { 0 };

	scanf("%d", &n);

	for (int i = 0;i < n;i++) {
		scanf("%d", &scv[i]);
	}


	printf("%d",DFS(scv[0], scv[1], scv[2]));
}