/*
 * =====================================================================================
 *
 *       Filename:  g.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/4/11 16:23:22
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  winoros (Ding), winoros@gmail.com
 *   Organization:  BUPT
 *
 * =====================================================================================
 */
#include <bits/stdc++.h>

int to[100010<<1], pre[100010<<1], tail[100010];
int e_tot;

static inline void add(int _from, int _to) {
	to[e_tot] = _to;
	pre[e_tot] = tail[_from];
	tail[_from] = e_tot++;
}

int downCnt[100010][11], upCnt[100010][11];

void dfs(int now, int fa) {
	downCnt[now][0] = upCnt[now][0] = 1;
	for(int i = tail[now]; i != -1; i = pre[i]) {
		if(to[i] == fa)
			continue;
		dfs(to[i], now);
		for(int j = 0; j < 10; ++j)
			downCnt[now][j+1] += downCnt[to[i]][j];
	}
}

void dfss(int now, int fa) {
	for(int i = tail[now]; i != -1; i = pre[i]) {
		if(to[i] == fa)
			continue;
		for(int j = 0; j < 10; ++j)
			upCnt[to[i]][j+1] = upCnt[now][j] + downCnt[now][j] - (j == 0 ? 1 : downCnt[to[i]][j-1]);
		dfss(to[i], now);
	}
}

void MAIN(int n, int q) {
	memset(tail, -1, sizeof tail);
	e_tot = 0;
	for(int i = 1, u, v; i < n; ++i) {
		scanf("%d%d", &u, &v);
		add(u, v);
		add(v, u);
	}
	for(int i = 1; i <= n; ++i) {
		memset(downCnt[i], 0, sizeof downCnt[i]);
		memset(upCnt[i], 0, sizeof upCnt[i]);
	}
	dfs(1, -1);
	dfss(1, -1);
	//for(int i = 1; i <= n; ++i)
	//	for(int j = 0; j < 11; ++j)
	//		printf("%d__%d%c", downCnt[i][j], upCnt[i][j], j == 10 ? '\n' : ' ');
	for(int i = 0, pos, d; i < q; ++i) {
		scanf("%d%d", &pos, &d);
		printf("%d\n", downCnt[pos][d] + upCnt[pos][d] - (d == 0 ? 1 : 0));
	}
}

int main() {
	int n, q;
	while(scanf("%d%d", &n, &q) == 2)
		MAIN(n, q);
	return 0;
}
