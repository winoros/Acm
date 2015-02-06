/*
 * =====================================================================================
 *
 *       Filename:  2976.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/2/6 15:40:59
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

const double eps = 1e-8;

pair<int, int> a[1010];
double mid;

double sgn(double x) {
	return x < -eps ? -1 : x > eps;
}

bool cmp(pair<int, int> lhs, pair<int, int> rhs) {
	return sgn((lhs.first - mid*lhs.second) - (rhs.first - mid*rhs.second)) > 0;
}

void MAIN(int n, int k) {
	for(int i = 0; i < n; ++i)
		scanf("%d", &a[i].first);
	for(int i = 0; i < n; ++i)
		scanf("%d", &a[i].second);
	double l = 0, r = 1;
	while(l + eps < r) {
		mid = (l+r)/2;
		sort(a, a+n, cmp);
		double s = 0;
		for(int i = 0; i < n-k; ++i)
			s += a[i].first - mid*a[i].second;
		if(sgn(s) >= 0)
			l = mid;
		else
			r = mid;
	}
	printf("%d\n", (int)(l*100+0.5));
}

int main() {
	int n, m;
	while(scanf("%d%d", &n, &m) && n)
		MAIN(n, m);
}
