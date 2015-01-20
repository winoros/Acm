/*
 * =====================================================================================
 *
 *       Filename:  2333.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/12/4 23:27:45
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

#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1

int maxx[300010<<2], delta[300010<<2];
int n, a[300010], pos[300010];

inline void push_up(int rt) {
	maxx[rt] = max(maxx[rt<<1], maxx[rt<<1|1]);
}

void build(int l = 1, int r = n, int rt = 1) {
	if(l == r) {
		delta[rt] = 0;
		maxx[rt] = a[l];
		return ;
	}
	int m = (l+r)>>1;
	build(lson);
	build(rson);
	push_up(rt);
}

inline void push_down(int rt) {
	if(delta[rt]) {
		maxx[rt<<1] += delta[rt];
		maxx[rt<<1|1] += delta[rt];
		delta[rt<<1] += delta[rt];
		delta[rt<<1|1] += delta[rt];
		delta[rt] = 0;
	}
}

void update(int _l, int _r, int val, int l = 1, int r = n, int rt = 1) {
	if(_l <= l && r <= _r) {
		maxx[rt] += val;
		delta[rt] += val;
		return ;
	}
	push_down(rt);
	int m = (l+r)>>1;
	if(_l <= m) update(_l, _r, val, lson);
	if(m < _r) update(_l, _r, val, rson);
	push_up(rt);
}

int query(int _l, int _r, int l = 1, int r = n, int rt = 1) {
	int ret = -1000000000;
	if(_l <= l && r <= _r) {
		return maxx[rt];
	}
	push_down(rt);
	int m = (l+r)>>1;
	if(_l <= m) ret = query(_l, _r, lson);
	if(m < _r) ret = max(ret, query(_l, _r, rson));
	return ret;
}

int p[300010], next[300010], end[300010];
struct node {
	char op[5];
	int x, y;
}q[300010];

int find(int x) {
	return x == p[x] ? x : p[x] = find(p[x]);
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", a+i);
	for(int i = 1; i <= n; ++i)
		p[i] = next[i] = end[i] = i;
	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; ++i) {
		scanf("%s", q[i].op);
		if(q[i].op[0] == 'U') {
			scanf("%d%d", &q[i].x, &q[i].y);
			int px = find(q[i].x), py = find(q[i].y);
			if(px > py) swap(px, py);
			p[py] = px;
			next[end[px]] = py;
			end[px] = end[py];
		} else if(q[i].op[0] == 'A') {
			scanf("%d", &q[i].x);
			if(q[i].op[1] != '3')
				scanf("%d", &q[i].y);
		} else {
			if(q[i].op[1] != '3')
				scanf("%d", &q[i].x);
		}
	}
	int cnt = 0;
	memset(end, 0, sizeof end);
	for(int i = 1; i <= n; ++i)
		for(int now = i; !end[now]; now = next[now])
			pos[now] = end[now] = ++cnt, p[now] = now;
	for(int i = 1; i <= n; ++i)
		next[i] = a[i];
	for(int i = 1; i <= n; ++i)
		a[pos[i]] = next[i];
	build();
	for(int i = 0; i < m; ++i) {
		if(q[i].op[0] == 'U') {
			int px = find(q[i].x), py = find(q[i].y);
			if(px > py) swap(px, py);
			p[py] = px;
			end[px] = end[py];
		} else if(q[i].op[0] == 'A') {
			if(q[i].op[1] == '1')
				update(pos[q[i].x], pos[q[i].x], q[i].y);
			else if(q[i].op[1] == '2') {
				int px = find(q[i].x);
				update(pos[px], end[px], q[i].y);
			}
			else
				update(1, n, q[i].x);
		} else {
			if(q[i].op[1] == '1')
				printf("%d\n", query(pos[q[i].x], pos[q[i].x]));
			else if(q[i].op[1] == '2') {
				int px = find(q[i].x);
				printf("%d\n", query(pos[px], end[px]));
			} else
				printf("%d\n", query(1, n));
		}
	}
	return 0;
}
