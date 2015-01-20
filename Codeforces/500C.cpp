/*
 * =====================================================================================
 *
 *       Filename:  500C.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/12/30 22:59:11
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

bool used[510];
int stackk[510], w[510], nowpos[510];

int pop(int pos) {
	int ans = 0;
	int tmp = stackk[pos];
	for(int i = pos-1; i >= 0; --i) {
		ans += w[stackk[i]];
		stackk[i+1] = stackk[i];
		nowpos[stackk[i+1]] = i+1;
	}
	stackk[0] = tmp;
	nowpos[tmp] = 0;
	return ans;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i)
		scanf("%d", w+i);
	int ans = 0;
	for(int i = 0, tmp, len = 0; i < m; ++i) {
		scanf("%d", &tmp);
		--tmp;
		if(!used[tmp]) {
			stackk[len++] = tmp, used[tmp] = true;
			ans += pop(len-1);
		} else {
			ans += pop(nowpos[tmp]);
		}
	}
	printf("%d\n", ans);
	return 0;
}
