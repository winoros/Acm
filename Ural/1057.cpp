/*
 * =====================================================================================
 *
 *       Filename:  1057.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/10/6 23:30:00
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

int dp[32][21];
int digit[32], base, k;

int _count(int pos, int cnt, bool limit) {
	if(pos == -1)
		return cnt == k;
	if(cnt > k)
		return 0;
	if(!limit && dp[pos][cnt] != -1)
		return dp[pos][cnt];
	int upper = limit ? digit[pos] : 1;
	int sum = 0;
	for(int i = 0; i <= upper; ++i)
		sum += _count(pos-1, cnt + (i == 1), limit && i == upper);
	if(!limit)
		dp[pos][cnt] = sum;
	return sum;
}

inline int calc(int num) {
	int len = 0;
	while(num) {
		digit[len++] = num %base;
		num /= base;
	}
	for(int i = len-1; i >= 0; --i)
		if(digit[i] > 1)
			for(; i >= 0; --i)
				digit[i] = 1;
	return _count(len-1, 0, true);
}

int main() {
	memset(dp, -1, sizeof dp);
	int l, r;
	scanf("%d%d%d%d", &l, &r, &k, &base);
	printf("%d\n", calc(r) - calc(l-1));
	return 0;
}
