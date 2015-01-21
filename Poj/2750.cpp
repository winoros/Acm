/*
 * =====================================================================================
 *
 *       Filename:  2750.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/1/20 19:20:06
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

inline int getid(int l, int r) {
	return (l + r) | (l != r);
}

int n;
int lmax[100010<<1], rmax[100010<<1], lmin[100010<<1], rmin[100010<<1];
int maxx[100010<<1], minn[100010<<1], sum[100010<<1];

void push_up(int l, int r) {
	int idx = getid(l, r);
	int m = (l+r)>>1;
	int lidx = getid(l, m), ridx = getid(m+1, r);
	sum[idx] = sum[lidx] + sum[ridx];
	lmax[idx] = max(lmax[lidx], sum[lidx] + lmax[ridx]);
	rmax[idx] = max(rmax[ridx], sum[ridx] + rmax[lidx]);
	maxx[idx] = max(rmax[lidx] + lmax[ridx], max(maxx[lidx], maxx[ridx]));
	lmin[idx] = min(lmin[lidx], sum[lidx] + lmin[ridx]);
	rmin[idx] = min(rmin[ridx], sum[ridx] + rmin[lidx]);
	minn[idx] = min(rmin[lidx] + lmin[ridx], min(minn[lidx], minn[ridx]));
}

void build(int l = 1, int r = n) {
	int idx = getid(l, r);
	if(l == r) {
		scanf("%d", &sum[idx]);
		lmax[idx] = rmax[idx] = lmin[idx] = rmin[idx] = maxx[idx] = minn[idx] = sum[idx];
		return ;
	}
	int m = (l+r)>>1;
	build(l, m);
	build(m+1, r);
	push_up(l, r);
}

void update(int pos, int val, int l = 1, int r = n) {
	int idx = getid(l, r);
	if(l == pos && r == pos) {
		sum[idx] = lmax[idx] = lmin[idx] = maxx[idx] = minn[idx] = rmax[idx] = rmin[idx] = val;
		return ;
	}
	int m = (l+r) >> 1;
	if(pos <= m)
		update(pos, val, l, m);
	else
		update(pos, val, m+1, r);
	push_up(l, r);
}

void MAIN() {
	scanf("%d", &n);
	build();
	int m;
	scanf("%d", &m);
	int idx = getid(1, n);
	while(m--) {
		int pos, val;
		scanf("%d%d", &pos, &val);
		update(pos, val);
		if(sum[idx] == maxx[idx])
			printf("%d\n", sum[idx] - minn[idx]);
		else 
			printf("%d\n", max(maxx[idx], sum[idx] - minn[idx]));
	}
}

int main() {
	MAIN();
	return 0;
}
