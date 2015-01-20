/*
 * =====================================================================================
 *
 *       Filename:  4616.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/9/29 16:02:40
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

int tail[50010], to[50010<<1], pre[50010<<1], tot;

inline void add(int _from, int _to) {
	pre[tot] = tail[_from];
	to[tot] = _to;
	tail[_from] = tot++;
}

int weight[50010], value[50010];
int dp[50010][5];
int n, m, ans;

void dfs(int now, int fa) {
	memset(dp[now], 0, sizeof dp[now]);
	for(int i = tail[now]; i != -1; i = pre[i]) {
		int _to = to[i];
		if(_to == fa)
			continue;
		dfs(_to, now);
		for(int i = 3; i >= 0; i--) {
			for(int j = 0; j <= i; j++)
				dp[now][i] = max(dp[now][i], dp[_to][j] + dp[now][i-j]);
		}
	}
	if(weight[now]) {
		for(int i = 3; i >= 1; i--)
			dp[now][i] = dp[now][i-1] + value[now];
		dp[now][0] = 0;
	} else {
		for(int i = 3; i >= 1; i--)
			dp[now][i] += value[now];
	}
	ans = max(ans, dp[now][m]);
}

int main() {
	int nn;
	for(scanf("%d", &nn); nn--; ) {
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; i++)
			scanf("%d%d", &value[i], &weight[i]);
		tot = 0;
		memset(tail, -1, sizeof(int)*(n+5));
		for(int i = 1; i < n; i++) {
			int _u, _v;
			scanf("%d%d", &_u, &_v);
			add(_u, _v);
			add(_v, _u);
		}
		ans = 0;
		dfs(0, -1);
		/* 
		for(int i = 0; i < n; i++)
			for(int j = 0; j <= m; j++)
				printf("%d%c", dp[i][j], j == m ? '\n' : ' ');
				*/
		printf("%d\n", ans);
	}
}

