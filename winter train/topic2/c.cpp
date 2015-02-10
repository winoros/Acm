/*
 * =====================================================================================
 *
 *       Filename:  c.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/2/10 12:13:32
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

int p[300], a[300][2];

int find(int x) {
	return x == p[x] ? x : p[x] = find(p[x]);
}

void merge(int x, int y) {
	int px = find(x), py = find(y);
	if(x == y)
		return ;
	p[px] = py;
}

struct edge {
	int x, y;
	double dis;
	bool operator < (const edge &lhs) const {
		return dis < lhs.dis;
	}
};

inline double d(int i, int j) {
	return sqrt(1.0*(a[i][0]-a[j][0])*(a[i][0]-a[j][0]) + 1.0*(a[i][1]-a[j][1])*(a[i][1]-a[j][1]));
}

edge e[200*200/2];

void MAIN(int n) {
	for(int i = 0; i < n; ++i)
		p[i] = i, scanf("%d%d", &a[i][0], &a[i][1]);
	int e_cnt = 0;
	for(int i = 0; i < n; ++i)
		for(int j = i+1; j < n; ++j) {
			e[e_cnt].x = i, e[e_cnt].y = j, e[e_cnt].dis = d(i, j);
			++e_cnt;
		}
	sort(e, e+e_cnt);
	double ans = 0;
	for(int i = 0; i < e_cnt; ++i) {
		merge(e[i].x, e[i].y);
		int p0 = find(0), p1 = find(1);
		if(p0 == p1) {
			ans = e[i].dis;
			break;
		}
	}
	printf("%.3f\n", ans);
}

int main() {
	int n, cnt = 0;
	for(scanf("%d", &n); n != 0; ) {
		printf("Scenario #%d\nFrog Distance = ", ++cnt);
		MAIN(n);
		scanf("%d", &n);
		if(n != 0)
			puts("");
	}
	return 0;
}
