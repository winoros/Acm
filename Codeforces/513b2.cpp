/*
 * =====================================================================================
 *
 *       Filename:  513b2.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/2/8 10:53:39
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

int ans[55];

void MAIN() {
	int n;
	long long m;
	scanf("%d%I64d", &n, &m);
	int l = 0, r = n - 1;
	for(int j = n - 1; j > 0; j--) {
		if (m <= (1LL << (j - 1))) {
			ans[l++] = n - j;
		} else {
			ans[r--] = n - j;
			m -= (1LL << (j - 1));
		}
	}
	ans[l] = n;
	for(int i = 0; i < n; ++i)
		printf("%d%c", ans[i], i == n-1 ? '\n' : ' ');
}

int main() {
	MAIN();
	return 0;
}
