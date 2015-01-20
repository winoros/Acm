/*
 * =====================================================================================
 *
 *       Filename:  4352.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/10/6 0:12:36
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

long long dp[20][1<<10][11];
int digit[20];

inline int count_one(int state) {
	int ret = 0;
	while(state) {
		ret += state&1;
		state >>= 1;
	}
	return ret;
}

inline int update(int state, int pos) {
	for(int i = pos; i <= 9; ++i)
		if(state & (1<<i))
			return (state ^ (1<<i)) | (1<<pos);
	return state | (1<<pos);
}

long long count(int pos, int state, int k, bool not_first, bool limit) {
	if(pos == -1)
		return count_one(state) == k;
	if(!limit && dp[pos][state][k] != -1)
		return dp[pos][state][k];
	int upper = limit ? digit[pos] : 9;
	long long sum = 0;
	for(int i = 0; i <= upper; ++i)
		sum += count(pos-1, not_first || i? update(state, i) : 0, k, not_first | i, limit && i == upper);
	if(!limit)
		dp[pos][state][k] = sum;
	return sum;
}

long long calc(long long num, int k) {
	int len = 0;
	while(num) {
		digit[len++] = num %10;
		num /= 10;
	}
	return count(len-1, 0, k, false, true);
}

int main() {
	memset(dp, -1, sizeof dp);
	int nn;
	scanf("%d", &nn);
	for(int ii = 1; ii <= nn; ii++) {
		long long l, r;
		int k;
		scanf("%I64d%I64d%d", &l, &r, &k);
		printf("Case #%d: %I64d\n", ii ,calc(r, k) - calc(l-1, k));
	}
	return 0;
}
