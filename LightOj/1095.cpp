/*
 * =====================================================================================
 *
 *       Filename:  1095.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/2/1 14:35:29
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

const int mod = 1e9+7;

long long a[1010], c[1010][1010];

void init() {
	a[0] = 1;
	for(int i = 1; i <= 1000; ++i)
		a[i] = a[i-1] * i %mod;
	c[1][1] = c[1][0] = 1;
	for(int i = 2; i <= 1000; ++i) {
		c[i][0] = c[i][i] = 1;
		for(int j = 1; j < i; ++j)
			c[i][j] = (c[i-1][j-1] + c[i-1][j]) %mod;
	}
}

void MAIN() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	long long ans = 0;
	for(int i = 0; i <= m-k; ++i) {
		if(i&1)
			ans = ((ans - c[m-k][i]*a[n-k-i] %mod) %mod + mod) %mod;
		else
			ans = (ans + c[m-k][i]*a[n-k-i] %mod) %mod;
	}
	ans = ans * c[m][k] %mod;
	printf("%lld\n", ans);
}

int main() {
	init();
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		printf("Case %d: ", i);
		MAIN();
	}
	return 0;
}
