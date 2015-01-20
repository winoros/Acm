/*
 * =====================================================================================
 *
 *       Filename:  4389.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/10/9 18:48:44
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

int dp[10][82][82][82];
int digit[10];

int count(int pos, int digit_sum, int mod, int left, bool limit) {
	if(pos == -1)
		return digit_sum == mod && !left;
	if(digit_sum > mod)
		return 0;
	if(!limit && dp[pos][digit_sum][mod][left] != -1)
		return dp[pos][digit_sum][mod][left];
	int upper = limit ? digit[pos] : 9;
	int sum = 0;
	for(int i = 0; i <= upper; ++i)
		sum += count(pos-1, digit_sum + i, mod, (left*10 + i) %mod, limit && i == upper);
	if(!limit)
		dp[pos][digit_sum][mod][left] = sum;
	return sum;
}

int calc(int num) {
	int len = 0;
	while(num) {
		digit[len++] = num %10;
		num /= 10;
	}
	int ret = 0;
	for(int i = 1; i <= len*9; ++i)
		ret += count(len-1, 0, i, 0, true);
	return ret;
}

int main() {
	memset(dp, -1, sizeof dp);
	int nn;
	scanf("%d", &nn);
	for(int ii = 1; ii <= nn; ++ii) {
		int l, r;
		scanf("%d%d", &l, &r);
		printf("Case %d: %d\n", ii, calc(r) - calc(l-1));
	}
	return 0;
}
