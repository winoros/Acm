/*
 * =====================================================================================
 *
 *       Filename:  1039.cpp
 *
 *    Description:  solve the 1039th problem of Ural
 *
 *        Version:  1.0
 *        Created:  2014/8/28 16:34:03
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

int dp[6001][2], degree[6001];
vector<int> v[6001];

void dfs(int now, int fa) {
	int sz = v[now].size();
	dp[now][0] = 0, dp[now][1] = degree[now];
	for(int i = 0; i < sz; i++) {
		if(v[now][i] == fa) continue;
		dfs(v[now][i], now);
		dp[now][0] += max(dp[v[now][i]][1], dp[v[now][i]][0]);
		dp[now][1] += dp[v[now][i]][0];
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &degree[i]);
	for(int i = 1; i < n; i++) {
		int son, fa;
		scanf("%d%d", &son, &fa);
		v[fa].push_back(son);
		v[son].push_back(fa);
	}
	dfs(1, -1);
	printf("%d\n", max(dp[1][0], dp[1][1]));
	return 0;
}
