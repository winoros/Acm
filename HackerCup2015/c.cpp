/*
 * =====================================================================================
 *
 *       Filename:  c.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/2/8 14:56:07
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

const int mod = 1e9+7;

int dp[2010][2010];

int dfs(int n1, int n2) {
	if(n2 == 0)
		return 1;
	int &ret = dp[n1][n2];
	if(ret != -1)
		return ret;
	ret = 0;
	ret = dfs(n1, n2-1);
	if(n1 > n2+1)
		ret += dfs(n1-1, n2);
	return ret %= mod;
}

int dfss(int n1, int n2) {
	if(n1 == 0)
		return 1;
	int &ret = dp[n1][n2];
	if(ret != -1)
		return ret;
	ret = 0;
	ret = dfss(n1-1, n2);
	if(n2 > n1)
		ret += dfss(n1, n2-1);
	return ret %= mod;
}

void MAIN() {
	int a, b;
	scanf("%d-%d", &a, &b);
	memset(dp, -1, sizeof dp);
	int ans1 = dfs(a, b);
	memset(dp, -1, sizeof dp);
	int ans2 = dfss(b, b);
	printf("%d %d\n", ans1, ans2);
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		printf("Case #%d: ", i);
		MAIN();
	}
	return 0;
}
