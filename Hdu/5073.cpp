/*
 * =====================================================================================
 *
 *       Filename:  5073.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/10/22 16:12:30
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

const double eps = 1e-11;

int sgn(double x) {
	return x < -eps ? -1 : x > eps;
}

long long sum[50010], sqr_sum[50010];
int a[50010];

int main() {
	sum[0] = sqr_sum[0] = 0;
	int nn;
	scanf("%d", &nn);
	while(nn--) {
		int n, k;
		scanf("%d%d", &n, &k);
		for(int i = 1; i <= n; ++i)
			scanf("%d", &a[i]);
		sort(a+1, a+n+1);
		for(int i = 1; i <= n; ++i)
			sum[i] = sum[i-1] + a[i], sqr_sum[i] = sqr_sum[i-1] + (long long)a[i]*a[i];
		k = n-k;
		if(k == 0 || k == 1) {
			puts("0");
		} else {
			double ans = 1e100;
			for(int i = 1; i + k - 1 <= n; ++i) {
				double mid = (double)(sum[i+k-1] - sum[i-1])/k;
				double tmp = sqr_sum[i+k-1] - sqr_sum[i-1];
				tmp -= 2*(sum[i+k-1] - sum[i-1])*mid;
				tmp += k*mid*mid;
				if(sgn(tmp-ans) == -1)
					ans = tmp;
			}
			printf("%.11f\n", ans);
		}
	}
	return 0;
}
