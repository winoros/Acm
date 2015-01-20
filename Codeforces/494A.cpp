/*
 * =====================================================================================
 *
 *       Filename:  494A.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/12/14 1:32:26
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

char str[100010];
int ans[100010];

int main() {
	scanf("%s", str);
	int cnt = 0, tail = 0, len= strlen(str);
	for(int i = 0; i < len; ++i) {
		if(str[i] == '(')
			++cnt;
		else if(str[i] == ')') {
			if(cnt)
				--cnt;
			else {
				bool ok = false;
				for(int now = tail-1; now >= 0; --now)
					if(ans[now] > 1) {
						--ans[now];
						ok = true;
						break;
					}
				if(!ok) {
					--cnt;
					break;
				}
			}
		} else {
			if(!cnt) {
				--cnt;
				break;
			} else {
				ans[tail++] = cnt;
				cnt = 0;
			}
		}
	}
	if(!cnt)
		for(int i = 0; i < tail; ++i)
			printf("%d\n", ans[i]);
	else
		puts("-1");
	return 0;
}
