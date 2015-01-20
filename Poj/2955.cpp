/*
 * =====================================================================================
 *
 *       Filename:  2955.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/10/11 12:42:38
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
char str[110];

int dfs(int l, int r) {
	if(dp[l][r] != -1)
		return dp[l][r];
	if(l >= r)
		return dp[l][r] = 0;
	dp[l][r] = dfs(l+1, r);
	for(int k = l+1; k <= r; ++k)
		if((str[l] == '(' && str[k] == ')') || (str[l] == '[' && str[k] == ']')) {
			dp[l][r] = max(dp[l][r], dfs(l+1, k-1) + 2 + dfs(k+1, r));
		}
	return dp[l][r];
}

int main() {
	for(scanf("%s", str); strcmp(str, "end"); scanf("%s", str)) {
		int len = strlen(str);
		memset(dp, -1, sizeof dp);
		printf("%d\n", dfs(0, len-1));
	}
	return 0;
}
