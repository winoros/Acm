/*
 * =====================================================================================
 *
 *       Filename:  3071.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/10/25 22:06:02
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

double dp[8][(1<<7)+10], prob[(1<<7)+10][(1<<7)+10];

int main() {
	int n;
	for(scanf("%d", &n); n != -1; scanf("%d", &n)) {
		for(int i = 0; i < 1<<n; ++i)
			for(int j = 0; j < 1<<n; ++j)
				scanf("%lf", &prob[i][j]);
		memset(dp, 0, sizeof dp);
		for(int i = 0; i < 1<<n; ++i)
			dp[0][i] = 1;
		for(int i = 1; i <= n; ++i)
			for(int j = 0; j < 1<<n; ++j)
				for(int k = 0; k < 1<<n; ++k)
					if((j>>(i-1)^1) == k>>(i-1))
						dp[i][j] += dp[i-1][j]*dp[i-1][k]*prob[j][k];
		int ans;
		double maxx = 0;
		for(int i = 0; i < 1<<n; ++i)
			if(maxx < dp[n][i])
				maxx = dp[n][i], ans = i;
		printf("%d\n", ans+1);
	}
	return 0;
}
