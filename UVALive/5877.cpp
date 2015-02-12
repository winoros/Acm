/*
 * =====================================================================================
 *
 *       Filename:  5877.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/2/12 13:36:11
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

const double eps = 1e-8;

vector<int> v[1010];
int dis[1010];

void bfs(int st, int ed) {
	queue<int> q;
	memset(dis, 0x3f, sizeof dis);
	dis[st] = 0;
	q.push(st);
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		if(now == ed)
			break;
		int sz = v[now].size();
		for(int i = 0; i < sz; ++i)
			if(dis[v[now][i]] == 0x3f3f3f3f)
				dis[v[now][i]] = dis[now] + 1, q.push(v[now][i]);
	}
}

pair<double, double> p[1010];

void MAIN() {
	int n, st, ed;
	double l1, l2;
	scanf("%d%d%d%lf%lf", &n, &st, &ed, &l1, &l2);
	for(int i = 1; i <= n; ++i)
		v[i].clear();
	for(int i = 1; i <= n; ++i)
		scanf("%lf%lf", &p[i].first, &p[i].second);
	double maxx = l1+l2;
	for(int i = 1; i <= n; ++i)
		for(int j = i+1; j <= n; ++j)
			if(sqrt((p[i].first - p[j].first)*(p[i].first - p[j].first) + (p[i].second - p[j].second)*(p[i].second - p[j].second)) <= maxx+eps)
				v[i].push_back(j), v[j].push_back(i);
	bfs(st, ed);
	if(dis[ed] == 0x3f3f3f3f)
		puts("Impossible");
	else
		printf("%d\n", dis[ed]);
}

int main() {
	int n;
	scanf("%d", &n);
	while(n--)
		MAIN();
	return 0;
}
