/*
 * =====================================================================================
 *
 *       Filename:  55D.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/10/3 22:40:26
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

long long dp[20][2530][50];
int digit[20];
int hash[2530];

void init_hash() {
	int now = 0;
	for(int i = 1; i <= 2520; i++)
		if(2520 %i == 0)
			hash[i] = now++;
}

const int mod = 2520;

long long dfs(int pos, int _mod, int pre_lcm, bool limit) {
	if(pos == -1)
		return _mod %pre_lcm == 0;
	if(!limit && dp[pos][_mod][hash[pre_lcm]] != -1)
		return dp[pos][_mod][hash[pre_lcm]];
	int upper = limit ? digit[pos] : 9;
	long long sum = 0;
	for(int i = 0; i <= upper; ++i) {
		if(!i)
			sum += dfs(pos-1, _mod*10 %2520, pre_lcm, limit && i == upper);
		else
			sum += dfs(pos-1, (_mod*10 + i) %2520, pre_lcm / __gcd(pre_lcm, i) * i, limit && i == upper);
	}
	if(!limit)
		dp[pos][_mod][hash[pre_lcm]] = sum;
	return sum;
}

long long calc(long long num) {
	int len = 0;
	while(num) {
		digit[len++] = num %10;
		num /= 10;
	}
	return dfs(len-1, 0, 1, true);
}

int main() {
	memset(dp, -1, sizeof dp);
	init_hash();
	int nn;
	for(scanf("%d", &nn); nn--; ) {
		long long l, r;
		scanf("%I64d%I64d", &l, &r);
		printf("%I64d\n", calc(r) - calc(l-1));
	}
	return 0;
}
