/*
 * =====================================================================================
 *
 *       Filename:  1015.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/12/11 13:39:12
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

int to[200010<<1], pre[200010<<1], tail[200010<<1], tot;

inline void add(int _from, int _to) {
	to[tot] = _to;
	pre[tot] = tail[_from];
	tail[_from] = tot++;
}

int p[200010<<1];

int find(int x) {
	return x == p[x] ? x : p[x] = find(p[x]);
}

int cnt;

void merge(int x, int y) {
	int px = find(x), py = find(y);
	if(px == py)
		return ;
	--cnt;
	p[px] = py;
}

bool block[200010<<1];
int id[200010<<1];
int ans[200010<<1];

int main() {
	memset(tail, -1, sizeof tail);
	memset(block, 0, sizeof block);
	tot = 0;
	int n, m;
	scanf("%d%d", &n, &m);
	cnt = n;
	for(int i = 0; i < n; ++i)
		p[i] = i;
	for(int i = 0, u, v; i < m; ++i) {
		scanf("%d%d", &u, &v);
		add(u, v), add(v, u);
	}
	int q;
	scanf("%d", &q);
	for(int i = 0; i < q; ++i) {
		scanf("%d", id+i);
		block[id[i]] = true;
	}
	for(int i = 0; i < n; ++i)
		if(!block[i])
			for(int idx = tail[i]; idx != -1; idx = pre[idx])
				if(!block[to[idx]])
					merge(i, to[idx]);
	for(int i = q-1; i >= 0; --i) {
		ans[i] = cnt - i - 1;
		block[id[i]] = false;
		for(int idx = tail[id[i]]; idx != -1; idx = pre[idx])
			if(!block[to[idx]])
				merge(id[i], to[idx]);
	}
	printf("%d\n", cnt);
	for(int i = 0; i < q; ++i)
		printf("%d\n", ans[i]);
	return 0;
}
