/*
 * =====================================================================================
 *
 *       Filename:  1019.cpp
 *
 *    Description:  solve the 1019th problem of Ural
 *
 *        Version:  1.0
 *        Created:  2014/8/31 1:42:42
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

int l[5001], r[5001], a[10010];
bool col[10010], op[5001];

int main() {
	int n;
	scanf("%d", &n);
	char str[2];
	int len = 0;
	a[len++] = 0, a[len++] = 1e9;
	memset(op, 0, sizeof op);
	for(int i = 0; i < n; i++) {
		scanf("%d%d%s", l+i, r+i, str);
		a[len++] = l[i], a[len++] = r[i];
		if(str[0] == 'b')
			op[i] = true;
	}
	sort(a, a+len);
	len = unique(a, a+len) - a;
	memset(col, 0, sizeof col);
	for(int i = 0; i < n; i++) {
		int ll = lower_bound(a, a+len, l[i]) - a;
		int rr = lower_bound(a, a+len, r[i]) - a;
		for(int j = ll; j < rr; j++)
			col[j] = op[i];
	}
	col[len-1] = true;
	int maxx = 0, ansL, ansR;
	for(int i = 0; i < len; i++) {
		if(!col[i]) {
			int ll = a[i];
			while(!col[i]) i++;
			int rr = a[i];
			if(maxx < rr - ll + 1)
				maxx = rr - ll + 1, ansL = ll, ansR = rr;
		}
	}
	printf("%d %d\n", ansL, ansR);
	return 0;
}
