/*
 * =====================================================================================
 *
 *       Filename:  1045.cpp
 *
 *    Description:  solve the 1045th problem of Ural
 *
 *        Version:  1.0
 *        Created:  2014/9/2 23:37:36
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
int ans;

bool dfs(int now, int fa) {
	int sz = v[now].size();
	bool has_son = false;
	sort(v[now].begin(), v[now].end());
	for(int i = 0; i < sz; i++) {
		if(v[now][i] == fa) continue;
		has_son = true;
		if(!dfs(v[now][i], now)) {
			ans = v[now][i];
			return true;
		}
	}
	if(!has_son)
		return false;
	return false;
}

int main() {
	int n, src;
	scanf("%d%d", &n, &src);
	for(int i = 0; i < n-1; i++) {
		int u1, u2;
		scanf("%d%d", &u1, &u2);
		v[u1].push_back(u2);
		v[u2].push_back(u1);
	}
	if(dfs(src, -1))
		printf("First player wins flying to airport %d\n", ans);
	else 
		puts("First player loses");
	return 0;
}
