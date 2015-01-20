/*
 * =====================================================================================
 *
 *       Filename:  1066.cpp
 *
 *    Description:  solve the 1066th problem of Ural
 *
 *        Version:  1.0
 *        Created:  2014/9/1 16:52:30
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

double b, m, n;
const double eps = 1e-9;

int djudge(double x) {
	return x < -eps ? -1 : x > eps;
}

bool check(double mid) {
	if(djudge(-mid/2 - n) >= 0)
		return djudge(n*n + mid*n + m-mid) >= 0;
	else {
		double x1 = (int)(-mid/2), x2 = x1+1;
			return djudge(x1*x1 + mid*x1 + m-mid) >= 0 && djudge(x2*x2 + mid*x2 + m-mid) >= 0;
	}	
}

int main() {
	scanf("%lf%lf", &n, &m);
	m--;
	double l = -10000, r = 0, mid;
	while(djudge(r-l)) {
		mid = (l+r)/2;
		if(check(mid))
			r = mid;
		else 
			l = mid;
	}
	printf("%.2f\n", n*n + r*n + m-r);
	return 0;
}
