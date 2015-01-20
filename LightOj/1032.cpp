/*
 * =====================================================================================
 *
 *       Filename:  1032.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/10/8 22:08:36
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

long long dp[32][2][32];
int digit[32];

long long count(int pos, int pre_digit, int pre_cnt, bool limit) {
	if(pos == -1)
		return pre_cnt;
	if(!limit && dp[pos][pre_digit][pre_cnt] != -1)
		return dp[pos][pre_digit][pre_cnt];
	int upper = limit ? digit[pos] : 1;
	long long sum = 0;
	for(int i = 0; i <= upper; ++i)
		sum += count(pos-1, i, pre_cnt + (pre_digit && i ? 1 : 0), limit && i == upper);
	if(!limit)
		dp[pos][pre_digit][pre_cnt] = sum;
	return sum;
}

long long calc(int num) {
	int len = 0;
	while(num) {
		digit[len++] = num & 1;
		num >>= 1;
	}
	return count(len-1, 0, 0, true);
}

int main() {
	memset(dp, -1, sizeof dp);
	int nn;
	scanf("%d", &nn);
	for(int ii = 1; ii <= nn; ++ii) {
		int n;
		scanf("%d", &n);
		printf("Case %d: %I64d\n", ii, calc(n));
	}
	return 0;
}
