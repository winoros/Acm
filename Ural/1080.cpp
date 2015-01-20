/*
 * =====================================================================================
 *
 *       Filename:  1080.cpp
 *
 *    Description:  solve the 1080th problem of Ural
 *
 *        Version:  1.0
 *        Created:  2014/8/26 0:38:58
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  winoros (), winoros@gmail.com
 *   Organization:  BUPT
 *
 * =====================================================================================
 */
/* 判断是否为二分图 */
#include <bits/stdc++.h>

using namespace std;

int col[100] = { 0 };
bool used[100] = { false };
vector<int> v[100];
queue<int> q;

bool bfs(int src) {
	while(!q.empty())
		q.pop();
	q.push(src);
	used[src] = true;
	col[src] = 1;
	while(!q.empty()) {
		int tmp = q.front(); q.pop();
		int sz = v[tmp].size();
		for(int i = 0; i < sz; i++) {
			//printf("%d---%d\n", tmp, v[tmp][i]);
			if(used[v[tmp][i]] && col[tmp] + col[v[tmp][i]] != 3)
				return false;
			if(!used[v[tmp][i]])
				q.push(v[tmp][i]), col[v[tmp][i]] = 3 - col[tmp], used[v[tmp][i]] = true;
		}
	}
	return true;
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		int tmp;
		while(scanf("%d", &tmp) && tmp)
			v[i].push_back(tmp), v[tmp].push_back(i);
	}
	for(int i = 1; i <= n; i++)
		if(!used[i] && !bfs(i)) {
			puts("-1");
			return 0;
		}
	for(int i = 1; i <= n; i++)
		printf("%d", col[i]-1);
	puts("");
	return 0;
}
