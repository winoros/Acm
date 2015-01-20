/*
 * =====================================================================================
 *
 *       Filename:  313D.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/10/17 17:45:25
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  winoros (Ding), winoros@gmail.com
 *   Organization:  BUPT
 *
 * =====================================================================================
 */
#include <bits/stdc++.h>

using namespace std;

long long dp[310][310];
long long cost[310][310];

int  main() {
	memset(cost, 0x3f, sizeof cost);
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < m; ++i) {
		int l, r, c;
		scanf("%d%d%d", &l, &r, &c);
		cost[l][r] = min(cost[l][r], (long long)c);
	}
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j < i; ++j)
			cost[j+1][i] = min(cost[j+1][i], cost[j][i]);
	memset(dp, 0x3f, sizeof dp);
	dp[0][0] = 0;
	for(int i = 1; i <= n; ++i) {
		dp[i][0] = 0;
		for(int j = 1; j <= i; ++j) {
			dp[i][j] = min(dp[i][j], dp[i-1][j]);
			for(int k = 1; k <= i; ++k)
				if(j >= i-k+1)
					dp[i][j] = min(dp[i][j], dp[k-1][j - (i-k+1)] + cost[k][i]);
		}
	}
	long long ans = 0x3f3f3f3f3f3f3f3f;
	for(int i = k; i <= n; ++i)
		ans = min(ans, dp[n][i]);
	printf("%I64d\n", ans == 0x3f3f3f3f3f3f3f3f ? -1 : ans);
	return 0;
}

