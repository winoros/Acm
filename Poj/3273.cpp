/*
 * =====================================================================================
 *
 *       Filename:  3273.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/1/21 18:16:59
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

int n, m;
int a[100100];

bool check(int ans) {
	int now = a[0], cnt = 1;
	for(int i = 1; i < n; ++i) {
		if(now + a[i] > ans)
			++cnt, now = a[i];
		else
			now += a[i];
	}
	return cnt <= m;
}

int bi(int l, int r) {
	int mid, ans;
	while(l <= r) {
		mid = (l+r)>>1;
		if(check(mid))
			ans = mid, r = mid-1;
		else
			l = mid+1;
	}
	return ans;
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i)
		scanf("%d", a+i);
	int sum = 0, maxx = -1;
	for(int i = 0; i < n; ++i)
		sum += a[i], maxx = max(maxx, a[i]);
	printf("%d\n", bi(maxx, sum));
	return 0;
}
