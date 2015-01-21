/*
 * =====================================================================================
 *
 *       Filename:  1655.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/1/21 18:02:58
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

int to[20010<<1], pre[20010<<1], tail[20010], tot;

inline void add(int _from, int _to) {
	to[tot] = _to;
	pre[tot] = tail[_from];
	tail[_from] = tot++;
}

int ans, ans_id;
int n;

int dfs(int now, int fa) {
	int cnt = 0, maxx = -1;
	for(int i = tail[now], tmp; i != -1; i = pre[i]) {
		if(to[i] == fa)
			continue;
		tmp = dfs(to[i], now);
		maxx = max(maxx, tmp);
		cnt += tmp;
	}
	maxx = max(maxx, n - cnt - 1);
	if(ans > maxx)
		ans = maxx, ans_id = now;
	else if(ans == maxx)
		ans_id = min(ans_id, now);
	return cnt + 1;
}

int main() {
	int nn;
	scanf("%d", &nn);
	while(nn--) {
		scanf("%d", &n);
		memset(tail, -1, sizeof tail);
		tot = 0;
		for(int i = 1, u, v; i < n; ++i) {
			scanf("%d%d", &u, &v);
			add(u, v);
			add(v, u);
		}
		ans = 30000;
		dfs(1, -1);
		printf("%d %d\n", ans_id, ans);
	}
	return 0;
}
