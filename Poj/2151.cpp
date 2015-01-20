/*
 * =====================================================================================
 *
 *       Filename:  2151.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/10/26 15:22:21
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

double dp[1010][35][35], prob[1010][35], prod[1010][35];

int main() {
	int n, m, k;
	while(scanf("%d%d%d", &n, &m, &k) && n) {
		for(int i = 0; i < m; ++i)
			for(int j = 1; j <= n; ++j)
				scanf("%lf", &prob[i][j]);
		for(int i = 0; i < m; ++i) {
			dp[i][0][0] = 1;
			for(int j = 1; j <= n; ++j) {
				dp[i][j][0] = dp[i][j-1][0] * (1 - prob[i][j]);
				for(int k = 1; k <= j; ++k)
					dp[i][j][k] = dp[i][j-1][k-1] * prob[i][j] + dp[i][j-1][k] * (1 - prob[i][j]);
			}
			prod[i][0] = dp[i][n][0];
			for(int j = 1; j <= n; ++j)
				prod[i][j] = prod[i][j-1] + dp[i][n][j];
		}
		double ans = 1, anss = 1;
		for(int i = 0; i < m; ++i)
			ans *= (1 - prod[i][0]), anss *= (prod[i][k-1] - prod[i][0]);
		printf("%.3f\n", ans - anss);
	}
	return 0;
}
