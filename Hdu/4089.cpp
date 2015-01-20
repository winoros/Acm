/*
 * =====================================================================================
 *
 *       Filename:  4089.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/11/8 0:39:35
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  winoros (Ding), winoros@gmail.com
 *   Organization:  BUPT
 *
 * =====================================================================================
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <utility>
#include <map>
#include <set>
#include <cctype>
#include <climits>
#include <stack>
#include <cmath>
#include <bitset>
#include <numeric>
#include <functional>

using namespace std;

const double eps = 1e-9;

int sgn(double x) {
	return x < -eps ? -1 : x > eps;
}

double dp[2010][2010], c[2010];

int main() {
	for(int n, m, k; scanf("%d%d%d", &n, &m, &k) > 0; ) {
		double p1, p2, p3, p4;
		scanf("%lf%lf%lf%lf", &p1, &p2, &p3, &p4);
		if(!sgn(1-p1-p2)) {
			puts("0.00000");
		} else {
			double p21 = p2/(1-p1), p31 = p3/(1-p1), p41 = p4/(1-p1);
			dp[1][1] = p4/(1-p1-p2);
			c[1] = p41;
			for(int i = 2; i <= n; ++i) {
				for(int j = 2; j <= k && j <= i; ++j)
					c[j] = p41 + p31*dp[i-1][j-1];
				for(int j = k+1; j <= i; ++j)
					c[j] = p31*dp[i-1][j-1];
				double val = 0, pp = 1;
				for(int j = 1; j <= i; ++j)
					val = val*p21 + c[j], pp *= p21;
				dp[i][i] = val/(1-pp);
				dp[i][1] = p21*dp[i][i] +c[1];
				for(int j = 2; j < i; ++j)
					dp[i][j] = p21*dp[i][j-1] + c[j];
			}
			printf("%.5f\n", dp[n][m]);
		}
	}
	return 0;
}
