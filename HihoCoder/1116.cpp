/*===============================================================
*   
*   FILE NAME:  1116.cpp
*   AUTHOR:     winoros
*   SHOOL:      BUPT
*   DATE:       02/04/2015 01:26:59
*   EMAIL:      winoros@gmail.com
*   Description:  
*
*
================================================================*/
#include <bits/stdc++.h>

using namespace std;

const int mod = 1e4+7;

int sum[100010<<1], p[100010<<1], lp[100010<<1], rp[100010<<1];

inline int getid(int l, int r) {
	return (l + r) | (l != r);
}

void push_up(int l, int r) {
	int idx = getid(l, r);
	int m = (l+r)>>1;
	int lidx =  getid(l, m), ridx = getid(m+1, r);
	sum[idx] = (sum[lidx] + sum[ridx] + lp[ridx]*rp[lidx]) %mod;
	lp[idx] = (lp[lidx] + p[lidx]*lp[ridx]) %mod;
	rp[idx] = (rp[ridx] + p[ridx]*rp[lidx]) %mod;
	p[idx] = p[lidx]*p[ridx] %mod;
}

int n;

void update(int pos, int val, int l = 1, int r = n) {
	if(l == pos && r == pos) {
		int idx = getid(l, r);
		sum[idx] = p[idx] = lp[idx] = rp[idx] = val;
		return ;
	}
	int m = (l+r)>>1;
	if(pos <= m)
		update(pos, val, l, m);
	else
		update(pos, val, m+1, r);
	push_up(l, r);
}

void MAIN() {
	int m;
	scanf("%d%d", &n, &m);
	for(int i = 0, pos, val; i < m; ++i) {
		scanf("%d%d", &pos, &val);
		update(pos, val);
		printf("%d\n", sum[getid(1, n)]);
	}
}

int main() {
	MAIN();
	return 0;
}
