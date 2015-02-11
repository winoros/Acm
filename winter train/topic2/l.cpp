/*
 * =====================================================================================
 *
 *       Filename:  l.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/2/11 18:28:06
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
	for(int i = 1; i <= n; ++i)
		p[i] = i, dis[i] = 0;
}

int find(int x) {
	if(p[x] == x)
		return x;
	int tmp = p[x];
	p[x] =find(p[x]);
	dis[x] += dis[tmp];
	return p[x];
}

void merge(int x, int y, int val) {
	int px = find(x), py = find(y);
	if(px == py)
		return ;
	p[px] = py;
	dis[px] = dis[y]+val-dis[x];
}

void MAIN(int n, int m) {
	init(n);
	char str[2];
	int a, b, c;
	while(m--) {
		scanf("%s%d%d", str, &a, &b);
		if(str[0] == '!') {
			scanf("%d", &c);
			merge(a, b, c);
		} else {
			int pa = find(a), pb = find(b);
			if(pa != pb)
				puts("UNKNOWN");
			else
				printf("%lld\n", dis[a] - dis[b]);
		}
	}
}

int main() {
	int n, m;
	while(scanf("%d%d", &n, &m) && n != 0)
		MAIN(n, m);
	return 0;
}
