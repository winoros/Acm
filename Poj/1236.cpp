/*
 * =====================================================================================
 *
 *       Filename:  1236.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/12/18 23:06:49
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

int to[10010], pre[10010], tail[110], tot;

inline void add(int _from, int _to) {
	to[tot] = _to;
	pre[tot] = tail[_from];
	tail[_from] = tot++;
}

int dfn[110], low[110], stackk[110], top, cnt, idx, belong[110];
bool instack[110];

void tarjan(int now) {
	dfn[now] = low[now] = cnt++;
	stackk[++top] = now;
	instack[now] = true;
	for(int i = tail[now]; i != -1; i = pre[i]) {
		if(dfn[to[i]] == -1) {			
			tarjan(to[i]);
			low[now] = min(low[now], low[to[i]]);
		} else if(instack[to[i]])
			low[now] = min(low[now], dfn[to[i]]);
	}
	if(low[now] == dfn[now]) {
		++idx;
		int tmp;
		do {
			tmp = stackk[top--];
			belong[tmp] = idx;
			instack[tmp] = false;
		} while(top >= 0 && tmp != now);
	}
}

int in[110], out[110];

int main() {
	int n;
	scanf("%d", &n);
	memset(tail, -1, sizeof tail);
	tot = 0;
	for(int i = 0, tmp; i < n; ++i)
		while(scanf("%d", &tmp) && tmp)
			add(i, tmp-1);
	memset(dfn, -1, sizeof dfn);
	memset(instack, 0, sizeof instack);
	idx = -1, cnt = 0;
	for(int i = 0; i < n; ++i)
		if(dfn[i] == -1)
			tarjan(i);
	if(!idx)
		printf("1\n0\n");
	else {
		memset(in, 0, sizeof in);
		memset(out, 0, sizeof out);
		for(int now = 0; now < n; ++now)
			for(int i = tail[now]; i != -1; i = pre[i])
				if(belong[to[i]] != belong[now])
					++in[belong[to[i]]], ++out[belong[now]];
		int cnt1 = 0, cnt2 = 0;
		for(int i = 0; i <= idx; ++i) {
			if(!in[i])
				++cnt1;
			if(!out[i])
				++cnt2;
		}
		printf("%d\n%d\n", cnt1, max(cnt1, cnt2));
	}
	return 0;
}


