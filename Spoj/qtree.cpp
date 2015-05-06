/*
 * =====================================================================================
 *
 *       Filename:  qtree.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/2/25 18:01:42
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  winoros (Ding), winoros@gmail.com
 *   Organization:  BUPT
 *
 * =====================================================================================
 */
#include <bits/stdc++.h>

int to[10010<<1], cost[10010<<1], pre[10010<<1], tail[10010];
int e_tot;

inline void add(int _from, int _to, int _cost) {
	to[e_tot] = _to;
	cost[e_tot] = _cost;
	pre[e_tot] = tail[_from];
	tail[_from] = e_tot++;
}

int size[10010], p[10010], dep[10010], chosenSon[10010], chosenCost[10010];
int dfn[10010], top[10010], timestamp;
int baseSeq[10010];

int dfs(int now, int fa, int depth) {
	p[now] = fa, dep[now] = depth;
	size[now] = 0, chosenSon[now] = -1;
	int maxSize = -1;
	for(int i = tail[now]; i != -1; i = pre[i]) {
		if(to[i] == fa)
			continue;
		size[now] += dfs(to[i], now, depth+1);
		if(size[to[i]] > maxSize)
			maxSize = size[to[i]], chosenSon[now] = to[i], chosenCost[now] = cost[i];
	}
	return ++size[now];
}

void getBaseSeq(int now, int val, int fa) {
	dfn[now] = ++timestamp;
	top[now] = fa;
	baseSeq[timestamp] = val;
	if(chosenSon[now] != -1)
		getBaseSeq(chosenSon[now], chosenCost[now], fa);
	for(int i = tail[now]; i != -1; i = pre[i]) {
		if(to[i] == p[now] || to[i] == chosenSon[now])
			continue;
		getBaseSeq(to[i], cost[i], to[i]);
	}
}

void hld(int beg) {
	dfs(beg, -1, 0);
	timestamp = 0;
	getBaseSeq(1, -1, 1);
}

int max[10010<<1];

inline int getidx(int l, int r) {
	return (l + r) | (l != r);
}

inline void upd(int l, int r) {
	int m = (l+r)>>1;
	max[getidx(l, r)] = std::max(max[getidx(l, m)], max[getidx(m+1, r)]);
}

void build(int l, int r) {
	if(l == r) {
		max[getidx(l, r)] = baseSeq[l];
		return ;
	}
	int m = (l+r)>>1;
	build(l, m);
	build(m+1, r);
	upd(l, r);
}

void update(int pos, int val, int l, int r) {
	if(l == pos && r == pos) {
		max[getidx(l, r)] = val;
		return ;
	}
	int m = (l+r)>>1;
	if(pos <= m)
		update(pos, val, l, m);
	else
		update(pos, val, m+1, r);
	upd(l, r);
}

int query(int _l, int _r, int l, int r) {
	if(_l <= l && r <= _r)
		return max[getidx(l, r)];
	int m = (l+r)>>1, ret = -1;
	if(_l <= m)
		ret = std::max(ret, query(_l, _r, l, m));
	if(m < _r)
		ret = std::max(ret, query(_l, _r, m+1, r));
	return ret;
}

int query(int u, int v, int n) {
	int ret = 0;
	while(top[u] != top[v]) {
		if(dep[top[u]] > dep[top[v]])
			std::swap(u, v);
		ret = std::max(ret, query(dfn[top[v]], dfn[v], 1, n));
		v = p[top[v]];
	}
	if(u == v)
		return ret;
	if(dep[u] > dep[v])
		std::swap(u, v);
	ret = std::max(ret, query(dfn[u]+1, dfn[v], 1, n));
	return ret;
}

void MAIN() {
	int n;
	scanf("%d", &n);
	e_tot = 0;
	memset(tail, -1, sizeof tail);
	for(int i = 1, u, v, c; i < n; ++i) {
		scanf("%d%d%d", &u, &v, &c);
		add(u, v, c);
		add(v, u, c);
	}
	hld(1);
	build(1, n);
	char str[10];
	while(scanf("%s", str) && str[0] != 'D') {
		int x, y;
		scanf("%d%d", &x, &y);
		if(str[0] == 'C') {
			x = (x-1)<<1;
			int u = to[x], v = to[x^1];
			if(p[u] == v)
				std::swap(u, v);
			update(dfn[v], y, 1, n);
		}
		else
			printf("%d\n", query(x, y, n));
	}
}

int main() {
	int n;
	scanf("%d", &n);
	while(n--)
		MAIN();
	return 0;
}
