/*
 * =====================================================================================
 *
 *       Filename:  4507.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/10/3 15:36:03
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

const int mod = 1e9 + 7;

long long dp[20][7][7], num_cnt[20][7][7], num_sum[20][7][7], ten[20];
int digit[20];

pair<int, pair<int, int> >  dfs(int pos, int mod_1, int mod_2, bool limit) {
	//first sqr_sum, second.first num_sum second.second num_cnt
	if(pos == -1)
		return make_pair(0, make_pair(0, mod_1 && mod_2));
	if(!limit && dp[pos][mod_1][mod_2] != -1)
		return make_pair(dp[pos][mod_1][mod_2], make_pair(num_sum[pos][mod_1][mod_2], num_cnt[pos][mod_1][mod_2]));
	int upper = limit ? digit[pos] : 9;
	//aa = a*10^i (aa + b)^2 = aa^2 + b^2 + 2*aa*b
	long long ans1 = 0, ans2 = 0, ans3 = 0;
	long long aa;
	for(int i = 0; i <= upper; ++i) {
		if(i == 7)
			continue;
		pair<int, pair<int, int> > tmp = dfs(pos-1, (mod_1 + i) %7, (mod_2*10 + i) %7, limit && i == upper);
		aa = i*ten[pos] %mod;
		ans3 = (ans3 + tmp.second.second) %mod;
		ans2 = (ans2 + aa * tmp.second.second %mod + tmp.second.first) %mod;
		ans1 = (ans1 + aa * aa %mod *tmp.second.second %mod) %mod;
		ans1 = (ans1 + 2 * aa * tmp.second.first %mod) %mod;
		ans1 = (ans1 + tmp.first) %mod;
	}
	if(!limit) {
		dp[pos][mod_1][mod_2] = ans1;
		num_sum[pos][mod_1][mod_2] = ans2;
		num_cnt[pos][mod_1][mod_2] = ans3;
	}
	return make_pair(ans1, make_pair(ans2, ans3));
}

long long calc(long long num) {
	int len = 0;
	if(!num)
		len = 1, digit[0] = 0;
	while(num) {
		digit[len++] = num %10;
		num /= 10;
	}
	return dfs(len-1, 0, 0, true).first;
}

int main() {
	memset(dp, -1, sizeof dp);
	memset(num_cnt, 0, sizeof num_cnt);
	memset(num_sum, 0, sizeof num_sum);
	ten[0] = 1;
	for(int i =1; i < 20; i++)
		ten[i] = ten[i-1] * 10 %mod;
	int nn;
	for(scanf("%d", &nn); nn--; ) {
		long long l, r;
		scanf("%I64d%I64d", &l, &r);
		printf("%I64d\n", (calc(r) - calc(l-1) + mod) %mod);
	}
	return 0;
}
