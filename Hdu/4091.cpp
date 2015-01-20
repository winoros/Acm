/*
 * =====================================================================================
 *
 *       Filename:  4091.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/9/16 12:25:24
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

int main() {
	int nn;
	scanf("%d", &nn);
	for(int ii = 1; ii <= nn; ii++) {
		long long tot, s1, v1, s2, v2;
		scanf("%lld%lld%lld%lld%lld", &tot, &s1, &v1, &s2, &v2);
		if(s2 > s1) swap(s1, s2), swap(v1, v2);
		long long lcm = s1 / __gcd(s1, s2) * s2;
		long long ans;
		long long ttt = tot/lcm >= 1 ? tot/lcm-1 : 0;
		if(v1*s2 - v2*s1 >= 0)
			ans = ttt*(lcm/s1*v1);
		else 
			ans = ttt*(lcm/s2*v2);
		tot = tot - ttt*lcm;
		long long maxx = 0;
		for(int i = 0; i * s1 <= tot; i++)
			maxx = max(maxx, v1*i + (tot-i*s1)/s2 * v2);
		printf("Case #%d: %lld\n", ii, ans + maxx);
	}
	return 0;
}
