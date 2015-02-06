/*
 * =====================================================================================
 *
 *       Filename:  3440.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/2/6 14:34:20
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

const double pi = acos(-1.0);

void MAIN() {
	double n, m, a, d;
	scanf("%lf%lf%lf%lf", &n, &m, &a, &d);
	double r = d/2, ans[4];
	ans[0] = 4*(a-r)*(a-r) + (2*n+2*m-8)*(a-d)*(a-r) + (a-d)*(a-d)*(n-2)*(m-2);
	ans[2] = (d*d - pi*r*r)* (n-1)*(m-1);
	ans[3] = pi*r*r*(n-1)*(m-1);
	ans[1] = n*m*a*a - ans[0] - ans[2] - ans[3];
	for(int i = 0; i < 4; ++i)
		printf("Probability of covering %d %s = %.4f%%\n", i+1, i == 0 ? "tile " : "tiles", ans[i]*100/(n*m*a*a));
	puts("");
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		printf("Case %d:\n", i);
		MAIN();
	}
	return 0;
}
