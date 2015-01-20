/*
 * =====================================================================================
 *
 *       Filename:  1651.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/10/13 15:45:40
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
int a[110];

int dfs(int l, int r) {
	if(r-l < 2)
		return 0;
	int &ret = dp[l][r];
	if(ret != 0x3f3f3f3f)
		return ret;
	for(int i = l+1; i < r; ++i)
		ret = min(ret, dfs(l, i) + dfs(i, r) + a[i]*a[l]*a[r]);
	return ret;
}

int main() {
	memset(dp, 0x3f, sizeof dp);
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	printf("%d\n", dfs(0, n-1));
	return 0;
}
