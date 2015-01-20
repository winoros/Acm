/*===============================================================
*   
*   FILE NAME:  balnum.cpp
*   AUTHOR:     winoros
*   SHOOL:      BUPT
*   DATE:       10/04/2014 14:48:21
*   EMAIL:      winoros@gmail.com
*   Description:  
*
*
================================================================*/
#include <bits/stdc++.h>

using namespace std;

long long dp[22][60000];
int digit[20];
int three[11] = { 1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049 };

long long dfs(int pos, int state, bool not_first, bool limit) {
	if(pos == -1) {
		int tmp;
		for(int i = 0; i <= 9; ++i) {
			tmp = state %3;
			if(tmp == 2 - (i&1)) {
				return 0;
			}
			state /= 3;
		}
		return 1;
	}
	if(!limit && dp[pos][state] != -1)
		return dp[pos][state];
	int upper = limit ? digit[pos] : 9;
	long long sum = 0;
	for(int i = 0; i <= upper; ++i) {
		int tmp = state / three[i] %3;
		if(!tmp) 
			tmp++;
		else
			tmp = 3 - tmp;
		sum += dfs(pos-1, not_first || i ? state/three[i+1]*three[i+1] + state%three[i] + tmp*three[i] : 0, not_first || i, limit && i == upper);
	}
	if(!limit)
		dp[pos][state] = sum;
	return sum;
}

long long calc(long long num) {
	if(!num)
		return 1;
	int len = 0;
	while(num) {
		digit[len++] = num %10;
		num /= 10;
	}
	return dfs(len-1, 0, false, true);
}

int main() {
	std::ios::sync_with_stdio(false);
	memset(dp, -1, sizeof dp);
	int nn;
	for(scanf("%d", &nn); nn; --nn) {
		long long l, r;
		scanf("%lld%lld", &l, &r);
		printf("%lld\n", calc(r) - calc(l-1));
	}
	return 0;
}
