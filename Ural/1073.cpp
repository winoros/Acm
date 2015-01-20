/*===============================================================
*   
*   FILE NAME:  1073.cpp
*   AUTHOR:     winoros
*   SHOOL:      BUPT
*   DATE:       08/24/2014 19:27:22
*   EMAIL:      winoros@gmail.com
*   Description:solve the 1073th problem of Ural
*
*
================================================================*/
/* 数n最少可以由几个平方数相加得到 */
#include <bits/stdc++.h>

using namespace std;

int dp[60001];

int main() {
	int n;
	scanf("%d", &n);
	dp[0] = 0;
	for(int i = 1; i <= n; i++) {
		dp[i] = dp[i-1]+1;
		for(int j = 2; j*j <= i; j++)
			dp[i] = min(dp[i], dp[i-j*j]+1);
	}
	printf("%d\n", dp[n]);
	return 0;
}
