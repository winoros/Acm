/*
 * =====================================================================================
 *
 *       Filename:  16E.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/11/28 23:01:48
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

double dp[1<<20], defeat[20][20];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			scanf("%lf", &defeat[i][j]);
	dp[(1<<n)-1] = 1;
	for(int s = (1<<n)-1; s > 0; --s) {
		int cnt = 0;
		for(int i = 0; i < n; ++i)
			if((s>>i) & 1)
				++cnt;
		for(int i = 0; i < n; ++i)
			if((s>>i) & 1) {
				for(int j = 0; j < n; ++j)
					if(((s>>j)&1) && j != i)
						dp[(1<<j)^s] += dp[s] * defeat[i][j] / ((cnt * (cnt-1) * 1.0) / 2);
			}
	}
	for(int i = 0; i < n; ++i)
		printf("%.11f%c", dp[1<<i], i == n-1 ? '\n' : ' ');
	return 0;
}
