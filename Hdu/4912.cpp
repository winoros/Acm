/*
 * =====================================================================================
 *
 *       Filename:  4912.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/12/17 22:30:03
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

int to[100010<<1], pre[100010<<1], tail[100010], tot;

inline void add(int _from, int _to) {
	to[tot] = _to;
	pre[tot] = tail[_from];
	tail[_from] = tot++;
}

int fa[100010][19], deg[100010];

void bfs() {
	queue<int> q;
	q.push(1);
	fa[1][0] = 1;
	deg[1] = 0;
	while(!q.empty()) {
		int now = q.front(); q.pop();
		for(int i = 1; i < 19; ++i)
			fa[now][i] = fa[fa[now][i-1]][i-1];
		for(int i = tail[now]; i != -1; i = pre[i]) {
			if(to[i] == fa[now][0])
				continue;
			fa[to[i]][0] = now;
			deg[to[i]] = deg[now]+1;
			q.push(to[i]);
		}
	}
}

int lca(int u, int v) {
	if(deg[u] > deg[v])
		swap(u, v);
	for(int delta = deg[v] - deg[u], i = 0; delta; delta>>=1, ++i)
		if(delta&1)
			v = fa[v][i];
	if(u == v)
		return u;
	for(int i = 18; i >= 0; --i) {
		if(fa[u][i] == fa[v][i])
			continue;
		u = fa[u][i], v= fa[v][i];
	}
	return fa[u][0];
}

bool vis[100010];

void cover(int now) {
	if(vis[now])
		return ;
	vis[now] = true;
	for(int i = tail[now]; i != -1; i = pre[i])
		if(to[i] != fa[now][0])
			cover(to[i]);
}


struct node {
	int u, v, lca;
};

bool cmp(node a, node b) {
	return deg[a.lca] > deg[b.lca];
}

node q[100010];

int main() {
	int n, m;
	while(scanf("%d%d", &n, &m) == 2) {
		memset(tail, -1, sizeof tail);
		tot = 0;
		for(int i = 1, u, v; i < n; ++i) {
			scanf("%d%d", &u, &v);
			add(u, v), add(v, u);
		}
		bfs();
		for(int i = 0; i < m; ++i) {
			scanf("%d%d", &q[i].u, &q[i].v);
			q[i].lca = lca(q[i].u, q[i].v);
		}
		sort(q, q+m, cmp);
		int ans = 0;
		memset(vis, false, sizeof vis);
		for(int i = 0; i < m; ++i) {
			if(vis[q[i].u] || vis[q[i].v])
				continue;
			++ans;
			cover(q[i].lca);
		}
		printf("%d\n", ans);
	}
	return 0;
}
