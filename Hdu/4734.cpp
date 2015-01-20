/*
 * =====================================================================================
 *
 *       Filename:  4734.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/10/4 22:42:39
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

int dp[12][10000];
int digit[12];

int dfs(int pos, int delta, bool limit) {
	if(pos == -1)
		return delta >= 0;
	if(delta < 0) return 0;
	if(!limit && dp[pos][delta] != -1)
		return dp[pos][delta];
	int upper = limit ? digit[pos] : 9;
	int sum = 0;
	for(int i = 0; i <= upper; ++i)
		sum += dfs(pos-1, delta - i*(1<<pos), limit && i == upper);
	if(!limit)
		dp[pos][delta] = sum;
	return sum;
}

int calc(int num, int maxx) {
	int len = 0;
	if(!num)
		return num >= maxx;
	while(num) {
		digit[len++] = num %10;
		num /= 10;
	}
	return dfs(len-1, maxx, true);
}

inline int f(int num) {
	int mi = 1, ret = 0;
	while(num) {
		ret += num %10 * mi;
		mi <<= 1;
		num /= 10;
	}
	return ret;
}

int main() {
	memset(dp, -1, sizeof dp);
	int nn;
	scanf("%d", &nn);
	for(int ii = 1; ii <= nn; ++ii) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("Case #%d: %d\n", ii, calc(b, f(a)));
	}
	return 0;
}
