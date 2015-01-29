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

template<class T>
inline bool read(T &n) {
    T x = 0, tmp = 1;
    char c = getchar();
    while((c < '0' || c > '9') && c != '-' && c != EOF) c = getchar();
    if(c == EOF) return false;
    if(c == '-') c = getchar(), tmp = -1;
    while(c >= '0' && c <= '9') x *= 10, x += (c - '0'),c = getchar();
    n = x*tmp;
    return true;
}

vector<int> succ[50010], prod[50010], bucket[50010], dom_t[50010];
int semi[50010], anc[50010], idom[50010], best[50010], fa[50010];
int dfn[50010], redfn[50010];
int timestamp;
int size[50010], child[50010];

void dfs(int now) {
	dfn[now] = ++timestamp;
	redfn[timestamp] = now;
	anc[timestamp] = idom[timestamp] = size[timestamp] = child[timestamp] = 0;
	semi[timestamp] = best[timestamp] = timestamp;
	int sz = succ[now].size();
	for(int i = 0; i < sz; ++i) {
		if(dfn[succ[now][i]] == -1) {
			dfs(succ[now][i]);
			fa[dfn[succ[now][i]]] = dfn[now];
		}
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

inline int eval(int now) {
	if(anc[now] == 0)
		return now;
	else {
		compress(now);
		return semi[best[anc[now]]] >= semi[best[now]] ? best[now]
			: best[anc[now]];
	}
}

inline void link(int v, int w) {
	int s = w;
	while(semi[best[w]] < semi[best[child[w]]]) {
		if(size[s] + size[child[child[s]]] >= 2*size[child[s]]) {
			anc[child[s]] = s;
			child[s] = child[child[s]];
		} else {
			size[child[s]] = size[s];
			s = anc[s] = child[s];
		}
	}
	best[s] = best[w];
	size[v] += size[w];
	if(size[v] < 2*size[w])
		swap(s, child[v]);
	while(s != 0) {
		anc[s] = v;
		s = child[s];
	}
}

void lengauer_tarjan(int n) {
	memset(dfn, -1, sizeof dfn);
	memset(fa, -1, sizeof fa);
	size[0] = best[0] = semi[0] = 0;
	timestamp = 0;
	dfs(n);
	fa[1] = 0;
	for(int w = timestamp; w > 1; --w) {
		int sz = prod[w].size();
		for(int i = 0; i < sz; ++i) {
			int u = eval(prod[w][i]);
			if(semi[w] > semi[u])
				semi[w] = semi[u];
		}
		bucket[semi[w]].push_back(w);
		link(fa[w], w);
		if(fa[w] == 0)
			continue;
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
	for(int w = 2; w <= timestamp; ++w) {
		if(idom[w] != semi[w])
			idom[w] = idom[idom[w]];
	}
	idom[1] = 0;
	for(int i = timestamp; i > 1; --i) {
		if(fa[i] == -1)
			continue;
		dom_t[idom[i]].push_back(i);
	}
}

long long ans[50010];

void get_ans(int now) {
	ans[redfn[now]] += redfn[now];
	int sz = dom_t[now].size();
	for(int i = 0; i < sz; ++i) {
		ans[redfn[dom_t[now][i]]] += ans[redfn[now]];
		get_ans(dom_t[now][i]);
	}
}

void MAIN(int n, int m) {
	for(int i = 0; i <= n; ++i)
		succ[i].clear(), prod[i].clear(), bucket[i].clear(), dom_t[i].clear();
	for(int i = 0, u, v; i < m; ++i) {
		read(u), read(v);
		succ[u].push_back(v);
	}
	lengauer_tarjan(n);
	memset(ans, 0, sizeof ans);
	get_ans(1);
	for(int i = 1; i <= n; ++i)
		printf("%I64d%c", ans[i], i == n ? '\n' :' ');
}

int main() {
	int n, m;
	while(read(n) && read(m))
		MAIN(n, m);
	return 0;
}
