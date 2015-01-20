/*
 * =====================================================================================
 *
 *       Filename:  2096.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/11/4 18:38:14
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

double dp[1010][1010];

int main() {
	int n, s;
	scanf("%d%d", &n, &s);
	memset(dp, 0, sizeof dp);
	for(int i = n; i >= 1; --i)
		for(int j = s; j >= 1; --j)
			if(i != n || j != s)
				dp[i][j] = ((n-i)*j*dp[i+1][j] + i*(s-j)*dp[i][j+1] + (n-i)*(s-j)*dp[i+1][j+1] + n*s) * 1.0 / (n*s - i*j);
	printf("%.4f\n", dp[1][1]+1);
	return 0;
}
