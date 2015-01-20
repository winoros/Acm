/*
 * =====================================================================================
 *
 *       Filename:  2553.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/12/19 18:54:14
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

vector<int> v[5010];

int dfn[5010], low[5010], stackk[5010], top, timestamp, scccnt, belong[5010];
bool instack[5010], not_ok[5010];

void tarjan(int now) {
	dfn[now] = low[now] = ++timestamp;
	instack[now] = true;
	stackk[++top] = now;
	int sz = v[now].size();
	for(int i = 0; i < sz; ++i) {
		if(dfn[v[now][i]] == -1) {
			tarjan(v[now][i]);
			low[now] = min(low[now], low[v[now][i]]);
		} else if(instack[v[now][i]])
			low[now] = min(low[now], dfn[v[now][i]]);
	}
	if(low[now] == dfn[now]) {
		++scccnt;
		int tmp = -1;
		while(tmp != now && top >= 0) {
			tmp = stackk[top--];
			belong[tmp] = scccnt;
			instack[tmp] = false;
		}
	}
}

void solve(int n, int m) {
	for(int i = 0, from, to; i < m; ++i) {
		scanf("%d%d", &from, &to);
		v[from-1].push_back(to-1);
	}
	memset(dfn, -1, sizeof dfn);
	memset(instack, false, sizeof instack);
	timestamp = top = scccnt = -1;
	for(int i = 0; i < n; ++i)
		if(dfn[i] == -1)
			tarjan(i);
	memset(not_ok, false, sizeof not_ok);
	for(int i = 0; i < n; ++i) {
		int sz = v[i].size();
		for(int j = 0; j < sz; ++j)
			if(belong[i] != belong[v[i][j]])
				not_ok[belong[i]] = true;
	}
	bool the_first = true;
	for(int i = 0; i < n; ++i) {
		if(!not_ok[belong[i]]) {
			if(the_first) {
				printf("%d", i+1);
				the_first = false;
			} else
				printf(" %d", i+1);
		}
	}
	puts("");
	for(int i = 0; i < n; ++i)
		v[i].clear();
}

int main() {
	int n;
	while(scanf("%d", &n) && n) {
		int m;
		scanf("%d", &m);
		solve(n, m);
	}
	return 0;
}
