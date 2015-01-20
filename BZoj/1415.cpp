/*
 * =====================================================================================
 *
 *       Filename:  1415.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/11/18 22:44:46
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

vector<int> v[1010];
double dp[1010][1010];
int next[1010][1010];
int dis[1010];
queue<int> q;

void bfs(int src) {
	while(!q.empty())
		q.pop();
	memset(dis, 0x3f, sizeof dis);
	dis[src] = 0;
	for(int i = 0; i < v[src].size(); ++i)
		dis[v[src][i]] = 1, next[src][v[src][i]] = v[src][i], q.push(v[src][i]);
	while(!q.empty()) {
		int now = q.front(); q.pop();
		int sz = v[now].size();
		for(int i = 0; i < sz; ++i) {
			int to = v[now][i];
			if(dis[now] + 1 < dis[to])
				q.push(to), next[src][to] = next[src][now], dis[to] = dis[now]+1;
			else if(dis[now] + 1 == dis[to] && next[src][now] < next[src][to])
				next[src][to] = next[src][now];
		}
	}
}

double dfs(int i, int j) {
	double &ret = dp[i][j];
	if(ret > -0.5)
		return ret;
	if(i == j)
		return ret = 0;
	if(next[i][j] == j || next[next[i][j]][j] == j)
		return ret = 1;
	ret = 0;
	int sz = v[j].size();
	for(int ii = 0; ii < sz; ++ii) {
		ret += dfs(next[next[i][j]][j], v[j][ii]);
	}
	ret += dfs(next[next[i][j]][j], j);
	ret /= sz+1;
	return ++ret;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int b, e;
	scanf("%d%d", &b, &e);
	for(int i = 0; i < m; ++i) {
		int one, two;
		scanf("%d%d", &one, &two);
		v[one].push_back(two);
		v[two].push_back(one);
	}
	for(int i = 1; i <= n; ++i)
		next[i][i] = i, bfs(i);
	memset(dp, -1, sizeof dp);
	printf("%.3f\n", dfs(b, e));
	return 0;
}
