/*
 * =====================================================================================
 *
 *       Filename:  505c.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/1/23 17:07:03
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

int gem[30010];
int dp[30010][505];
int pivot;

int dfs(int pos, int l) {
	int &ret = dp[pos][l - pivot], add = 0;
	if(ret != -1)
		return ret;
	if(pos + l + 1 <= 30000)
		add = dfs(pos+l+1, l+1);
	if(pos + l <= 30000)
		add = max(add, dfs(pos+l, l));
	if(pos + l - 1<= 30000 && l - 1 > 0)
		add = max(add, dfs(pos+l-1, l-1));
	return ret = gem[pos] + add;
}

int main() {
	memset(dp, -1, sizeof dp);
	int m, d;
	scanf("%d%d", &m, &d);
	while(m--) {
		int pos;
		scanf("%d", &pos);
		++gem[pos];
	}
	pivot = d - 252;
	printf("%d\n", dfs(d, d));
	return 0;
}
