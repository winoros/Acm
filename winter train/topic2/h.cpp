/*
 * =====================================================================================
 *
 *       Filename:  h.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/2/11 15:41:53
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

const int mod = 1e9+7;

int p[10000010];

void init(int n) {
	for(int i = 0; i <= n; ++i)
		p[i] = i;
}

int find(int x) {
	return p[x] == x ? x : p[x] = find(p[x]);
}

bool merge(int x, int y) {
	int px = find(x), py = find(y);
	if(px == py)
		return false;
	else {
		p[px] = py;
		return true;
	}
}

int fast_pow(int idx, int exp) {
	int ret = 1;
	for(; exp != 0; exp >>= 1) {
		if(exp & 1)
			ret = 1LL * ret * idx %mod;
		idx = 1LL * idx * idx %mod;
	}
	return ret;
}

void MAIN(int n, int m) {
	init(n);
	int cnt = 0;
	while(m--) {
		int x, y;
		scanf("%d%d", &x, &y);
		if(merge(x-1, y))
			++cnt;
	}
	printf("%d\n", fast_pow(26, n-cnt));
}

int main() {
	int n, m;
	while(scanf("%d%d", &n, &m) > 0)
		MAIN(n, m);
	return 0;
}
