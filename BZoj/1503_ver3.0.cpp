/*
 * =====================================================================================
 *
 *       Filename:  1503_ver3.0.cpp
 *
 *    Description:  
 *
 *        Version:  3.0
 *        Created:  2015/2/7 0:23:03
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  winoros (Ding), winoros@gmail.com
 *   Organization:  BUPT
 *
 * =====================================================================================
 */
#include <bits/stdc++.h>

using namespace std;

inline int getid(int l, int r) {
	return (l + r) | (l != r);
}

int cnt[300010<<1];
bool zero[300010<<1];

void upd(int l, int r) {
	int idx = getid(l, r);
	int m = (l+r)>>1;
	int lidx = getid(l, m), ridx = getid(m+1, r);
	cnt[idx] = cnt[lidx] + cnt[ridx];
}

void relax(int l, int r) {
	int idx = getid(l, r);
	if(zero[idx]) {
		int m = (l+r)>>1;
		int lidx = getid(l, m), ridx = getid(m+1, r);
		cnt[lidx] = cnt[ridx] = 0;
		zero[lidx] = zero[ridx] = true;
		zero[idx] = false;
	}
}

void insert(int pos, int l = 1, int r = 300000) {
	if(l == r) {
		++cnt[getid(l, r)];
		return ;
	}
	relax(l, r);
	int m = (l+r)>>1;
	if(pos <= m)
		insert(pos, l, m);
	else
		insert(pos, m+1, r);
	upd(l, r);
}

int final_ans;

void reset(int _l, int _r, int l = 1, int r = 300000) {
	int idx = getid(l, r);
	if(_l <= l && r <= _r) {
		final_ans += cnt[idx];
		cnt[idx] = 0;
		zero[idx] = true;
		return ;
	}
	relax(l, r);
	int m = (l+r)>>1;
	if(_l <= m)
		reset(_l, _r, l, m);
	if(m < _r)
		reset(_l, _r, m+1, r);
	upd(l, r);
}

int query(int rk, int l = 1, int r = 300000) {
	if(l == r)
		return l;
	relax(l, r);
	int m = (l+r)>>1;
	int lidx = getid(l, m);
	if(rk <= cnt[lidx])
		return query(rk, l, m);
	else
		return query(rk-cnt[lidx], m+1, r);
}

void MAIN() {
	int n, minn;
	scanf("%d%d", &n, &minn);
	char str[3];
	int x, change = -100000, idx = getid(1, 300000);
	final_ans = 0;
	while(n--) {
		scanf("%s%d", str, &x);
		if(str[0] == 'I') {
			if(x >= minn)
				insert(x-change);
		} else if(str[0] == 'A')
			change += x;
		else if(str[0] == 'S') {
			change -= x;
			reset(1, minn-change-1);
		} else {
			x = cnt[idx] - x + 1;
			if(x <= 0)
				puts("-1");
			else
				printf("%d\n", query(x)+change);
		}
	}
	printf("%d\n", final_ans);
}

int main() {
	MAIN();
	return 0;
}
