/*
 * =====================================================================================
 *
 *       Filename:  1068.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/10/19 13:17:55
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

int dp[55][55][2];
char str[55];


bool check(int head, int tail) {
	int m = (tail - head + 1) >> 1;
	for(int i = 0; i < m; ++i)
		if(str[head+i] != str[head+m+i])
			return false;
	return true;
}
int dfs(int l, int r, bool m) {
	if(l >= r)
		return l == r;
	int &ret = dp[l][r][m];
	if(ret != -1)
		return ret;
	ret = r - l + 1;
	if(m)
		for(int i = l; i < r; ++i)
			ret = min(ret, dfs(l, i, 1) + dfs(i+1, r, 1) + 1);
	for(int i = l; i < r; ++i)
		ret = min(ret, dfs(l, i, m) + r - i);
	if((r-l)&1 && check(l, r))
		ret = min(ret, dfs(l, (l+r)>>1, 0) + 1);
	return ret;
}

int main() {
	while(scanf("%s", str) > 0) {
		memset(dp, -1, sizeof dp);
		int len = strlen(str);
		printf("%d\n", dfs(0, len-1, 1));
	}
	return 0;
}
