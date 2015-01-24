/*
 * =====================================================================================
 *
 *       Filename:  1947.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/1/24 17:49:58
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

int to[151<<1], pre[151<<1], tail[151];
int tot;

inline void add(int _from, int _to) {
	to[tot] = _to;
	pre[tot] = tail[_from];
	tail[_from] = tot++;
}

int dp[151][151];

int dfs(int now) {
	int tot = 1, pre_tot, cur_son_cnt = 0;
	memset(dp[now], 0x3f, sizeof dp[now]);
	dp[now][1] = 0;
	for(int i = tail[now]; i != -1; i = pre[i]) {
		pre_tot= tot;
		cur_son_cnt = dfs(to[i]);
		tot += cur_son_cnt;
		for(int j = tot; j >= 1; --j) {
			if(j <= pre_tot)
				++dp[now][j];
			for(int k = 1; k <= cur_son_cnt && j-k > 0; ++k)
				dp[now][j] = min(dp[now][j], dp[now][j-k] + dp[to[i]][k]);
		}
	}
	return tot;
}

bool is_son[151];

void MAIN() {
	int n, p;
	scanf("%d%d", &n, &p);
	memset(tail, -1, sizeof tail);
	tot = 0;
	memset(is_son, 0, sizeof is_son);
	for(int i = 1, u, v; i < n; ++i) {
		scanf("%d%d", &u, &v);
		--u, --v;
		is_son[v] = true;
		add(u, v);
	}
	int root;
	for(root = 0; is_son[root]; ++root)
		;
	dfs(root);
	int ans = 0x3f3f3f3f;
	for(int i = 0; i < n; ++i)
		if(i == root)
			ans = min(ans, dp[i][p]);
		else
			ans = min(ans, dp[i][p]+1);
	printf("%d\n", ans);
}

int main() {
	MAIN();
	return 0;
}
