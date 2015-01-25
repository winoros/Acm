/*
 * =====================================================================================
 *
 *       Filename:  2468.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/1/25 11:24:26
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  winoros (Ding), winoros@gmail.com
 *   Organization:  BUPT
 *
 * =====================================================================================
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <utility>
#include <map>
#include <set>
#include <cctype>
#include <climits>
#include <stack>
#include <cmath>
#include <bitset>
#include <numeric>
#include <functional>

using namespace std;

int to[110<<1], pre[110<<1], tail[110];
int tot;

inline void add(int _from, int _to) {
	to[tot] = _to;
	pre[tot] = tail[_from];
	tail[_from] = tot++;
}

int dp[110][220][2], val[110];

void dfs(int now, int fa, int k) {
	memset(dp[now], 0, sizeof dp[now]);
	for(int i = 0; i <= k; ++i)
		dp[now][i][0] = dp[now][i][1] = val[now];
	for(int i = tail[now]; i != -1; i = pre[i]) {
		if(to[i] == fa)
			continue;
		dfs(to[i], now, k);
		for(int j = k; j >= 0; --j) {
			for(int l = 0; l <= j; ++l) {
				dp[now][j+2][1] = max(dp[now][j+2][1], dp[now][j-l][1] + dp[to[i]][l][1]);
				dp[now][j+1][0] = max(dp[now][j+1][0], dp[now][j-l][1] + dp[to[i]][l][0]);
				dp[now][j+2][0] = max(dp[now][j+2][0], dp[now][j-l][0] + dp[to[i]][l][1]);
			}
		}
	}
}

void MAIN(int n, int k) {
	for(int i = 1; i <= n; ++i)
		scanf("%d", &val[i]);
	memset(tail, -1, sizeof tail);
	tot = 0;
	for(int i = 1, u, v; i < n; ++i) {
		scanf("%d%d", &u, &v);
		add(u, v);
		add(v, u);
	}
	dfs(1, -1, k);
	printf("%d\n", dp[1][k][0]);
}

int main() {
	int n, k;
	while(scanf("%d%d", &n, &k) > 0)
		MAIN(n, k);
	return 0;
}
