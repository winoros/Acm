/*
 * =====================================================================================
 *
 *       Filename:  3555.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/10/2 1:36:38
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

long long dp[35][3]; //o for normal number 1 for normal number which tail is 4 2 for special

int digit[35];

long long dfs(int pos, int kind, bool limit) {
	if(pos == -1)
		return kind == 2;
	if(!limit && dp[pos][kind] != -1)
		return dp[pos][kind];
	long long sum = 0;
	int upper = limit ? digit[pos] : 9;
	for(int i = 0; i <= upper; ++i) {
		int next_kind = kind;
		if(kind == 0 && i == 4)
			next_kind = 1;
		else if(kind == 1) {
			if(i == 9)
				next_kind = 2;
			else if(i != 4)
				next_kind = 0;
		}
		sum += dfs(pos-1, next_kind, limit && i == upper);
	}
	if(!limit)
		dp[pos][kind] = sum;
	return sum;
}

long long calc(long long num) {
	int len = 0;
	while(num) {
		digit[len++] = num%10;
		num/=10;
	}
	return dfs(len-1, 0, 1);
}

int main() {
	int nn;
	memset(dp, -1, sizeof dp);
	for(scanf("%d", &nn); nn--; ) {
		long long num;
		scanf("%I64d", &num);
		printf("%I64d\n", calc(num));
		int len = 0;
		while(num)
			num /= 10, len++;
		for(int i = len-1; i >= 0; --i) 
			printf("%I64d\t%I64d\t%I64d\n", dp[i][0], dp[i][1], dp[i][2]);
	}
}
