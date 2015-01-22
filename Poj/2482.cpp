/*
 * =====================================================================================
 *
 *       Filename:  2482.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/1/22 13:56:06
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

struct line {
	long long x, y1, y2, val;
};

bool cmp(line a, line b) {
	return a.x < b.x ? true : (a.x == b.x ? a.val < b.val : false);
}

line l[10010<<1];

inline int getid(int l, int r) {
	return (l + r) | (l != r);
}

long long add[10010<<2], maxx[10010<<2];

void push_up(int l, int r) {
	int idx = getid(l, r);
	int m = (l+r) >> 1;
	int lidx = getid(l, m), ridx = getid(m+1, r);
	maxx[idx] = max(maxx[lidx], maxx[ridx]);
}

void push_down(int l, int r) {
	int idx = getid(l, r);
	if(add[idx]) {
		int m = (l+r) >> 1;
		int lidx = getid(l, m), ridx = getid(m+1, r);
		maxx[lidx] += add[idx], maxx[ridx] += add[idx];
		add[lidx] += add[idx], add[ridx] += add[idx];
		add[idx] = 0;
	}
}

void update(int _l, int _r, long long val, int l, int r) {
	int idx = getid(l, r);
	if(_l <= l && r <= _r) {
		add[idx] += val;
		maxx[idx] += val;
		return ;
	}
	push_down(l, r);
	int m = (l+r) >> 1;
	if(_l <= m)
		update(_l, _r, val, l, m);
	if(m < _r)
		update(_l, _r, val, m+1, r);
	push_up(l, r);
}

long long y[10010<<2];

void MAIN(int n, int w, int h) {
	for(int i = 0; i < n; ++i) {
		long long posx, posy, val;
		scanf("%I64d%I64d%I64d", &posx, &posy, &val);
		y[i] = posy, y[i+n] = posy+h-1;
		l[i].x = posx, l[i].y1 = posy,  l[i].y2 = posy+h-1, l[i].val = val;
		l[i+n].x = posx+w, l[i+n].y1 = posy, l[i+n].y2 = posy+h-1, l[i+n].val = -val;
	}
	n *= 2;
	sort(l, l+n, cmp);
	sort(y, y+n);
	int len = unique(y, y+n) - y;
	long long ans = 0;
	memset(add, 0, sizeof add);
	memset(maxx, 0, sizeof add);
	int idx = getid(1, len);
	for(int i = 0; i < n; ++i) {
		int y1 = lower_bound(y, y+len, l[i].y1) - y + 1;
		int y2 = lower_bound(y, y+len, l[i].y2) - y + 1;
		update(y1, y2, l[i].val, 1, len);
		ans = max(ans, maxx[idx]);
	}
	printf("%I64d\n", ans);
}

int main() {
	int n, w, h;
	while(scanf("%d%d%d", &n, &w, &h) > 0)
		MAIN(n, w, h);
	return 0;
}
