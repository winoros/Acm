/*
 * =====================================================================================
 *
 *       Filename:  qtree2.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/3/13 21:51:23
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

int dis[10010<<1]; //distance from root;
int p[10010][16], dep[10010];

void dfs(int now) {
	for(int i = tail[now]; i != -1; i = pre[i]) {
		if(to[i] == p[now][0])
			continue;
		p[to[i]][0] = now, dep[to[i]] = dep[now] + 1;
		for(int j = 1; j < 16; ++j)
			p[to[i]][j] = p[p[to[i]][j-1]][j-1];
		dis[to[i]] = dis[now] + cost[i];
		dfs(to[i]);
	}
}

int queryLca(int u, int v) {
	if(dep[u] > dep[v])
		std::swap(u, v);
	for(int delta = dep[v] - dep[u], i = 0; delta; delta >>= 1, ++i) {
		if(delta&1)
			v = p[v][i];
	}
	if(u == v)
		return u;
	for(int i = 15; i >= 0; --i) {
		if(p[u][i] == p[v][i])
			continue;
		u = p[u][i], v = p[v][i];
	}
	return p[u][0];
}

int getKthAncestor(int u, int k) {
	for(int i = 0; k; ++i, k>>=1)
		if(k&1)
			u = p[u][i];
	return u;
}

int kthNode(int u, int v, int k) {
	int lca = queryLca(u, v);
	if(dep[u] - dep[lca] + 1 >= k)
		return k == 1 ? u : getKthAncestor(u, k-1);
	k -= dep[u] - dep[lca] + 1;
	if(k <= dep[v] - dep[lca])
		return k == dep[v] - dep[lca] ? v : getKthAncestor(v, dep[v] - dep[lca] - k);
	else
		return -1;
}

void MAIN() {
	int n;
	scanf("%d", &n);
	memset(tail, -1, sizeof tail);
	e_tot = 0;
	for(int i = 1, u, v, c; i < n; ++i) {
		scanf("%d%d%d", &u, &v, &c);
		add(u, v, c);
		add(v, u, c);
	}
	dis[1] = 0, dep[1] = 0;
	for(int i = 0; i < 16; ++i)
		p[1][i] = 1;
	dfs(1);
	char str[10];
	while(scanf("%s", str) && str[1] != 'O') {
		int x, y;
		scanf("%d%d", &x, &y);
		if(str[0] == 'D')
			printf("%d\n", dis[x] + dis[y] - 2*dis[queryLca(x, y)]);
		else {
			int z;
			scanf("%d", &z);
			printf("%d\n", kthNode(x, y, z));
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	while(n--)
		MAIN();
	return 0;
}
