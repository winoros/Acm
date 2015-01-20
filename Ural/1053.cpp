/*
 * =====================================================================================
 *
 *       Filename:  1053.cpp
 *
 *    Description:  solve the 1053th problem of Ural
 *
 *        Version:  1.0
 *        Created:  2014/8/26 3:15:21
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

int main() {
	int n, ans;
	scanf("%d%d", &n, &ans);
	for(int i = 1; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		ans = __gcd(ans, tmp);
	}
	printf("%d\n", ans);
	return 0;
}
