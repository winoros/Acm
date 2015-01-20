/*
 * =====================================================================================
 *
 *       Filename:  3015.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/12/4 19:39:52
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

int a[50010];

int main() {
	int n, k;
	while(scanf("%d%d", &n, &k) && n) {
		for(int i = 0; i < n; ++i)
			scanf("%d", a+i);
		double ans = 0, c = k*1.0/n;
		for(int i = 0; i < n-k+1; ++i) {
			ans += (a[n-1-i] - a[i]) * c;
			c /= (n-1-i)*1.0 / (n-k-i);
		}
		printf("%.3f\n", ans);
	}
	return 0;
}

