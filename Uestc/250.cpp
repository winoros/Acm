/*===============================================================
*   
*   FILE NAME:  250.cpp
*   AUTHOR:     winoros
*   SHOOL:      BUPT
*   DATE:       10/02/2014 15:12:34
*   EMAIL:      winoros@gmail.com
*   Description:  
*
*
================================================================*/
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

long long dp[12][10];
int digit[12];

long long dfs(int bit, bool not_first, int pre, bool limit) {
	if(bit == -1)
		return not_first;
	if(!limit && dp[bit][pre] != -1 && not_first)
		return dp[bit][pre];
	int upper = limit ? digit[bit] : 9;
	long long sum = 0;
	for(int i = 0; i <= upper; ++i) {
		if(!not_first || abs(pre - i) >= 2)
			sum += dfs(bit-1, not_first || i, i, limit && i == upper);
	}
	if(!limit && not_first)
		dp[bit][pre] = sum;
	return sum;
}

long long calc(long long num) {
	int len = 0;
	digit[len] = 0;
	while(num) {
		digit[len++] = num %10;
		num /= 10;
	}
	return dfs(len-1, false, 0, true);
}

int main() {
	memset(dp, -1, sizeof dp);
	long long n, m;
	while(scanf("%lld%lld", &n, &m) > 0)
		printf("%lld\n", calc(m) - calc(n-1));
	return 0;
}
