/*
 * =====================================================================================
 *
 *       Filename:  1011.cpp
 *
 *    Description:  solve the 1011th problem of Ural
 *
 *        Version:  1.0
 *        Created:  2014/8/25 4:52:17
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
	double n, m;
	while(scanf("%lf%lf", &n, &m) > 0) {
		int ans = 1, x = 1, y = 1;
		n += 1e-10, m -= 1e-10;
		while(x == y) 
			ans++, x = (int)ans*n/100, y = (int)ans*m/100;
		printf("%d\n", ans);
	}
	return 0;
}
