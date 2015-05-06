/*
 * =====================================================================================
 *
 *       Filename:  qtree3.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/3/16 12:33:09
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

inline void add(int _from, int _to) {
	to[e_tot] = _to;
	pre[e_tot] = tail[_from];
	tail[_from] = e_tot++;
}

int lowDfn[100010<<1], highDfn[100010<<1];
int timestamp;
int p[100010][18];

void dfs(int now, int fa) {
	lowDfn[now] = ++timestamp;
	p[now][0] = fa;
	for(int i = 1; i < 18; ++i)
		p[now][i] = p[p[now][i-1]][i-1];
	for(int i = tail[now]; i != -1; i = pre[i]) {
		if(to[i] == fa)
			continue;
		dfs(to[i], now);
	}
	highDfn[now] = ++timestamp;
}

int bit[100010<<1];

void update(int pos, bool positive, int n) {
	for(; pos <= n; pos += pos & (-pos))
		bit[pos] += positive ? 1 : -1;
}

int query(int pos) {
	int ret = 0;
	for(; pos > 0; pos -= pos & (-pos))
		ret += bit[pos];
	return ret;
}

int getAns(int now) {
	if(query(lowDfn[now]) == 0)
		return -1;
	else {
		for(int i = 17; i >= 0; --i)
			if(query(lowDfn[p[now][i]]) > 0)
				now = p[now][i];
		return now;
	}
}

bool black[100010];

void MAIN() {
	int n, m;
	scanf("%d%d", &n, &m);
	memset(tail, -1, sizeof tail);
	e_tot = 0;
	for(int i = 1, u, v; i < n; ++i) {
		scanf("%d%d", &u, &v);
		add(u, v);
		add(v, u);
	}
	timestamp = 0;
	dfs(1, 1);
	memset(bit, 0, sizeof bit);
	memset(black, false, sizeof black);
	for(int i = 0, op, x; i < m; ++i) {
		scanf("%d%d", &op, &x);
		if(op == 1)
			printf("%d\n", getAns(x));
		else {
			if(black[x])
				update(lowDfn[x], black[x] = false, timestamp), update(highDfn[x], true, timestamp);
			else
				update(lowDfn[x], black[x] = true, timestamp), update(highDfn[x], false, timestamp);
		}
	}
}

int main() {
	MAIN();
	return 0;
}
