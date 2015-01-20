/*
 * =====================================================================================
 *
 *       Filename:  1077.cpp
 *
 *    Description:  solve the 1077th problem of Ural
 *
 *        Version:  1.0
 *        Created:  2014/8/31 0:07:18
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

vector<int> v[201];
stack<int> ans[201*201];
int p[201], pre[201];
queue<int> q;
bool used[201];

int find(int x) {
	return p[x] == x ? x : p[x] = find(p[x]);
}
void bfs(int s, int e) {
	memset(pre, 0, sizeof pre);
	memset(used, 0, sizeof used);
	while(!q.empty()) 
		q.pop();
	q.push(s);
	used[s] = true;
	while(!q.empty()) {
		int now = q.front(); q.pop();
		int sz = v[now].size();
		for(int i = 0; i < sz; i++) {
			if(used[v[now][i]]) continue;
			pre[v[now][i]] = now;
			used[v[now][i]] = true;
			if(v[now][i] == e) 
				return ;
			else 
				q.push(v[now][i]);
		}
	}
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		p[i] = i; 
	int ansLen = 0;
	while(m--) {
		int v1, v2;
		scanf("%d%d", &v1, &v2);
		int p1 = find(v1), p2 = find(v2);
		if(p1 == p2) {
			bfs(v1, v2);
			int now = v2;
			ans[ansLen].push(now);
			while(pre[now])
				ans[ansLen].push(pre[now]), now = pre[now];
			ansLen++;
		} else {
			v[v1].push_back(v2);
			v[v2].push_back(v1);
			p[p1] = p2;
		}
	}
	printf("%d\n", ansLen);
	for(int i = 0; i < ansLen; i++) {
		printf("%d ", ans[i].size());
		while(1) {
			printf("%d", ans[i].top());
			ans[i].pop();
			if(!ans[i].empty())
				putchar(' ');
			else { 
				putchar('\n');
				break;
			}
		}
	}
	return 0;
}
