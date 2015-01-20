/*
 * =====================================================================================
 *
 *       Filename:  1017.cpp
 *
 *    Description:  solve the 1017th problem of Ural
 *
 *        Version:  1.0
 *        Created:  2014/8/24 20:18:39
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  winoros (), winoros@gmail.com
 *   Organization:  BUPT
 *
 * =====================================================================================
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll dp[510][510] = { 0 };

int main() {
	dp[1][1] = 1;
	int n;
	scanf("%d", &n);
	for(int i = 2; i <= n; i++) {
		for(int j = 1; j<= i; j++) {
			dp[i][j] += dp[i-1][j-1] + dp[i-j][j-1];
		}
	}
	ll ans = 0;
	for(int i = n-1; i >= 0; i--) 
		ans += dp[n][i];
	printf("%I64d\n", ans);
	return 0;
}
