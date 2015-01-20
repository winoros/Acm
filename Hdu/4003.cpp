/*
 * =====================================================================================
 *
 *       Filename:  4003.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/9/15 13:58:21
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

int tail[10010], to[20010], pre[20010], cost[20010], tot;
int dp[10010][15];
int m;

void add(int _from, int _to, int _cost) {
	pre[tot] = tail[_from];
	to[tot] = _to;
	cost[tot] = _cost;
	tail[_from] = tot++;
}

void dfs(int now, int fa) {
	memset(dp[now], 0, sizeof dp[now]);
	for(int i = tail[now]; i != -1; i = pre[i]) {
		int _to = to[i], _cost = cost[i];
		if(_to == fa) continue;
		dfs(_to, now);
		for(int j = m; j >= 0; j--) {
			dp[now][j] += dp[_to][0] + 2*_cost;
			for(int k = 1; k <= j; k++)
				dp[now][j] = min(dp[now][j], dp[now][j-k] + dp[_to][k] + k*_cost);
		}
	}
}

int main() {
	int n, src;
	while(scanf("%d%d%d", &n, &src, &m) != EOF) {
		tot = 0;
		memset(tail, -1, sizeof tail);
		for(int i = 1; i < n; i++) {
			int _u, _v, _cost;
			scanf("%d%d%d", &_u, &_v, &_cost);
			add(_u, _v, _cost);
			add(_v, _u, _cost);
		}
		dfs(src, -1);
		printf("%d\n", dp[src][m]);
	}
	return 0;
}

