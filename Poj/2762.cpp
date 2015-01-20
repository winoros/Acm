/*
 * =====================================================================================
 *
 *       Filename:  2762.cpp
 *
 *    Description:   
 *
 *        Version:  1.0
 *        Created:  2014/12/20 23:31:58
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

int to[6010], pre[6010], tail[1010], tot;

inline void add(int _from, int _to) {
	to[tot] = _to;
	pre[tot] = tail[_from];
	tail[_from] = tot++;
}

int dfn[1010], low[1010], belong[1010], timestamp, scccnt, stackk[1010], top;
bool instack[1010];

void tarjan(int now) {
	dfn[now] = low[now] = ++timestamp;
	stackk[++top] = now;
	instack[now] = true;
	for(int i = tail[now]; i != -1; i = pre[i]) {
		if(dfn[to[i]] == -1) {
			tarjan(to[i]);
			low[now] = min(low[now], low[to[i]]);
		} else if(instack[to[i]])
			low[now] = min(low[now], dfn[to[i]]);
	}
	if(dfn[now] == low[now]) {
		int tmp = -1;
		++scccnt;
		while(tmp != now) {
			tmp = stackk[top--];
			instack[tmp] = false;
			belong[tmp] = scccnt;
		}
	}
}

bool in[1010], out[1010];

void MAIN() {
	int n, m;
	scanf("%d%d", &n, &m);
	memset(tail, -1, sizeof tail);
	tot = 0;
	for(int i = 0, u, v; i < m; ++i) {
		scanf("%d%d", &u, &v);
		add(u-1, v-1);
	}
	memset(dfn, -1, sizeof dfn);
	memset(instack, false, sizeof instack);
	top = scccnt = timestamp = -1;
	for(int i = 0; i < n; ++i)
		if(dfn[i] == -1)
			tarjan(i);
	memset(in, false, sizeof in);
	memset(out, false, sizeof out);
	for(int now = 0; now < n; ++now)
		for(int i = tail[now]; i != -1; i = pre[i]) 
			if(belong[now] != belong[to[i]])
				out[belong[now]] = true, in[belong[to[i]]] = true;
	int cnt1 = 0, cnt2 = 0;
	for(int i = 0; i <= scccnt; ++i) {
		if(!in[i])
			++cnt1;
		if(!out[i])
			++cnt2;
	}
	if(cnt1 > 1 || cnt2 > 1)
		puts("No");
	else
		puts("Yes");
}

int main() {
	int nn;
	scanf("%d", &nn);
	while(nn--) 
		MAIN();
	return 0;
}
