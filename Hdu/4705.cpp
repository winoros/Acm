/*
 * =====================================================================================
 *
 *       Filename:  4705.cpp
 *
 *    Descriptionn
 *
 *        Version:  1.0
 *        Created:  2014/9/24 2:16:12
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

int tail[100010], pre[100010<<1], to[100010<<1], tot;

inline void add(int _from, int _to) {
	pre[tot] = tail[_from];
	to[tot] = _to;
	tail[_from] = tot++;
}

int n;
int cnt_v[100010]; // cnt_v[i] for the number of the tree which root is i
long long cnt;

void dfs(int now, int fa) {
	cnt_v[now] = 0;
	for(int i = tail[now]; i != -1; i = pre[i]) {
		int _to = to[i];
		if(_to == fa)
			continue;
		dfs(_to, now);
		cnt += (long long)cnt_v[now]*cnt_v[_to];
		cnt_v[now] += cnt_v[_to];
	}
	cnt += (long long)cnt_v[now]*(n - cnt_v[now] - 1);
	cnt_v[now]++;
}

int main() {
	while(scanf("%d", &n) > 0) {
		tot = 0;
		memset(tail, -1, sizeof(int)*(n+5));
		for(int i = 1; i < n; i++) {
			int _u, _v;
			scanf("%d%d", &_u, &_v);
			add(_u, _v);
			add(_v, _u);
		}
		cnt = 0;
		dfs(1, -1);
		printf("%I64d\n", (long long)n*(n-1)*(n-2)/6 - cnt);
	}
	return 0;
}
