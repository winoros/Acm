/*
 * =====================================================================================
 *
 *       Filename:  100402g.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/3/10 19:48:10
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  winoros (Ding), winoros@gmail.com
 *   Organization:  BUPT
 *
 * =====================================================================================
 */
#include <bits/stdc++.h>

struct node {
	int a, b;
    long long val;
	friend bool operator < (node lhs, node rhs) {
		return lhs.val > rhs.val;
	}
};

node q[100010];

long long a[100010], min[100010];
int next[100010];
bool used[100010];

int find(int x) {
	return next[x] == x ? x : next[x] = find(next[x]);
}

void merge(int x, int y) {
	int nextx = find(x), nexty = find(y);
	min[nexty] = std::min(min[nexty], min[nextx]);
	next[nextx] = nexty;
}

void MAIN() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; ++i)
		scanf("%d%d%I64d", &q[i].a, &q[i].b, &q[i].val);
	std::sort(q, q+m);
	for(int i = 1; i <= n; ++i)
		next[i] = i, min[i] = (1LL<<31)-1;
	for(int i = 0; i < m; ++i) {
		int ok = false;
		//printf("%d__%d\n", q[i].a, q[i].b);
		for(int j = q[i].a; j <= q[i].b; ++j) {
			//printf("%d_____________\n", j);
			if(!used[j]) {
				used[j] = true;
				ok = true;
				a[j] = min[j] = q[i].val;
				merge(q[i].a, j);
			} else {
				ok |= min[find(j)] == q[i].val;
				merge(q[i].a, j);
				j = find(j);
			}
		}
		if(!ok) {
			puts("inconsistent");
			return ;
		}
	}
	puts("consistent");
	for(int i = 1; i <= n; ++i) {
		printf("%I64d%c", a[i], i == n ? '\n' : ' ');
	}
}

int main() {
	MAIN();
	return 0;
}
