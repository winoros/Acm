/*
 * =====================================================================================
 *
 *       Filename:  1090.cpp
 *
 *    Description:  solve the 1090th problem of Ural 
 *
 *        Version:  1.0
 *        Created:  2014/8/27 23:38:46
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

int bit[10010];

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	int ans = 0, maxx = 0;
	for(int i = 0; i < k; i++) {
		int tmp, times = 0, cnt;
		memset(bit, 0, sizeof(int)*(n+5));
		for(int j = 0; j < n; j++) {
			scanf("%d", &tmp);
			cnt = 0;
			for(int kk = tmp-1; kk > 0; kk -= kk & (-kk))
				cnt += bit[kk];
			times += j-cnt;
			for(int kk = tmp; kk <= n; kk += kk & (-kk))
				bit[kk]++;
		}
		if(times > maxx) ans = i, maxx = times;
	}
	printf("%d\n", ans+1);
	return 0;
}
