/*
 * =====================================================================================
 *
 *       Filename:  3667.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/10/27 21:26:19
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

int lsum[50010<<2], rsum[50010<<2], msum[50010<<2];
int cover[50010<<2];

inline void push_down(int rt, int m) {
	if(cover[rt] != -1) {
		cover[rt<<1] = cover[rt<<1|1] = cover[rt];
		msum[rt<<1] = lsum[rt<<1] = rsum[rt<<1] = cover[rt] ? 0 : m - (m>>1);
		msum[rt<<1|1] = rsum[rt<<1|1] = lsum[rt<<1|1] = cover[rt] ? 0 : (m>>1);
		cover[rt] = -1;
	}
}

inline void push_up(int rt, int m) {
	lsum[rt] = lsum[rt<<1];
	rsum[rt] = rsum[rt<<1|1];
	if(lsum[rt] == m - (m>>1))
		lsum[rt] += lsum[rt<<1|1];
	if(rsum[rt] == (m>>1))
		rsum[rt] += rsum[rt<<1];
	msum[rt] = max(lsum[rt<<1|1] + rsum[rt<<1], max(msum[rt<<1], msum[rt<<1|1]));
}

void build(int l, int r, int rt) {
	msum[rt] = lsum[rt] = rsum[rt] = r - l + 1;
	cover[rt] = -1;
	if(l == r)
		return ;
	int m = (l+r)>>1;
	build(lson);
	build(rson);
}

void update(int _l, int _r, int c, int l, int r, int rt) {
	if(_l <= l && r <= _r) {
		cover[rt] = c;
		lsum[rt] = rsum[rt] = msum[rt] = cover[rt] ? 0 : r-l+1;
		return ;
	}
	push_down(rt, r-l+1);
	int m = (l+r)>>1;
	if(_l <= m) update(_l, _r, c, lson);
	if(m < _r) update(_l, _r, c, rson);
	push_up(rt, r-l+1);
}

int query(int w, int l, int r, int rt) {
	if(l == r)
		return l;
	push_down(rt, r-l+1);
	int m = (l+r)>>1;
	if(msum[rt<<1] >= w)
		return query(w, lson);
	else if(rsum[rt<<1] + lsum[rt<<1|1] >= w)
		return m - rsum[rt<<1] + 1;
	else 
		return query(w, rson);
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	build(1, n, 1);
	while(m--) {
		int op;
		scanf("%d", &op);
		if(op == 1) {
			int len;
			scanf("%d", &len);
			if(msum[1] >= len) {
				int pos = query(len, 1, n, 1);
				printf("%d\n", pos);
				update(pos, pos+len-1, 1, 1, n, 1);
			} else 
				puts("0");
		} else {
			int st, len;
			scanf("%d%d", &st, &len);
			update(st, st+len-1, 0, 1, n, 1);
		}
	}
	return 0;
}
