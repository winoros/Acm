/*
 * =====================================================================================
 *
 *       Filename:  n.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/2/11 20:55:28
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

int p[100010];
long long dis[100010];

void init(int n) {
	for(int i = 0; i <= n; ++i)
		p[i] = i, dis[i] = 0;
}

int find(int x) {
	if(p[x] == x) 
		return x;
	int tmp = p[x];
	p[x] = find(p[x]);
	dis[x] += dis[tmp];
	return p[x];
}

void merge(int x, int y, int val) {
	int px = find(x), py = find(y);
	if(px == py)
		return ;
	if(px > py) {
		p[py] = px;
		dis[py] = (dis[x] - val - dis[y]);
	} else {
		p[px] = py;
		dis[px] = (dis[y] + val - dis[x]);
	}
}

void MAIN() {
	int n, m;
	scanf("%d%d", &n, &m);
	init(n);
	while(m--) {
		int a, b, sum;
		scanf("%d%d%d", &a, &b, &sum);
		++b;
		int pa = find(a), pb = find(b);
		if(pa == pb && dis[a] - dis[b] != sum)
			puts("Error!");
		else {
			puts("Accepted!");
			if(pa != pb)
				merge(a, b, sum);
		}
	}
	for(int i = 1; i <= n; ++i) {
		int pi = find(i), pii = find(i+1);
		if(pi != pii)
			puts("Unknown!");
		else
			printf("%lld\n", dis[i] - dis[i+1]);
	}
}

int main() {
	MAIN();
	return 0;
}
