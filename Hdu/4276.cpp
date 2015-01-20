/*
 * =====================================================================================
 *
 *       Filename:  4276.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/9/16 17:15:34
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

int tail[110], pre[210], to[210], cost[210], thing[110], tot;
int dp[110][510];
int n, m ,t;
bool bigger;

inline void add(int _from, int _to, int _cost) {
	pre[tot] = tail[_from];
	to[tot] = _to;
	cost[tot] = _cost;
	tail[_from] = tot++;
}

bool dfs(int now, int fa) {
	bool check = now == n ? true : false;
	if(bigger) return false;
	for(int i = 0; i <= m; i++)
		dp[now][i] = thing[now];
	for(int i = tail[now]; i != -1; i = pre[i]) {
		int _to = to[i], _cost = cost[i];
		if(_to == fa)
			continue;
		if(dfs(_to, now))
			t += _cost, _cost = 0, check = true;
		if(t > m) {
			bigger = true;
			return false;
		}
		for(int j = m; j >= _cost*2; j--) {
			for(int k = 0; k <= j - _cost*2; k++)
				dp[now][j] = max(dp[now][j], dp[now][j - 2*_cost - k] + dp[_to][k]);
		}
	}
	return check;
}

int main() {
	while(scanf("%d%d", &n, &m) != EOF) {
		tot = 0;
		memset(tail, -1, sizeof tail);
		for(int i = 1; i < n; i++) {
			int _u, _v, _cost;
			scanf("%d%d%d", &_u, &_v, &_cost);
			add(_u, _v, _cost);
			add(_v, _u, _cost);
		}
		for(int i = 1; i <= n; i++)
			scanf("%d", &thing[i]);
		t = 0;
		bigger = false;
		dfs(1, -1);
		if(bigger)
			puts("Human beings die in pursuit of wealth, and birds die in pursuit of food!");
		else
			printf("%d\n", dp[1][m-t]);
	}
	return 0;
}
