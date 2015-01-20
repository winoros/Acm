/*
 * =====================================================================================
 *
 *       Filename:  1031.cpp
 *
 *    Description:  solve the 1031th problem of Ural
 *
 *        Version:  1.0
 *        Created:  2014/8/27 23:14:57
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

int dis[10010], dp[10010];

int main() {
	int l[3], c[3];
	for(int i = 0; i < 3; i++)
		scanf("%d", &l[i]);
	for(int i = 0; i < 3; i++)
		scanf("%d", &c[i]);
	int n;
	scanf("%d", &n);
	int s, e;
	scanf("%d%d", &s, &e);
	s--, e--;
	if(s > e) swap(s, e);
	dis[0] = 0;
	for(int i = 1; i < n; i++)
		scanf("%d", &dis[i]);
	dp[s] = 0;
	for(int i = s+1; i <= e; i++) {
		dp[i] = 0x3f3f3f3f;
		for(int j = i-1; j >= s && dis[i]-dis[j] <= l[2]; j--) {
			for(int k = 0; k < 3; k++)
				if(dis[i]-dis[j] <= l[k]) {
					dp[i] = min(dp[i], dp[j] + c[k]);
					break;
				}
		}
	}
	printf("%d\n", dp[e]);
	return 0;
}
