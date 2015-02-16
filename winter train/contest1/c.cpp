/*
 * =====================================================================================
 *
 *       Filename:  c.cpp
 *
 *    Description
 *
 *        Version:  1.0
 *        Created:  2015/2/16 15:06:56
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

int a[10010];

void MAIN() {
	int n, m;
	scanf("%d%d", &n, &m);
	a[0] = 0;
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		a[i] += a[i-1];
	}
	while(m--) {
		int tmp;
		scanf("%d", &tmp);
		printf("%d\n", upper_bound(a, a+n+1, tmp) - a);
	}
}

int main() {
	MAIN();
	return 0;
}
