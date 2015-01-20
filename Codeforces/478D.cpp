/*
 * =====================================================================================
 *
 *       Filename:  478D.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/10/19 15:30:44
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

const int mod = 1e9+7;

int dp[200010];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int len;
    for(len = 1; len < 1000; ++len)
        if(len*(len+1)/2 <= n+m && (len+1)*(len+2)/2 > n+m)
            break;
    int maxx = len*(len+1)/2;
    memset(dp, 0, sizeof dp);
    dp[0] = 1;
    for(int i = 1; i <= len; ++i) {
        int upper = min(i*(i+1)/2, n);
        for(int j = upper; j >= i; --j)
            dp[j] = (dp[j] + dp[j-i]) %mod;
    }
    int ans = 0;
    int upper = min(maxx, n);
    for(int i = 0; i <= upper; ++i)
        if(maxx - i <= m)
            ans = (ans + dp[i]) %mod;
    printf("%d\n", ans);
    return 0;
}
