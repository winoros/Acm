/*
 * =====================================================================================
 *
 *       Filename:  509b.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/1/31 20:07:06
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

int a[110];
int ans[110][110];
bool ok[110] = {false};

void MAIN() {
	int n, k;
	scanf("%d%d", &n, &k);
	int maxx = -1, minn = 1111;
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		maxx = max(maxx, a[i]);
		minn = min(minn, a[i]);
	}
	++minn;
	if(maxx - minn + 1 > k) {
		puts("NO");
	} else {
		puts("YES");
		for(int i = 0, j; i < n; ++i) {
			j = 0;
			for(; j < minn && j < a[i]; ++j)
				printf("%d ", 1);
			for(j = minn; j < a[i]; ++j)
				printf("%d ", j-minn+2);
			puts("");
		}
	}
}

int main() {
	MAIN();
	return 0;
}
