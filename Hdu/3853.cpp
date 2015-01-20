/*
 * =====================================================================================
 *
 *       Filename:  3853.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/11/4 13:36:30
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

double dp[1010][1010], p[1010][1010][3];
int n, m;

double dfs(int i, int j) {
	if(i == n && j == m)
		return 0;
	if(i > n || j > m)
		return 0;
	double &ret = dp[i][j];
	if(ret != -1)
		return ret;
	if(abs(p[i][j][0] - 1) < 1e-6)
		return ret = 0;
	ret = 0;
	return ret = (dfs(i, j+1) * p[i][j][1] + dfs(i+1, j) * p[i][j][2] + 2) / (1-p[i][j][0]);
}

int main() {
	while(scanf("%d%d", &n, &m) > 0) {
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j)
				dp[i][j] = -1, scanf("%lf%lf%lf", &p[i][j][0], &p[i][j][1], &p[i][j][2]);
		printf("%.3f\n", dfs(1,1));
	}
	return 0;
}
