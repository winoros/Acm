/*
 * =====================================================================================
 *
 *       Filename:  3252.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/10/2 23:27:46
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

int dp[32][32][32];
int bit[32];

int dfs(int pos, int cnt_zero, int cnt_one, bool not_first, bool limit) {
	if(pos == -1)
		return cnt_zero >= cnt_one;
	if(!limit && dp[pos][cnt_zero][cnt_one] != -1 && not_first)
		return dp[pos][cnt_zero][cnt_one];
	int upper = limit ? bit[pos] : 1;
	int sum = 0;
	for(int i = 0; i <= upper; ++i) {
		if(!not_first) {
			if(!i)
				sum += dfs(pos-1, 0, 0, false, limit && i == upper);
			else
				sum += dfs(pos-1, 0, 1, true, limit && i == upper);
		} else {
			if(!i)
				sum += dfs(pos-1, cnt_zero + 1, cnt_one, true, limit && i == upper);
			else 
				sum += dfs(pos-1, cnt_zero, cnt_one + 1, true, limit && i == upper);
		}
	}
	if(!limit && not_first)
		dp[pos][cnt_zero][cnt_one] = sum;
	return sum;
}

int calc(int num) {
	int len = 0;
	while(num) {
		bit[len++] = num %2;
		num /=2;
	}
	return dfs(len-1, 0, 0, false, true);
}

int main() {
	memset(dp, -1, sizeof dp);
	for(int st, en; scanf("%d%d", &st, &en) > 0; )
		printf("%d\n", calc(en) - calc(st-1));
	return 0;
}
