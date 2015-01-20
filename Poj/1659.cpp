/*
 * =====================================================================================
 *
 *       Filename:  1659.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/12/19 16:12:55
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

bool atlas[15][15];
struct node {
	int cnt, idx;
	bool operator < (const node &b) const {
		return cnt < b.cnt;
	}
};

node a[14];

void solve() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i].cnt);
		a[i].idx = i;
	}
	memset(atlas, false, sizeof atlas);
	for(int i = n; i > 1; --i) {
		sort(a, a+i);
		if(a[i-1].cnt >= i) {
			puts("NO");
			return ;
		}
		for(int j = 1; j <= a[i-1].cnt; ++j) {
			if(a[i-1-j].cnt) {
				atlas[a[i-1].idx][a[i-1-j].idx] = atlas[a[i-1-j].idx][a[i-1].idx] = true, --a[i-1-j].cnt;
			}
			else {
				puts("NO");
				return ;
			}
		}
		a[i-1].cnt = 0;
	}
	puts("YES");
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			printf("%d%c", atlas[i][j], j == n-1 ? '\n' : ' ');
}

int main() {
	int nn;
	scanf("%d", &nn);
	while(nn--) {
		solve();
		if(nn)
			puts("");
	}
	return 0;
}
