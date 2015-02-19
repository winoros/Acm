/*
 * =====================================================================================
 *
 *       Filename:  516a.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/2/19 19:15:08
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

char pre[20];
int ans[20<<2];

void MAIN() {
	int n;
	scanf("%d%s", &n, pre);
	int tot = 0;
	for(int i = 0; i < n; ++i) {
		switch(pre[i] - '0') {
			case 2:
				ans[tot++] = 2;
				break;
			case 3:
				ans[tot++] = 3;
				break;
			case 4:
				ans[tot] = 3, ans[tot+1] = 2, ans[tot+2] = 2;
				tot+=3;
				break;
			case 5:
				ans[tot++] = 5;
				break;
			case 6:
				ans[tot] = 5, ans[tot+1] = 3;
				tot+=2;
				break;
			case 7:
				ans[tot++] = 7;
				break;
			case 8:
				ans[tot] = 7, ans[tot+1] = 2, ans[tot+2] = 2, ans[tot+3] = 2;
				tot+=4;
				break;
			case 9:
				ans[tot] = 7, ans[tot+1] = 3, ans[tot+2] = 3, ans[tot+3] = 2;
				tot+=4;
			default :
				break;
		}
	}
	sort(ans, ans+tot, greater<int>());
	for(int i = 0; i < tot; ++i)
		printf("%d", ans[i]);
	puts("");
}

int main() {
	MAIN();
	return 0;
}
