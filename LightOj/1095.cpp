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

int a[1010], c[1010][1010];

void init() {
	a[0] = c[0][0] = 1;
	for(int i = 1; i <= 1000; ++i)
		a[i] = (long long)a[i-1] * i %mod;
	c[1][1] = c[1][0] = 1;
	for(int i = 2; i <= 1000; ++i) {
		c[i][0] = c[i][i] = 1;
		for(int j = 1; j < i; ++j)
			c[i][j] = (long long)(c[i-1][j-1] + c[i-1][j]) %mod;
	}
}

void MAIN() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	int ans = 0;
	for(int i = 0; i <= m-k; ++i) {
		if(i&1)
			ans = ((ans - (long long)c[m-k][i]*a[n-k-i] %mod) %mod + mod) %mod;
		else
			ans = (ans + (long long)c[m-k][i]*a[n-k-i] %mod) %mod;
	}
	ans = (long long)ans * c[m][k] %mod;
	printf("%d\n", ans);
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
