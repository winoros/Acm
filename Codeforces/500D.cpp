/*
 * =====================================================================================
 *
 *       Filename:  500D.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/12/31 0:47:54
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  winoros (Ding), winoros@gmail.com
 *   Organization:  BUPT
 *
 * =====================================================================================
 */
#include <bits/stdc++.h>

using namespace std;

int p[100010], cnt[100010];
long long sum[100010], dsum[100010];
double dp[100010];
int to[100010<<1], pre[100010<<1], cost[100010<<1], tail[100010], tot;

inline void add(int u, int v, int w) {
	to[tot] = v;
	cost[tot] = w;
	pre[tot] = tail[u];
	tail[u] = tot++;
}

void dfs(int now, int fa) {
	dp[now] = 0;
	sum[now] = dsum[now] = 0;
	cnt[now] = 0;
	for(int i = tail[now]; i != -1; i = pre[i]) {
		if(to[i] == fa)
			continue;
		dfs(to[i], now);
		sum[now] += sum[to[i]];
		dsum[now] += dsum[to[i]] + cost[i] * cnt[to[i]];
		cnt[now] += cnt[to[i]];
		dp[now] += dp[to[i]];
	}
	for(int i = tail[now]; i != -1; i = pre[i]) {
		if(to[i] == fa)
			continue;
		sum[now] += (dsum[to[i]] + cost[i] * cnt[to[i]]) * (cnt[now] - cnt[to[i]] + 1);
	}
	if(cnt[now] > 1)
		dp[now] += (sum[now] + dsum[now]*(cnt[now]-2)) * 1.0 / (cnt[now] * (cnt[now]-1)) * 2;
	++cnt[now];
	printf("%I64d__%I64d__%d__%.11f\n", sum[now], dsum[now], now, dp[now]);
}

int main() {
	int n;
	scanf("%d", &n);
	memset(tail, -1, sizeof tail);
	tot = 0;
	for(int i = 1, u, v, w; i < n; ++i) {
		scanf("%d%d%d", &u, &v, &w);
		add(u, v, w);
		add(v, u, w);
	}
	dfs(1, -1);
	printf("%.11f\n", dp[1]);
	return 0;
}
