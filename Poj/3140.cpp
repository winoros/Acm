/*
 * =====================================================================================
 *
 *       Filename:  3140.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/1/25 21:53:46
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

int to[100010<<1], pre[100010<<1], tail[100010];
int tot;

inline void add(int _from, int _to) {
	to[tot] = _to;
	pre[tot] = tail[_from];
	tail[_from] = tot++;
}

int val[100010];
long long ans, s_tot;

long long dfs(int now, int fa) {
	long long cnt = val[now];
	for(int i = tail[now]; i != -1; i = pre[i]) {
		if(fa == to[i])
			continue;
		cnt += dfs(to[i], now);
	}
	ans = min(ans, llabs(s_tot - cnt*2));
	return cnt;
}

void MAIN(int n, int m) {
	for(int i = 0; i < n; ++i)
		scanf("%d", &val[i]);
	s_tot = accumulate(val, val+n, 0LL);
	memset(tail, -1, sizeof tail);
	tot = 0;
	for(int i = 1, u, v; i < n; ++i) {
		scanf("%d%d", &u, &v);
		--u, --v;
		add(u, v);
		add(v, u);
	}
	ans = 0x3f3f3f3f3f3f3f3f;
	dfs(0, -1);
	printf("%I64d\n", ans);
}

int main() {
	int cnt = 0, n, m;
	while(scanf("%d%d", &n, &m) && n) {
		printf("Case %d: ", ++cnt);
		MAIN(n, m);
	}
	return 0;
}
