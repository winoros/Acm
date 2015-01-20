/*
 * =====================================================================================
 *
 *       Filename:  3652.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/10/3 15:18:03
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

int dp[12][3][13];
int digit[12];

int dfs(int pos, int mod, int kind, int limit) {
	if(pos == -1)
		return !mod && kind == 2;
	if(!limit && dp[pos][kind][mod] != -1)
		return dp[pos][kind][mod];
	int upper = limit ? digit[pos] : 9;
	int sum = 0;
	for(int i = 0; i <= upper ; ++i) {
		int new_kind = kind;
		if(kind == 0 && i == 1)
			new_kind = 1;
		else if(kind == 1) {
			if(i == 3)
				new_kind = 2;
			else if(i != 1)
				new_kind = 0;
		}
		sum += dfs(pos-1, (mod*10 + i) %13, new_kind, limit && i == upper);
	}
	if(!limit)
		dp[pos][kind][mod] = sum;
	return sum;
}

int calc(int num) {
	int len = 0;
	while(num) {
		digit[len++] = num %10;
		num /= 10;
	}
	return dfs(len-1, 0, 0, true);
}

int main() {
	memset(dp, -1, sizeof dp);
	for(int n; scanf("%d", &n) > 0; ) 
		printf("%d\n", calc(n));
	return 0;
}
