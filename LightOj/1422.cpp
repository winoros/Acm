/*
 * =====================================================================================
 *
 *       Filename:  1422.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/10/11 19:14:12
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

int dp[110][110];
int op[110];

int dfs(int l, int r) {
	if(dp[l][r] != -1)
		return dp[l][r];
	if(l == r)
		return dp[l][r] = 1;
	else if(l > r)
		return dp[l][r] = 0;
	if(op[l] == op[r])
		dp[l][r] = dfs(l+1, r-1) + 1;
	else
		dp[l][r] = dfs(l+1, r) + 1;
	for(int i = l+1; i < r; ++i)
		if(op[l] == op[i])
			dp[l][r] = min(dp[l][r], dfs(l+1, i-1) + dfs(i, r));
	return dp[l][r];
}

int main() {
	int nn;
	scanf("%d", &nn);
	for(int ii = 1; ii <= nn; ++ii) {
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
			scanf("%d", &op[i]);
		memset(dp, -1, sizeof dp);
		printf("Case %d: %d\n", ii, dfs(0, n-1));
	}
	return 0;
}
