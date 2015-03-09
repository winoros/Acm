/*
 * =====================================================================================
 *
 *       Filename:  518d.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/2/25 0:42:41
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  winoros (Ding), winoros@gmail.com
 *   Organization:  BUPT
 *
 * =====================================================================================
 */
#include <bits/stdc++.h>

double dp[2010][2010];

void MAIN() {
	int n, t;
	double prob;
	std::cin >> n >> prob >> t;
	dp[0][0] = 1;
	for(int i = 0; i < t; ++i) {
		int upper = std::min(i, n);
		for(int j = 0; j <= upper; ++j)
			if(j == n)
				dp[i+1][j] += dp[i][j];
			else
				dp[i+1][j] += (1-prob)*dp[i][j], dp[i+1][j+1] += prob*dp[i][j];
	}
	double ans = 0;
	for(int i = 0; i <= n; ++i)
		ans += dp[t][i] * i;
	std::cout << std::setprecision(17) << ans << std::endl;
}

int main() {
	MAIN();
	return 0;
}
