/*
 * =====================================================================================
 *
 *       Filename:  2057.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/1/25 15:15:30
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

int to[1010], pre[1010], tail[1010];
int tot;

inline void add(int _from, int _to) {
	to[tot] = _to;
	pre[tot] = tail[_from];
	tail[_from] = tot++;
}

int fail[1010], success[1010];
int leaves[1010];
bool worm[1010];

bool cmp(const int &lhs, const int &rhs) {
	return (fail[lhs] + 2) * leaves[rhs] < (fail[rhs] + 2) * leaves[lhs];
}

void dfs(int now) {
	leaves[now] = 0;
	fail[now] = success[now] = 0;
	int store[8], cnt = 0;
	for(int i = tail[now]; i != -1; i = pre[i]) {
		dfs(to[i]);
		store[cnt++] = to[i];
		leaves[now] += leaves[to[i]];
	}
	if(leaves[now]) {
		sort(store, store + cnt, cmp);
		for(int i = 0; i < cnt; ++i) {
			success[now] += (fail[now] + 1) * leaves[store[i]] + success[store[i]];
			fail[now] += fail[store[i]] + 2;
		}
	} else
		++leaves[now];
	if(worm[now])
		fail[now] = 0;
}

void MAIN(int n) {
	int fa;
	char str[2];
	scanf("%d%s", &fa, str);
	memset(worm, 0, sizeof worm);
	memset(tail, -1 ,sizeof tail);
	tot = 0;
	for(int i = 2; i <= n; ++i) {
		scanf("%d%s", &fa, str);
		add(fa, i);
		if(str[0] == 'Y')
			worm[i] = true;
	}
	dfs(1);
	printf("%.4f\n", success[1]*1.0 / leaves[1]);
}

int main() {
	int n;
	while(scanf("%d", &n) && n)
		MAIN(n);
	return 0;
}
