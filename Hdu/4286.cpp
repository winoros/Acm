/*
 * =====================================================================================
 *
 *       Filename:  4286.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/10/21 11:48:25
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

int dp[110][110];
int d_sum[110], d[110];

int dfs(int l, int r) {
	if(l >= r)
		return 0;
	int &ret = dp[l][r];
	if(ret != -1)
		return ret;
	ret = 0x3f3f3f3f;
	for(int m = l; m <= r; ++m)
		ret = min(ret, dfs(l+1, m) + dfs(m+1, r) + d[l]*(m-l) + (d_sum[r] - d_sum[m])*(m-l+1));
	return ret;
}

int main() {
	int nn;
	scanf("%d", &nn);
	for(int ii = 1; ii <= nn; ++ii) {
		int n;
		scanf("%d", &n);
		d_sum[0] = 0;
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &d[i]);
			d_sum[i] = d_sum[i-1] + d[i];
		}
		memset(dp, -1, sizeof dp);
		printf("Case #%d: %d\n", ii, dfs(1, n));
	}
	return 0;
}
