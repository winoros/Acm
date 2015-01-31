/*
 * =====================================================================================
 *
 *       Filename:  509a.cpp
 *
 *    Description
 *
 *        Version:  1.0
 *        Created:  2015/1/31 19:59:53
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

long long  a[20][20];

void MAIN() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		a[i][0] = a[0][i] = 1;
	for(int i = 1; i < n; ++i)
		for(int j = 1; j < n; ++j)
			a[i][j] = a[i-1][j] + a[i][j-1];
	long long maxx = 0;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			maxx = max(maxx, a[i][j]);
	printf("%I64d\n", maxx);
}

int main() {
	MAIN();
	return 0;
}
