/*
 * =====================================================================================
 *
 *       Filename:  2743.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/12/7 13:09:52
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

struct node {
	int x, y, idx;
	friend bool operator < (node a, node b) {
		return a.y < b.y;
	}
};

node q[1000010];
int bit[1000010], n, a[1000010];
int ans[1000010];
int pre[1000010], last[1000010];

void update(int pos, int val) {
	for(; pos <= n; pos += pos & (-pos))
		bit[pos] += val;
}

int query(int pos) {
	int ret = 0;
	for(; pos > 0; pos -= pos & (-pos))
		ret += bit[pos];
	return ret;
}

int main() {
	int c, m;
	scanf("%d%d%d", &n, &c, &m);
	memset(pre, 0, sizeof pre);
	memset(last, 0, sizeof last);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", a+i);
		pre[i] = last[a[i]];
		last[a[i]] = i;
	}
	for(int i = 0; i < m; ++i) {
		scanf("%d%d", &q[i].x, &q[i].y);
		q[i].idx = i;
	}
	sort(q, q+m);
	for(int i = 0, now = 1; i < m; ++i) {
		for(; now <= q[i].y; ++now) 
			update(pre[pre[now]]+1, 1), update(pre[now]+1, -1);
		ans[q[i].idx] = query(q[i].x);
	}
	for(int i = 0; i < m; ++i)
		printf("%d\n", ans[i]);
	return 0;
}
