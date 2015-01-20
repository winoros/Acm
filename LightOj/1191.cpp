/*
 * =====================================================================================
 *
 *       Filename:  1191.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/10/9 11:45:58
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

long long dp[55][55][55];

int main() {
	for(int k = 1; k <= 50; ++k) {
		for(int i = 1; i <= k; ++i)
			dp[i][1][k] = 1;
		for(int i = 2; i <= 50; ++i)
			for(int j = i; j <= 50; ++j)
				for(int t = 1; t <= k && t <= j; ++t)
					dp[j][i][k] += dp[j-t][i-1][k];
	}
	int nn;
	scanf("%d", &nn);
	for(int ii = 1; ii <= nn; ++ii) {
		int n, m, k;
		scanf("%d%d%d", &n, &m, &k);
		printf("Case %d: %I64d\n", ii, dp[n][m][k]);
	}
	return 0;
}
