/*
 * =====================================================================================
 *
 *       Filename:  1855.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/12/7 14:18:47
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

struct node {
	int money, share;
	node(): money(0), share(0) {}
	node(int _money, int _share): money(_money), share(_share) {}
};

node q[2010];
int head, tail;
int dp[2010][2010];

int main() {
	head = 0, tail = -1;
	q[++tail] = node(0, 0);
	int n, vol, w;
	scanf("%d%d%d", &n, &vol, &w);
	int ans = 0;
	for(int i = 0; i <= n; ++i)
		for(int j = 0; j <= vol; ++j)
			dp[i][j] = -100000000;
	dp[0][0] = 0;
	for(int i = 1; i <= n; ++i) {
		int ap, bp, as, bs;
		scanf("%d%d%d%d", &ap, &bp, &as, &bs);
		for(int j = 0; j <= as; ++j)
			dp[i][j] = -j*ap;
		for(int j = 0; j <= vol; ++j)
			dp[i][j] = max(dp[i][j], dp[i-1][j]);
		int k = i-w-1;
		if(k > 0) {
			head = 0, tail = -1;
			for(int j = 0; j <= vol; ++j) {
				int to_insert = dp[k][j] + j*ap;
				while(head <= tail && q[tail].money <= to_insert)
					--tail;
				q[++tail] = node(to_insert, j);
				while(head <= tail && q[head].share < j-as)
					++head;
				dp[i][j] = max(dp[i][j], q[head].money - j*ap);
			}
			head = 0, tail = -1;
			for(int j = vol; j >= 0; --j) {
				int to_insert = dp[k][j] + j*bp;
				while(head <= tail && q[tail].money <= to_insert)
					--tail;
				q[++tail] = node(to_insert, j);
				while(head <= tail && q[head].share > j+bs)
					++head;
				dp[i][j] = max(dp[i][j], q[head].money - j*bp);
			}
		}
		ans = max(ans, dp[i][0]);
	}
	printf("%d\n", ans);
	return 0;
}
