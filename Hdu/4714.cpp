/*
 * =====================================================================================
 *
 *       Filename:  4714.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/9/24 0:07:01
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

int tail[1000010], pre[1000010<<1], to[1000010<<1], tot;

inline void add(int _from, int _to) {
	pre[tot] = tail[_from];
	to[tot] = _to;
	tail[_from] = tot++;
}

int dp[1000010][2];

void dfs(int now, int fa) {
	dp[now][0] = dp[now][1] = 0;
	int first = 0, second = 0, tot_cost = 0;
	for(int i = tail[now]; i != -1; i = pre[i]) {
		int _to = to[i];
		if(_to == fa)
			continue;
		dfs(_to, now);
		tot_cost += dp[_to][1] + 2;
		int delta = dp[_to][1] + 2 - dp[_to][0];
		if(delta > first) {
			second = first;
			first = delta;
		} else if(delta > second) {
			second = delta;
		}
	}
	dp[now][0] = tot_cost - first;
	dp[now][1] = dp[now][0] - second;
}

int main() {
	int nn;
	for(scanf("%d", &nn); nn--; ) {
		int n;
		scanf("%d", &n);
		memset(tail, -1, sizeof(int)*(n+5));
		tot = 0;
		for(int i = 1; i < n; i++) {
			int _u, _v;
			scanf("%d%d", &_u, &_v);
			add(_u, _v);
			add(_v, _u);
		}
		dfs(1, -1);
		printf("%d\n", dp[1][1] + 1);
	}
	return 0;
}
