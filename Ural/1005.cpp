/*
 * =====================================================================================
 *
 *       Filename:  1005.cpp
 *
 *    Description:  solve the 1005th problem of Ural
 *
 *        Version:  1.0
 *        Created:  2014/8/22 0:19:35
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  winoros (), winoros@gmail.com
 *   Organization:  BUPT
 *
 * =====================================================================================
 */

#include <bits/stdc++.h>

using namespace std;

int w[25];
bool dp[1000001];

int main() {
	int n, sum = 0;;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &w[i]);
		sum += w[i];
	}
	int m = sum/2;
	dp[0] = true;
	for(int i = 0; i < n; i++) {
		for(int j = m; j >= w[i]; j--)
			if(dp[j-w[i]]) {
				dp[j] = true;
			}
	}
	int ans = 0;
	for(int i = m; i >= 0; i--) 
		if(dp[i]) {
			ans = i;
			break;
		}
	printf("%d\n", sum - 2*ans);
	return 0;
}
