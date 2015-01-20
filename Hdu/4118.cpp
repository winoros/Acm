/*
 * =====================================================================================
 *
 *       Filename:  4118.cpp
 *
 *    Description
 *
 *        Version:  1.0
 *        Created:  2014/9/17 18:14:41
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

int n;
int son_num[100010];
int tail[100010], to[200010], pre[200010], cost[200010], tot;
long long ans;

inline void add(int _from, int _to, int _cost) {
	pre[tot] = tail[_from];
	to[tot] = _to;
	cost[tot] = _cost;
	tail[_from] = tot++;
}

void dfs(int now, int fa) {
	son_num[now] = 1;
	for(int i = tail[now]; i != -1; i = pre[i]) {
		int _to = to[i], _cost = cost[i];
		if(_to == fa)
			continue;
		dfs(_to, now);
		ans += (long long)_cost*min(n-son_num[_to], son_num[_to])*2;
		son_num[now] += son_num[_to];
	}
}

int main() {
	int nn;
	scanf("%d", &nn);
	for(int ii = 1; ii <= nn; ii++) {
		scanf("%d", &n);
		memset(tail, -1, sizeof tail);
		tot = 0;
		for(int i = 1; i < n; i++) {
			int _u, _v, _cost;
			scanf("%d%d%d", &_u, &_v, &_cost);
			add(_u, _v, _cost);
			add(_v, _u, _cost);
		}
		ans = 0;
		dfs(1, -1);
		printf("Case #%d: %I64d\n", ii, ans);
	}
	return 0;
}
