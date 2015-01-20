/*
 * =====================================================================================
 *
 *       Filename:  1010.cpp
 *
 *    Description:  solve the 1010th problem of Ural
 *
 *        Version:  1.0
 *        Created:  2014/8/25 21:30:22
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  winoros (), winoros@gmail.com
 *   Organization:  BUPT
 *
 * =====================================================================================
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ll ans = 2, max, tmp, tmpp;
	int n;
	scanf("%d", &n);
	scanf("%I64d%I64d", &tmp, &tmpp);
	max = llabs(tmp-tmpp);
	tmp = tmpp;
	n-=2;
	for(int i = 0; i < n; i++) {
		scanf("%I64d", &tmpp);
		if(max < llabs(tmp-tmpp))
			max = llabs(tmp-tmpp), ans = i+3;
		tmp = tmpp;
	}
	printf("%I64d %I64d\n", ans-1, ans);
	return 0;
}
