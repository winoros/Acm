/*
 * =====================================================================================
 *
 *       Filename:  4694.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/1/26 12:32:52
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  winoros (Ding), winoros@gmail.com
 *   Organization:  BUPT
 *
 * =====================================================================================
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <utility>
#include <map>
#include <set>
#include <cctype>
#include <climits>
#include <stack>
#include <cmath>
#include <bitset>
#include <numeric>
#include <functional>

using namespace std;

vector<int> succ[50010], prod[50010], bucket[50010];
int semi[50010], anc[50010], idom[50010], best[50010], fa[50010];
int dfn[50010], redfn[50010];
int timestamp;

void dfs(int now) {
	dfn[now] = ++timestamp;
	redfn[timestamp] = now;
	anc[now] = idom[now] = 0;
	semi[timestamp] = best[timestamp] = timestamp;
	int sz = succ[now].size();
	for(int i = 0; i < sz; ++i) {
		if(fa[succ[now][i]] == -1)
			dfs(succ[now][i]), fa[succ[now][i]] = now;
		prod[dfn[succ[now][i]]].push_back(dfn[now]);
	}
}

void compress(int now) {
	if(anc[anc[now]] != 0) {
		compress(anc[now]);
		if(semi[best[now]] > semi[best[anc[now]]])
			best[now] = best[anc[now]];
		anc[now] = anc[anc[now]];
	}
}

int eval(int now) {
	if(anc[now] == 0)
		return now;
	compress(now);
	return best[now];
}

void lengauer_tarjan(int n) {
	memset(dfn, -1, sizeof dfn);
	memset(fa, -1, sizeof fa);
	timestamp = -1;
	dfs(n);
	for(int w = n-1; w > 0; --w) {
		if(fa[w] == -1)
			continue;
		printf("%d___\n", w);
		int sz = prod[w].size();
		for(int i = 0; i < sz; ++i) {
			int u = eval(prod[w][i]);
			if(semi[w] > semi[u])
				semi[w] = semi[u];
		}
		bucket[semi[w]].push_back(w);
		anc[w] = fa[w];
		sz = bucket[fa[w]].size();
		for(int i = 0; i < sz; ++i) {
			int u = eval(bucket[fa[w]][i]);
			if(semi[u] < fa[w])
				idom[bucket[fa[w]][i]] = u;
			else
				idom[bucket[fa[w]][i]] = fa[w];
		}
		bucket[fa[w]].clear();
	}
	for(int i = 0; i < n; ++i)
		printf("%d ", semi[i]);
	puts("");
	for(int i = 0; i < n; ++i)
		printf("%d ", idom[i]);
	puts("");
	for(int w = 1; w < n; ++w) {
		if(fa[w] == -1)
			continue;
		if(idom[w] != semi[w])
			idom[w] = idom[idom[w]];
	}
	idom[0] = 0;
}

long long ans[50010];

void get_ans(int now) {
	ans[redfn[now]] += redfn[now];
	int sz = succ[redfn[now]].size();
	for(int i = 0; i < sz; ++i) {
		ans[succ[redfn[now]][i]] += ans[redfn[now]];
		get_ans(succ[redfn[now]][i]);
	}
}

void MAIN(int n, int m) {
	for(int i = 0; i <= n; ++i)
		succ[i].clear(), prod[i].clear(), bucket[i].clear();
	for(int i = 0, u, v; i < m; ++i) {
		scanf("%d%d", &u, &v);
		succ[u].push_back(v);
	}
	lengauer_tarjan(n);
	for(int i = 0; i < n; ++i)
		printf("%d%c", idom[i], i == n-1 ? '\n' : ' ');
	memset(ans, 0, sizeof ans);
	get_ans(0);
	for(int i = 1; i <= n; ++i)
		printf("%I64d%c", ans[i], i == n ? '\n' :' ');
}

int main() {
	int n, m;
	while(scanf("%d%d", &n, &m) > 0)
		MAIN(n, m);
	return 0;
}
