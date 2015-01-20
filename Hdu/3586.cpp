/*
 * =====================================================================================
 *
 *       Filename:  3586.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/9/16 16:34:04
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

int tail[1010], pre[2010], to[2010], cost[2010], tot;
int dp[1010];

inline void add(int _from, int _to, int _cost) {
	pre[tot] = tail[_from];
	to[tot] = _to;
	cost[tot] = _cost;
	tail[_from] = tot++;
}

void dfs(int now, int fa, int limit) {
	bool bad = false, has_son = false;
	int sum = 0;
	dp[now] = 0x3f3f3f3f;
	for(int i = tail[now]; i != -1; i = pre[i]) {
		int _to = to[i], _cost = cost[i];
		if(_to == fa)
			continue;
		has_son = true;
		dfs(_to, now, limit);
		if(dp[_to] < 0x3f3f3f3f || _cost <= limit) {
			sum += min(dp[_to], _cost);
		} else
			bad = true;
	}
	if(!bad && has_son)
		dp[now] = sum;
}

int main() {
	int n, m;
	while(scanf("%d%d", &n, &m) && n) {
		tot = 0;
		memset(tail, -1, sizeof tail);
		for(int i = 1; i < n; i++) {
			int _u, _v, _cost;
			scanf("%d%d%d", &_u, &_v, &_cost);
			add(_u, _v, _cost);
			add(_v, _u, _cost);
		}
		int l = 0, r = 1000, mid, ans = -1;
		while(l <= r) {
			mid = (l+r) >> 1;
			dfs(1, -1, mid);
			if(dp[1] <= m)
				ans = mid, r = mid-1;
			else
				l = mid+1;
		}
		printf("%d\n", ans);
	}
	return 0;
}
