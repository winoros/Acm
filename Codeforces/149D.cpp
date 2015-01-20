/*
 * =====================================================================================
 *
 *       Filename:  149D.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/10/13 15:14:58
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

const int mod = 1e9+7;

long long dp[710][710][3][3];
char str[710];

long long dfs(int l, int r, int cl, int cr) {
	if(l > r)
		return 1;
	long long &ret = dp[l][r][cl][cr];
	if(ret != -1)
		return ret;
	ret = 0;
	int m, cnt = 0;
	for(m = l; m <= r; ++m) {
		if(str[m] == '(')
			++cnt;
		else
			--cnt;
		if(!cnt)
			break;
	}
	if(m == r) {
		for(int i = 1; i < 3; ++i) {
			if(cl != i)
				ret += dfs(l+1, r-1, i, 0);
			if(cr != i)
				ret += dfs(l+1, r-1, 0, i);
			ret %= mod;
		}
	} else {
		for(int i = 1; i < 3; ++i) {
			if(cl != i)
				ret += dfs(l+1, m-1, i, 0) * dfs(m+1, r, 0, cr);
			ret += dfs(l+1, m-1, 0, i) * dfs(m+1, r, i, cr);
			ret %= mod;
		}
	}
	return ret;
}

int main() {
	memset(dp, -1, sizeof dp);
	scanf("%s", str);
	int len = strlen(str);
	printf("%I64d\n", dfs(0, len-1, 0, 0));
	return 0;
}
