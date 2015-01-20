/*
 * =====================================================================================
 *
 *       Filename:  1018.cpp
 *
 *    Description:  solve the 1018th problem of Ural
 *
 *        Version:  1.0
 *        Created:  2014/8/26 16:46:31
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  winoros (), winoros@gmail.com
 *   Organization:  BUPT
 *
 * =====================================================================================
 */

#include <bits/stdc++.h>

using namespace std;

struct node {
	int to, cost;
};

int dp[110][110] = { 0 };
int son[110];
vector<node> v[110];

inline node make_node(int _to, int _cost) {
	node ret;
	ret.to = _to, ret.cost = _cost;
	return ret;
}

void dfs(int x, int fa) {
	son[x] = 0;
	int sz = v[x].size();
	for(int i = 0; i < sz; i++) {
		if(v[x][i].to == fa) continue;
		dfs(v[x][i].to, x), son[x] += son[v[x][i].to];
	}
	son[x]++;
	for(int i = 0; i < sz; i++) {
		if(v[x][i].to == fa) continue;
		int _cost = v[x][i].cost, _to = v[x][i].to;
		for(int j = son[x]; j >= 2; j--) {
			int maxx = min(j-1, son[_to]);
			for(int k = 1; k <= maxx; k++) {
				if(dp[x][j] < dp[x][j-k] + dp[_to][k] + _cost)
					dp[x][j] = dp[x][j-k]+dp[_to][k]+_cost;
			}
		}
	}
}

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 1; i < n; i++) {
		int tmp, tmpp, cost;
		scanf("%d%d%d", &tmp, &tmpp, &cost);
		v[tmp].push_back(make_node(tmpp, cost));
		v[tmpp].push_back(make_node(tmp, cost));
	}
	dfs(1, -1);
	printf("%d\n", dp[1][k+1]);
	return 0;
}
