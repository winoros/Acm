/*
 * =====================================================================================
 *
 *       Filename:  1060.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/10/20 20:20:18
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

int tot, tail[500010], to[500010<<1], cost[500010<<1], pre[500010<<2];

inline void add(int _from, int _to, int _cost) {
	pre[tot] = tail[_from];
	to[tot] = _to;
	cost[tot] = _cost;
	tail[_from] = tot++;
}

long long first[500010];
long long ans;

void dfs(int now, int fa) {
	first[now] = 0;
	for(int i = tail[now]; i != -1; i = pre[i]) {
		int _to = to[i], _cost = cost[i];
		if(_to == fa)
			continue;
		dfs(_to, now);
		if(first[_to] + _cost > first[now])
			first[now] = first[_to] + _cost;
	}
	for(int i = tail[now]; i != -1; i = pre[i]) {
		if(to[i] == fa)
			continue;
		ans += first[now] - first[to[i]] - cost[i];
	}
}

int main() {
	int n, root;
	scanf("%d%d", &n, &root);
	tot = 0;
	memset(tail, -1, sizeof tail);
	for(int i = 1; i < n; ++i) {
		int _u, _v, _cost;
		scanf("%d%d%d", &_u, &_v, &_cost);
		add(_u, _v, _cost);
		add(_v, _u, _cost);
	}
	ans = 0;
	dfs(root, -1);
	printf("%I64d\n", ans);
	return 0;
}
