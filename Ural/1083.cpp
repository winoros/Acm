/*
 * =====================================================================================
 *
 *       Filename:  1083.cpp
 *
 *    Description:  solve the 1083th problem of Ural
 *
 *        Version:  1.0
 *        Created:  2014/8/22 0:09:58
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  winoros (), winoros@gmail.com
 *   Organization:  BUPT
 *
 * =====================================================================================
 */

#include <bits/stdc++.h>

int main() {
	int n;
	char str[30];
	scanf("%d%s", &n, str);
	int k = 0;
	for(int i = 0; i < strlen(str); i++)
		if(str[i] == '!') k++;
	int ans = 1;
	while(n > 0) {
		ans *= n;
		n -= k;
	}
	printf("%d\n", ans);
	return 0;
}
