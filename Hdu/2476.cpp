/*
 * =====================================================================================
 *
 *       Filename:  2476.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/10/13 17:08:17
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
char str1[110], str2[110];

int dfs(int l, int r) {
	if(l > r)
		return 0;
	if(l == r)
		return 1;
	int &ret = dp[l][r];
	if(ret != 0x3f3f3f3f)
		return ret;
	for(int m = l; m < r; ++m)
		ret = min(ret, dfs(l, m) + dfs(m+1, r));
	if(str2[l] == str2[r])
		--ret;
	return ret;
}

int ans[110];

int main() {
	while(scanf("%s%s", str1, str2) > 0) {
		memset(dp, 0x3f, sizeof dp);
		int len = strlen(str1);
		ans[0] = str1[0] != str2[0];
		for(int i = 1; i < len; ++i) {
			ans[i] = dfs(0, i);
			if(str1[i] == str2[i])
				ans[i] = min(ans[i], ans[i-1]);
			else 
				for(int j = 0; j <= i; ++j)
					ans[i] = min(ans[i], ans[j] + dfs(j+1, i));
		}
		printf("%d\n", ans[len-1]);
	}
	return 0;
}
