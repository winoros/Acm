/*
 * =====================================================================================
 *
 *       Filename:  1091.cpp
 *
 *    Description:	solve the 1091th problem of Ural
 *
 *        Version:  1.0
 *        Created:  2014/9/1 2:19:03
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

int ans = 0, k, n;
int gcd[51][51];

void make_gcd() {
	for(int i = 1; i <= 50; i++)
		for(int j = i; j <= 50; j++)
			gcd[i][j] = gcd[j][i] = __gcd(i, j);
}

void dfs(int now, int now_gcd, int times) {
	if(k == times) {
		ans++;
		return ;
	}
	for(int i = now+1; i <= n; i++) {
		int next_gcd;
		if(!times) 
			next_gcd = i;
		else 
			next_gcd = gcd[i][now_gcd];
		if(next_gcd == 1) 
			continue;
		else 
			dfs(i, next_gcd, times+1);
	}
}

int main() {
	make_gcd();
	scanf("%d%d", &k, &n);
	dfs(1, 1, 0);
	printf("%d\n", ans >= 10000 ? 10000 : ans);
	return 0;
}
