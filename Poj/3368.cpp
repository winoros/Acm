/*
 * =====================================================================================
 *
 *       Filename:  3368.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/1/22 21:47:50
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

int a[100010];
int begin[100010], cnt;

void init(int n) {
	a[0] = INT_MAX;
	cnt = 0;
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		if(a[i] != a[i-1]) {
			begin[++cnt] = i;
		}
	}
	begin[++cnt] = n+1;
}

int st[100010][18], pre_log[100010];
void make_st() {
#ifndef PRE_LOG
	pre_log[0] = -1;
	for(int i = 1; i <= 100010; ++i) {
		pre_log[i] = pre_log[i-1];
		if((1<<(pre_log[i]+1)) == i)
			++pre_log[i];
	}
#define PRE_LOG
#endif
	for(int i = 1; i < cnt; ++i)
		st[i][0] = begin[i+1] - begin[i];
	for(int j = 1; j <= pre_log[cnt-1]; ++j)
		for(int i = 1; i + (1<<j) - 1 < cnt; ++i) 
			st[i][j] = max(st[i][j-1], st[i+(1<<(j-1))][j-1]);
}

int query(int l, int r) {
	int k = pre_log[r-l+1];
	return max(st[l][k], st[r-(1<<k)+1][k]);
}

void MAIN(int n, int q) {
	init(n);
	make_st();
	while(q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		if(a[l] == a[r])
			printf("%d\n", r-l+1);
		else {
			int ll = upper_bound(begin+1, begin+cnt, l) - begin - 1;
			int rr = upper_bound(begin+1, begin+cnt, r) - begin - 1;
			if(ll + 1 == rr)
				printf("%d\n", max(begin[ll+1] - l, r - begin[rr] + 1));
			else
				printf("%d\n",  max(max(begin[ll+1] - l, r - begin[rr] + 1), query(ll+1, rr-1)));
		}
	}
}

int main() {
	int n, q;
	while(scanf("%d", &n) && n) {
		scanf("%d", &q);
		MAIN(n, q);
	}
	return 0;
}
