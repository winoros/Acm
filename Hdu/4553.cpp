/*
 * =====================================================================================
 *
 *       Filename:  4553.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/10/27 18:52:30
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

#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1

int lsum[2][100010<<2], rsum[2][100010<<2], msum[2][100010<<2];
int cover[2][100010<<2];

inline void push_down(int rt, int m) {
	for(int i = 0; i < 2; ++i) {
		if(cover[i][rt] != -1) {
			cover[i][rt<<1] = cover[i][rt<<1|1] = cover[i][rt];
			lsum[i][rt<<1] = rsum[i][rt<<1] = msum[i][rt<<1] = cover[i][rt] ? 0 : m - (m>>1);
			lsum[i][rt<<1|1] = rsum[i][rt<<1|1] = msum[i][rt<<1|1] = cover[i][rt] ? 0 : (m>>1);
			cover[i][rt] = -1;
		}
	}
}

inline void push_up(int rt, int m) {
	for(int i = 0; i < 2; ++i) {
		lsum[i][rt] = lsum[i][rt<<1];
		rsum[i][rt] = rsum[i][rt<<1|1];
		if(lsum[i][rt] == m - (m>>1))
			lsum[i][rt] += lsum[i][rt<<1|1];
		if(rsum[i][rt] == m>>1)
			rsum[i][rt] += rsum[i][rt<<1];
		msum[i][rt] = max(rsum[i][rt<<1] + lsum[i][rt<<1|1], max(msum[i][rt<<1], msum[i][rt<<1|1]));
	}
}

void build(int l, int r, int rt) {
	for(int i = 0; i < 2; ++i)
		lsum[i][rt] = rsum[i][rt] = msum[i][rt] = r-l+1;
	cover[0][rt] = cover[1][rt] = -1;
	if(l == r)
		return ;
	int m = (l+r)>>1;
	build(lson);
	build(rson);
}

void update(int _l, int _r, int c, int l, int r, int rt) {
	if(_l <= l && r <= _r) {
		cover[0][rt] = c ? 1 : 0;
		lsum[0][rt] = rsum[0][rt] = msum[0][rt] = c ? 0 : r-l+1;
		if(c != 1) {
			cover[1][rt] = c;
			lsum[1][rt] = rsum[1][rt] = msum[1][rt] = c ? 0 : r-l+1;
		}
		return ;
	}
	push_down(rt, r-l+1);
	int m = (l+r)>>1;
	if(_l <= m) update(_l, _r, c, lson);
	if(m < _r) update(_l, _r, c, rson);
	push_up(rt, r-l+1);
}

int query(int c, int w, int l, int r, int rt) {
	if(l == r)
		return l;
	push_down(rt, r-l+1);
	int m = (l+r)>>1;
	if(msum[c-1][rt<<1] >= w)
		return query(c, w, lson);
	else if(rsum[c-1][rt<<1] + lsum[c-1][rt<<1|1] >= w)
		return m - rsum[c-1][rt<<1] + 1;
	else
		return query(c, w, rson);
}

int main() {
	int nn;
	int cnt = 1;
	scanf("%d", &nn);
	for(int ii = 1; ii <= nn; ++ii) {
		int n, m;
		scanf("%d%d", &n, &m);
		char str[10];
		build(1, n, 1);
		printf("Case %d:\n", ii);
		while(m--) {
			scanf("%s", str);
			if(str[0] == 'D') {
				int len;
				scanf("%d", &len);
				if(msum[0][1] >= len) {
					int pos = query(1, len, 1, n, 1);
					printf("%d,let's fly\n", pos);
					update(pos, pos+len-1, 1, 1, n, 1);
				} else
					puts("fly with yourself");
			} else if(str[0] == 'N') {
				int len;
				scanf("%d", &len);
				if(msum[0][1] >= len) {
					int pos = query(1, len, 1, n, 1);
					printf("%d,don't put my gezi\n", pos);
					update(pos, pos+len-1, 2, 1, n, 1);
				} else if(msum[1][1] >= len) {
					int pos = query(2, len, 1, n, 1);
					printf("%d,don't put my gezi\n", pos);
					update(pos, pos+len-1, 2, 1, n, 1);
				} else
					puts("wait for me");
			} else {
				int l, r;
				scanf("%d%d", &l, &r);
				puts("I am the hope of chinese chengxuyuan!!");
				update(l, r, 0, 1, n, 1);
			}
		}
	}
	return 0;
}
