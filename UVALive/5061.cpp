/*
 * =====================================================================================
 *
 *       Filename:  5061.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/2/13 12:33:27
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

int to[50010<<1], pre[50010<<1], tail[50010];
int e_tot;

inline void add(int _from, int _to) {
	to[e_tot] = _to;
	pre[e_tot] = tail[_from];
	tail[_from] = e_tot++;
}

int p[50010][17], deg[50010];

void bfs() {
	queue<int> q;
	q.push(0);
	p[0][0] = 0;
	deg[0] = 0;
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		for(int i = 1; i < 17; ++i)
			p[now][i] = p[p[now][i-1]][i-1];
		for(int i = tail[now]; i != -1; i = pre[i]) {
			if(to[i] == p[now][0])
				continue;
			p[to[i]][0] = now;
			deg[to[i]] = deg[now] + 1;
			q.push(to[i]);
		}
	}
}

int lca(int u, int v) {
	if(deg[u] > deg[v])
		swap(u, v);
	for(int delta = deg[v] - deg[u], i = 0; delta != 0; delta >>= 1, ++i)
		if(delta&1)
			v = p[v][i];
	if(u == v)
		return u;
	for(int i = 16; i >= 0; --i) {
		if(p[u][i] == p[v][i])
			continue;
		u = p[u][i], v = p[v][i];
	}
	return p[u][0];
}

int ans[50010], val[50010];

int dfs(int now, int fa) {
	ans[now] = val[now];
	for(int i = tail[now]; i != -1; i = pre[i]) {
		if(to[i] == fa)
			continue;
		ans[now] += dfs(to[i], now);
	}
	return ans[now];
}

void MAIN() {
	int n;
	scanf("%d", &n);
	memset(tail, -1, sizeof tail);
	e_tot = 0;
	for(int i = 1, u, v; i < n; ++i) {
		scanf("%d%d",&u, &v);
		add(u, v);
		add(v, u);
	}
	bfs();
	int m;
	scanf("%d", &m);
	memset(val, 0, sizeof val);
	for(int i = 0, u, v, c; i < m; ++i) {
		scanf("%d%d%d", &u, &v, &c);
		val[u] += c;
		val[v] += c;
		int lcaa = lca(u, v);
		val[lcaa] -= c;
		if(lcaa != 0)
			val[p[lcaa][0]] -= c;
	}
	dfs(0, -1);
	for(int i = 0; i < n; ++i)
		printf("%d\n", ans[i]);
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		printf("Case #%d:\n", i);
		MAIN();
	}
	return 0;
}
