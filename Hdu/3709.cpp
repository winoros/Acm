/*
 * =====================================================================================
 *
 *       Filename:  3709.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/10/5 20:09:42
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

long long dp[20][20][2000];
int digit[20];

long long count(int pos, int center, int pre_sum, bool limit) {
	if(pos == -1)
		return pre_sum == 0;
	if(pre_sum < 0)
		return 0LL;
	if(!limit && dp[pos][center][pre_sum] != -1)
		return dp[pos][center][pre_sum];
	int upper = limit ? digit[pos] : 9;
	long long sum = 0;
	for(int i = 0; i <= upper; ++i)
		sum += count(pos-1, center, pre_sum + i*(pos-center), limit && i == upper);
	if(!limit)
		dp[pos][center][pre_sum] = sum;
	return sum;
}

long long calc(long long num) {
	int len = 0;
	while(num) {
		digit[len++] = num %10;
		num /= 10;
	}
	long long ret = 0;
	for(int i = len-1; i >= 0; --i)
		ret += count(len-1, i, 0, true);
	return ret - len+1;
}

int main() {
	memset(dp, -1, sizeof dp);
	int nn;
	for(scanf("%d", &nn); nn; --nn) {
		long long l, r;
		scanf("%I64d%I64d", &l, &r);
		printf("%I64d\n", calc(r) - calc(l-1));
	}
	return 0;
}
