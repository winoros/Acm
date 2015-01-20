/*
 * =====================================================================================
 *
 *       Filename:  1056.cpp
 *
 *    Description:  solve the 1056th problem of Ural
 *
 *        Version:  1.0
 *        Created:  2014/9/1 18:14:41
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

int pre[10010];
vector<int> v[10010];
int far_dis, far_node;

void dfs(int now, int fa, int depth) {
	pre[now] = fa;
	if(far_dis < depth+1) {
		far_node = now;
		far_dis = depth+1;
	}
	int sz = v[now].size();
	for(int i = 0; i < sz; i++) {
		if(v[now][i] == fa) continue;
		dfs(v[now][i], now, depth+1);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 2; i <= n; i++) {
		int fa;
		scanf("%d", &fa);
		v[i].push_back(fa);
		v[fa].push_back(i);
	}
	far_dis = -1;
	dfs(1, -1, 0);
	far_dis = -1;
	dfs(far_node, -1, 0);
	for(int i = 1; i < far_dis/2; i++)
		far_node = pre[far_node];
	if(far_dis&1)
		printf("%d\n", pre[far_node]);
	else
		printf("%d %d\n", far_node, pre[far_node]);
	return 0;
}
