/*
 * =====================================================================================
 *
 *       Filename:  4366.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/10/25 17:50:00
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

double dp[1<<21];

int main() {
	int n;
	double prob[22];
	while(scanf("%d", &n) > 0) {
		for(int i = 0; i < n; ++i)
			scanf("%lf", &prob[i]);
		dp[(1<<n) - 1] = 0;
		for(int s = (1<<n) - 2; s >= 0; --s) {
			double sum = 0;
			dp[s] = 1;
			for(int i = 0; i < n; ++i)
				if(!((s>>i) & 1)) {
					sum += prob[i];
					dp[s] += prob[i]*dp[s|(1<<i)];
				}
			dp[s] /= sum;
		}
		printf("%.10f\n", dp[0]);
	}
	return 0;
}
