/*
 * =====================================================================================
 *
 *       Filename:  3264.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/1/22 19:43:48
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

int st_min[200010][18], st_max[200010][18], pre_log[200010];
int a[200010];

void make_st(int n) {
	pre_log[0] = -1;
	for(int i = 1; i <= n; ++i) {
		pre_log[i] = pre_log[i-1];
		if((1 << (pre_log[i]+1)) == i)
			++pre_log[i];
		st_min[i][0] = st_max[i][0] = a[i];
	}
	for(int j = 1; j <= pre_log[n]; ++j)
		for(int i = 1; i + (1<<j) - 1 <= n; ++i) {
			st_min[i][j] = min(st_min[i][j-1], st_min[i+(1<<(j-1))][j-1]);
			st_max[i][j] = max(st_max[i][j-1], st_max[i+(1<<(j-1))][j-1]);
		}
}

int query(int l, int r) {
	int k = pre_log[r-l+1];
	return max(st_max[l][k], st_max[r-(1<<k)+1][k]) - min(st_min[l][k], st_min[r-(1<<k)+1][k]);
}

void MAIN() {
	int n, q;
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	make_st(n);
	while(q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", query(l, r));
	}
}

int main() {
	MAIN();
	return 0;
}
