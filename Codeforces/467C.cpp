/*===============================================================
*   
*   FILE NAME:  467C.cpp
*   AUTHOR:     winoros
*   SHOOL:      BUPT
*   DATE:       09/19/2014 01:55:42
*   EMAIL:      winoros@gmail.com
*   Description:  
*
*
================================================================*/
#include <bits/stdc++.h>

using namespace std;

int a[5010]; 
long long sum[5010];
long long dp[5010][5010];

int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		sum[i] = sum[i-1] + a[i];
	}
	for(int i = m+1; i <= n; i++)
		sum[i] = sum[i-1] + a[i] - a[i-m];
	memset(dp, 0, sizeof dp);
	for(int i = m; i <= n; i++) {
		for(int j = 1; j <= k; j++) {
			dp[i][j] = dp[i-1][j];
			dp[i][j] = max(dp[i][j], dp[i-m][j-1] + sum[i]);
		}
	}
	printf("%I64d\n", dp[n][k]);
	return 0;
}
