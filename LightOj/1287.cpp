/*
 * =====================================================================================
 *
 *       Filename:  1287.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/12/2 11:17:05
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

int to[150<<1], cost[150<<1], tail[20], pre[150<<1];
int tot, n;

inline void add(int _from, int _to, int _cost) {
	to[tot] = _to;
	cost[tot] = _cost;
	pre[tot] = tail[_from];
	tail[_from] = tot++;
}

double dp[1<<16][16];

bool dfs(int state, int now_pos) {
	double &ret = dp[state][now_pos];
	if(state == (1<<n)-1) {
		ret = 0;
		return true;
	}
	if(ret > -0.5)
		return ret > 1e-10;
	ret = 0;
	int go = 0;
	for(int idx = tail[now_pos]; idx != -1; idx = pre[idx]) {
		if((state>>to[idx]) & 1)
			continue;
		else if(dfs(state | (1<<to[idx]), to[idx]))
			++go, ret += dp[state|(1<<to[idx])][to[idx]] + cost[idx];
	}
	if(!go) {
		ret = 0;
		return false;
	}
	else {
		ret = (5 + ret) / go;
		return true;
	}
}

int main() {
	int nn;
	scanf("%d", &nn);
	for(int ii = 1; ii <= nn; ++ii) {
		memset(tail, -1, sizeof tail);
		tot = 0;
		int m;
		scanf("%d%d", &n, &m);
		for(int i = 0; i < m; ++i) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			add(u, v, w);
			add(v, u, w);
		}
		memset(dp, -1, sizeof dp);
		dfs(1, 0);
		printf("Case %d: %.11f\n", ii, dp[1][0]);
	}
}
