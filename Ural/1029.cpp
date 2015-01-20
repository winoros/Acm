/*
 * =====================================================================================
 *
 *       Filename:  1029.cpp
 *
 *    Description:  solve the 1029th problem of Ural
 *
 *        Version:  1.0
 *        Created:  2014/8/27 16:47:00
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  winoros (), winoros@gmail.com
 *   Organization:  BUPT
 *
 * =====================================================================================
 */

#include <bits/stdc++.h>

using namespace std;

int dp[110][510] = { 0 }, cost[110][510];
pair<int, int> pre[110][510];

int main() {
	int m, n;
	scanf("%d%d", &m, &n);
	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= n; j++)
			scanf("%d", &cost[i][j]);
	for(int i = 1; i <= n; i++)
		pre[1][i].second = -1;
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			dp[i][j] = dp[i-1][j] + cost[i][j];
			if(i > 1) 
				pre[i][j].first = i-1, pre[i][j].second = j;
		}
		for(int j = 1; j <= n; j++)
			if(j > 1 && dp[i][j] > dp[i][j-1]+cost[i][j])
				dp[i][j] = dp[i][j-1]+cost[i][j], pre[i][j].first = i, pre[i][j].second = j-1;;
		for(int j = n; j > 0; j--)
			if(j < n && dp[i][j] > dp[i][j+1]+cost[i][j])
				dp[i][j] = dp[i][j+1]+cost[i][j], pre[i][j].first = i, pre[i][j].second = j+1;
	}
	stack<pair<int, int> > output;
	pair<int, int> now(m, 0);
	int ans = INT_MAX;
	for(int i = 1; i <= n; i++)
		if(ans > dp[m][i])
			ans = dp[m][i], now.second = i;
	output.push(now);
	while(pre[now.first][now.second].second != -1) {
		output.push(pre[now.first][now.second]), now = pre[now.first][now.second];
	}
	while(1) {
		printf("%d", output.top().second);
		output.pop();
		if(output.empty()) {
			putchar('\n');
			break;
		} else 
			putchar(' ');
	}
	return 0;
}
